import re
from controller.service import Service
from repository.repoDiscipline import RepoDiscipline
from repository.repoStudenti import RepoStudenti
from repository.repoNote import RepoNote
from controller.serviceDiscipline import ServiceDiscipline
from controller.serviceStudenti import ServiceStudenti
from controller.serviceNote import ServiceNote

"""
    comenzi
        adauga student: {nume}, {student_id}
        sterge student: {student_id}
        cauta student: {student_id}

        adauga disciplina: {nume}. {disciplina_id}, {profesor}
        sterge disciplina: {disciplina_id}
        cauta disciplina: {disciplina_id}
        
        adauga nota student: {student_id}, {disciplina_id}, {nota}
        afiseaza note student: {student_id}, {disciplina_id}
        
        afiseaza statistici1 la disciplina: {disciplina_id}
        afiseaza statistici2 la disciplina: {disciplina_id}
"""

def removeStudentData(text: list)-> int:
    id = int(text[1][1:])
    return id

def addStudentData(text: list)-> tuple:
    nume = text[1][1:]
    numeSplit = re.split(r'[ -]', nume)
    for i in range(len(numeSplit)):
        numeSplit[i] = numeSplit[i].capitalize()
    nume = ' '.join(numeSplit)
    id = int(text[2][1:])
    return id, nume

def cautaStudentData(text: list)-> int:
    student_id = int(text[1][1:])
    return student_id

def addDisciplinaData(text: list)-> tuple:
    disciplina = text[1][1:]
    id = int(text[2][1:])
    nume = text[3][1:]
    numeSplit = re.split(r'[ -]', nume)
    for i in range(len(numeSplit)):
        numeSplit[i] = numeSplit[i].capitalize()
    nume = ' '.join(numeSplit)
    return disciplina, id, nume

def addNotaData(text: list)-> tuple:
    student_id = int(text[1][1:])
    disciplina_id = int(text[2][1:])
    nota = float(text[3][1:])
    return student_id, disciplina_id, nota

def studentNoteData(text: list)-> tuple:
    student_id = int(text[1][1:])
    disciplina_id = int(text[2][1:])
    return student_id, disciplina_id

def cautaDisciplinaData(text: list)-> int:
    disciplina_id = int(text[1][1:])
    return disciplina_id

def formatAfiseazaStudenti(text: list)-> bool:
    if text[0] == "afiseaza studenti":
        return True

def formatAfiseazaNoteStudent(text: list)-> bool:
    if text[0] == "afiseaza note student":
        return True

def formatAfiseazaDiscipline(text: list)-> bool:
    if text[0] == "afiseaza discipline":
        return True

def formatAdaugaStudent(text: list)-> bool:
    if text[0] == "adauga student":
        return True

def formatStergeStudent(text: list)-> bool:
    if text[0] == "sterge student":
        return True

def formatCautaStudent(text: list)-> bool:
    if text[0] == "cauta student":
        return True

def formatModificaStudent(text: list)-> bool:
    pass

def formatAdaugaDisciplina(text: list)-> bool:
    if text[0] == "adauga disciplina":
        return True

def formatStergeDisciplina(text: list)-> bool:
    if text[0] == "sterge disciplina":
        return True

def formatCautaDisciplina(text: list)-> bool:
    if text[0] == "cauta disciplina":
        return True

def formatModificaDisciplina(text: list) -> bool:
    if text[0] == "modifica disciplina":
        return True

def formatAdaugaNota(text: list)-> bool:
    if text[0] == "adauga nota student":
        return True

def formatAfiseazaStastici1(text: list)-> bool:
    if text[0] == "afiseaza statistici1 la disciplina":
        return True

def formatAfiseazaStatistici2(text: list)-> bool:
    if text[0] == "afiseaza statistici2 la disciplina":
        return True

def formatExit(text: list)-> bool:
    if text[0] == "exit":
        return True

def commandChecker(command: str):

    pass

