
"""
    comenzi:
        → adauga student: {nume_student}, {student_id}
        → sterge student: {student_id}
        → cauta student: {student_id}
        → modifica nume student: {student_id}, {nume_student_nou}

        → adauga disciplina: {nume}. {disciplina_id}, {profesor}
        → sterge disciplina: {disciplina_id}
        → cauta disciplina: {disciplina_id}
        → modifica nume disciplina: {disciplina_id}, {nume_disciplina_nou}
        → modifica profesor disciplina: {disciplina_id}, {nume_profesor_nou}

        → adauga nota student: {student_id}, {disciplina_id}, {nota}
        → afiseaza note student: {student_id}, {disciplina_id}

        → afiseaza statistici1 la disciplina: {disciplina_id}
        → afiseaza statistici2 la disciplina: {disciplina_id}

"""
import random

import re

from parsers import (stergeSauCautaStudentData, adaugaStudentData, cautaDisciplinaData, adaugaDisciplinaData, studentNoteData,
                     adaugaNotaData, modificaStudentData, modificaDisciplinaData)
from errors import SearchStudentError, ValidationError, AddStudentError, RemoveStudentError, RemoveDisciplineError, \
    AddDisciplineError, SearchDisciplineError, NoStatisticsError, NoGradesError, \
    InvalidGradeError, UserInputError


class ui:

    def __init__(self, serviceStudenti, serviceDiscipline, serviceNote):
        self.__serviceStudenti = serviceStudenti
        self.__serviceDiscipline = serviceDiscipline
        self.__serviceNote = serviceNote

    def ui_adauga_student(self, text):
        try:
            student_id, nume = adaugaStudentData(text)
            self.__serviceStudenti.add_student(student_id, nume)
            print("Studentul a fost adaugat cu succes")
        except (ValidationError, AddStudentError, UserInputError) as e:
            print(e)

    def ui_cauta_student(self, text):
        try:
            student_id = stergeSauCautaStudentData(text)
            student = self.__serviceStudenti.search_student(student_id)
            print(f"Studentul cautat este: {student.get_nume()}")
        except (SearchStudentError, ValidationError, UserInputError) as e:
            print(e)

    def ui_sterge_student(self, text):
        try:
            student_id = stergeSauCautaStudentData(text)
            self.__serviceStudenti.remove_student(student_id)
            print(f"Studentul cu id {student_id} a fost sters cu succes.")
        except (ValidationError, RemoveStudentError, UserInputError) as e:
            print(e)

    def ui_modifica_nume_student(self, text):
        try:
            student_id, nume = modificaStudentData(text)
            self.__serviceStudenti.modify_student_name(student_id, nume)
            print(f"Studentul cu id {student_id} s-a modificat cu succes.")
        except (ValidationError, SearchStudentError, UserInputError) as e:
            print(e)

    def ui_adauga_disciplina(self, text):
        try:
            name, id, professor = adaugaDisciplinaData(text)
            self.__serviceDiscipline.add_disciplina(id, name, professor)
            print(f"Disciplina {name} a fost adaugata cu succes.")
        except (ValidationError, AddDisciplineError, UserInputError) as e:
            print(e)

    def ui_cauta_disciplina(self, text):
        try:
            disciplina_id = cautaDisciplinaData(text)
            disciplinaCautata = self.__serviceDiscipline.search_disciplina(disciplina_id)
            print(f"Disciplina cautata este: {disciplinaCautata.get_nume()}")
        except (SearchDisciplineError, ValidationError, UserInputError) as e:
            print(e)

    def ui_sterge_disciplina(self, text):
        try:
            disciplina_id = cautaDisciplinaData(text)
            self.__serviceDiscipline.remove_disciplina(disciplina_id)
            print(f"Disciplina cu id {disciplina_id} a fost stearsa succes.")
        except (RemoveDisciplineError, ValidationError, UserInputError) as e:
            print(e)

    def ui_modifica_nume_disciplina(self, text):
        try:
            disciplina_id, nume_disciplina = modificaDisciplinaData(text)
            self.__serviceDiscipline.modify_disciplina_nume(disciplina_id, nume_disciplina)
            print(f"Disciplina cu id {disciplina_id} s-a modificat cu succes.")
        except (SearchDisciplineError, ValidationError, UserInputError) as e:
            print(e)

    def ui_modifica_nume_profesor_disciplna(self, text):
        try:
            disciplina_id, nume_profesor = modificaDisciplinaData(text)
            self.__serviceDiscipline.modify_disciplina_nume_profesor(disciplina_id, nume_profesor)
            print(f"Disciplina cu id {disciplina_id} s-a modificat cu succes.")
        except (SearchDisciplineError, ValidationError, UserInputError) as e:
            print(e)

    def ui_afiseaza_studenti(self):
        lista_studenti = self.__serviceStudenti.get_all_students()
        if lista_studenti:
            for student in lista_studenti:
                print(student)
        else:
            print("Nu exista nici un student")

    def ui_afiseaza_discipline(self):
        lista_discipline = self.__serviceDiscipline.get_all_disciplines()
        if lista_discipline:
            for disciplina in lista_discipline:
                print(disciplina)
        else:
            print("Nu exista nici o disciplina")

    def ui_adauga_nota_student(self, text):
        try:
            student_id, disciplina_id, nota = adaugaNotaData(text)
            self.__serviceNote.add_nota(student_id, disciplina_id, nota)
            print("Nota a fost adaugata cu succes.")
        except (ValidationError, InvalidGradeError, SearchStudentError, SearchDisciplineError, UserInputError) as e:
            print(e)

    def ui_afiseaza_note_student(self, text):
        try:
            student_id, disciplina_id = studentNoteData(text)
            noteStudentLaDisciplina = self.__serviceNote.get_note_student(student_id, disciplina_id)
            for nota in noteStudentLaDisciplina:
                print(nota)
        except (ValidationError, NoGradesError, SearchStudentError, SearchDisciplineError, UserInputError) as e:
            print(e)

    def ui_afiseaza_statistici1(self, text):
        try:
            disciplina_id = cautaDisciplinaData(text)
            disciplinaCautata = self.__serviceDiscipline.search_disciplina(disciplina_id)
            try:
                noteStudenti = self.__serviceNote.get_studenti_si_note_alfabetic(disciplina_id)
                print(f"Lista notelor studentilor la disciplina {disciplinaCautata} ordonate alfabetic dupa numele studentilor este:")
                for nume_student, nota in noteStudenti:
                    print(f"{nume_student}, Nota: {nota}")
            except NoStatisticsError as e:
                print(e)
        except (SearchDisciplineError, SearchStudentError, ValidationError, UserInputError) as e:
            print(e)


    def ui_afiseaza_statistici2(self, text):
        try:
            disciplina_id = cautaDisciplinaData(text)
            disciplinaCautata = self.__serviceDiscipline.search_disciplina(disciplina_id)
            try:
                noteStudenti = self.__serviceNote.get_studenti_si_note_dupaNota(disciplina_id)
                print(f"Lista notelor studentilor la disciplina {disciplinaCautata} ordonate dupa nota este:")
                for nume_student, nota in noteStudenti:
                    print(f"{nume_student}, Nota: {nota}")
            except NoStatisticsError as e:
                print(e)
        except (SearchDisciplineError, SearchStudentError, ValidationError, UserInputError) as e:
            print(e)

    def ui_afiseaza_statistici3(self):
        try:
            statistici = self.__serviceNote.get_statistici()
            print("Primii 20% din studenti ordonat dupa media notelor la toate disciplinele sunt:")
            for nume_student, nota in statistici:
                print(f"{nume_student}, Nota: {nota}")
        except NoStatisticsError as e:
            print(e)

    def ui_afiseaza_statistici4(self):
        try:
            statistici = self.__serviceNote.get_statistici_invers()
            print("Primele 20% din discipline ordonate dupa media notelor la acea disciplina a tututor studentiilor:")
            for nume_disciplina, nota in statistici:
                print(f"{nume_disciplina}, Nota: {nota}")
        except NoStatisticsError as e:
            print(e)

    def ui_genereaza_studenti(self):
        studenti_range = 20
        random_number = random.randint(1, studenti_range)
        for i in range(studenti_range):
            try:
                self.__serviceStudenti.generate_random_students()
            except AddStudentError:
                print("s-a generat acelasi id lol")
                continue

    def ui_genereaza_discipline(self):
        discipline_range = 10
        random_number = random.randint(1, discipline_range)
        for i in range(discipline_range):
            try:
                self.__serviceDiscipline.generate_random_disciplines()
            except AddDisciplineError:
                print("s-a generat acelasi id lol")
                continue


    def run(self):
        RUNNING = True
        while RUNNING:
            comanda = input(">>>").lower()
            commandSplit = re.split(r'[:,]', comanda)
            match commandSplit[0]:
                case "afiseaza studenti":
                    self.ui_afiseaza_studenti()

                case "afiseaza discipline":
                    self.ui_afiseaza_discipline()

                case "afiseaza note student":
                    self.ui_afiseaza_note_student(commandSplit)

                case "adauga student":
                    self.ui_adauga_student(commandSplit)

                case "adauga nota student":
                    self.ui_adauga_nota_student(commandSplit)

                case "sterge student":
                    self.ui_sterge_student(commandSplit)

                case "cauta student":
                    self.ui_cauta_student(commandSplit)

                case "modifica nume student":
                    self.ui_modifica_nume_student(commandSplit)

                case "adauga disciplina":
                    self.ui_adauga_disciplina(commandSplit)

                case "sterge disciplina":
                    self.ui_sterge_disciplina(commandSplit)

                case "cauta disciplina":
                    self.ui_cauta_disciplina(commandSplit)

                case "modifica nume disciplina":
                    self.ui_modifica_nume_disciplina(commandSplit)

                case "modifica profesor disciplina":
                    self.ui_modifica_nume_profesor_disciplna(commandSplit)

                case "afiseaza statistici1 la disciplina":
                    self.ui_afiseaza_statistici1(commandSplit)

                case "afiseaza statistici2 la disciplina":
                    self.ui_afiseaza_statistici2(commandSplit)

                case "afiseaza statistici3":
                    self.ui_afiseaza_statistici3()

                case "afiseaza statistici4":
                    self.ui_afiseaza_statistici4()

                case "genereaza studenti":
                    self.ui_genereaza_studenti()

                case "genereaza discipline":
                    self.ui_genereaza_discipline()

                case "exit":
                    RUNNING = False
                    print("Exiting...")