def start():
    Studenti = RepoStudenti()
    studentiService = ServiceStudenti(Studenti)
    studentiService.add_student(12345, "Homorozan Catalin Stefan")
    studentiService.add_student(12346, "Bogdan Ioan")
    studentiService.add_student(12333, "Avram Ioan")
    studentiService.add_student(12445, "Zendaya Xenovia")

    Discipline = RepoDiscipline()
    disciplineService = ServiceDiscipline(Discipline)
    disciplineService.add_disciplina(1, "Matematica", "Profesor Mate")
    disciplineService.add_disciplina(3, "Engleza", "Profesor Mate")
    disciplineService.add_disciplina(2, "Romana", "Profesor Romana")

    Note = RepoNote()
    noteService = ServiceNote(Note, Studenti, Discipline)
    noteService.add_nota(12345, 2, 10)
    noteService.add_nota(12346, 2, 8)
    noteService.add_nota(12445, 2, 1)
    noteService.add_nota(12345, 1, 2)
    noteService.add_nota(12345, 1, 4)
    noteService.add_nota(12345, 1, 2)
    noteService.add_nota(12346, 1, 5)
    noteService.add_nota(12346, 1, 3)
    noteService.add_nota(12333,1, 8)
    noteService.add_nota(12445, 1, 1)
    RUNNING = True
    while RUNNING:
        command = input(">>>").lower()
        commandSplit = re.split(r'[:,]', command)

        if formatAfiseazaStudenti(commandSplit):
            for student in Studenti.studenti:
                print(student)

        elif formatAfiseazaDiscipline(commandSplit):
            for disciplina in Discipline.__discipline:
                print(disciplina)

        elif formatAfiseazaNoteStudent(commandSplit):
            student_id, disciplina_id = studentNoteData(commandSplit)
            studentCautat = studentiService.search_student(student_id)

        elif formatAfiseazaStastici1(commandSplit):
            disciplina_id = cautaDisciplinaData(commandSplit)
            disciplinaCautata = disciplineService.search_disciplina(disciplina_id)
            studenti_si_note = noteService.get_studenti_si_note_alfabetic(disciplina_id)
            print(f"Notele la disciplina {disciplinaCautata.get_nume()} ordonate alfabetic dupa nume sunt:")
            for tuplu in studenti_si_note:
                nume_student, nota = tuplu
                print(f"{nume_student}, Nota:{nota}")

        elif formatAfiseazaStatistici2(commandSplit):
            disciplina_id = cautaDisciplinaData(commandSplit)
            disciplinaCautata = disciplineService.search_disciplina(disciplina_id)
            studenti_si_note = noteService.get_studenti_si_note_dupaNota(disciplina_id)
            print(f"Notele la disciplina {disciplinaCautata.get_nume()} ordonate dupa nota:")
            for tuplu in studenti_si_note:
                nume_student, nota = tuplu
                print(f"{nume_student}, Nota:{nota}")

        elif formatAdaugaStudent(commandSplit):
            id, nume = addStudentData(commandSplit)
            studentiService.add_student(id, nume)

        elif formatAdaugaNota(commandSplit):
            student_id, disciplina_id, nota = addNotaData(commandSplit)
            noteService.add_nota(student_id, disciplina_id, nota)

        elif formatStergeStudent(commandSplit):
            id = removeStudentData(commandSplit)
            studentiService.remove_student(id)

        elif formatAdaugaDisciplina(commandSplit):
            nume, id, profesor = addDisciplinaData(commandSplit)
            disciplineService.add_disciplina(id, nume, profesor)

        elif formatCautaStudent(commandSplit):
            student_id = cautaStudentData(commandSplit)
            studentCautat = studentiService.search_student(student_id)
            print("Studentul cautat este:", studentCautat.get_nume())

        elif formatCautaDisciplina(commandSplit):
            disciplina_id = cautaDisciplinaData(commandSplit)
            disciplinaCautata = disciplineService.search_disciplina(disciplina_id)
            print("Disciplina cautata este:", disciplinaCautata.get_nume())

        elif formatStergeDisciplina(commandSplit):
            disciplina_id = cautaDisciplinaData(commandSplit)
            disciplineService.remove_disciplina(disciplina_id)

        elif formatExit(commandSplit):
            RNUNING = False
            print("Exiting...")
            break
