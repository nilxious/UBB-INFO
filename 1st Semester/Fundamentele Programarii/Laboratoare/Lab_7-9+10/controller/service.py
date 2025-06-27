from domain.disciplina import Disciplina
from domain.student import Student
from domain.nota import Nota
from validare.validare_disciplina import ValidatorDisciplina
from validare.validare_student import ValidatorStudent
from errors import InvalidGradeError, NoGradesError, NoStatisticsError

class Service(object):
    def __init__(self, facultate):
        self.facultate = facultate

    def add_student(self, id: int, nume: str):
        """
        Metoda care creeaza un student cu parametrii id si nume, dupa care il adauga in baza de date (Facultatea)

        :param id: int, trebuind sa aiba exact 5 cifre
        :param nume: string, numele studentului
        :return: -, daca datele sunt valide
        :raises: ValidationError, daca id-ul studentului nu are exact 5 cifre sau este negativ, sau daca numele acestuia are caractere
        diferite de literele alfabetului si de caracterul "-"
        """
        studentNou = Student(id, nume)
        ValidatorStudent().valideaza(studentNou)

        self.facultate.adauga_student(studentNou)

    def remove_student(self, id: int):
        """
        Metoda care sterge un student din baza de date (Facultatea), daca acesta exista
        :param id: int, id-ul studentului
        :return: -, daca datele sunt valide
        :raises: ValidationError, daca id-ul studentului nu are exact 5 cifre sau este negativ, sau daca numele acestuia are caractere
        diferite de literele alfabetului si de caracterul "-"
        """
        ValidatorStudent().valideaza(Student(id, "Lorem ipsum"))

        self.facultate.sterge_student(id)

    def remove_disciplina(self, id: int):
        """
        Metoda care sterge o disciplina din baza de date (Facultatea), daca aceasta exista
        :param id: int, id-ul disciplinei
        :return: -, daca datele sunt valide
        :raises: ValidationError, daca id-ul disciplinei este negativ
        """
        ValidatorDisciplina().valideaza(Disciplina(id, "Lorem ipsum", "Lorem ipsum"))

        self.facultate.sterge_disciplina(id)

    def search_student(self, id: int):
        """
        Metoda care cauta un student din baza de date (Facultatea) dupa id, iar daca exista il returneaza
        :param id: int, id-ul studentului
        :return: studentul cautat, daca datele sunt valide si stundetul cu id-ul id exista
        :raises: ValidationError, daca id-ul studentului nu are exact 5 cifre sau este negativ, sau daca numele acestuia are caractere
        diferite de literele alfabetului si de caracterul "-"
        """
        ValidatorStudent().valideaza(Student(id, "Lorem ipsum"))

        return self.facultate.cauta_student(id)

    def add_disciplina(self, id: int, nume: str, profesor: str):
        """
        Metoda care creeaza si adauga o disciplina cu parametrii id, nume, profesor in baza de date (Facultatea)
        in cazul in care aceasta nu exista deja
        :param id: int, id-ul disciplinei
        :param nume: string, numele materiei
        :param profesor: string, numele profesorului
        :raises ValidationError, daca id-ul disciplinei este negativ
        :return: -, daca datele sunt valide
        """
        disciplinaNoua = Disciplina(id, nume, profesor)

        ValidatorDisciplina().valideaza(disciplinaNoua)

        self.facultate.adauga_disciplina(disciplinaNoua)

    def search_disciplina(self, disciplina_id: int):
        """
        Metoda care cauta o disciplina din baza de date (Facultatea) dupa id, iar daca exista o returneaza
        :param disciplina_id: int, id-ul disciplinei
        :return: disciplina cautata, daca datele sunt valide si disciplina cu id-ul disciplina_id exista
        :raises: ValidationError, daca id-ul disciplinei este negativ
        """
        ValidatorDisciplina().valideaza(Disciplina(disciplina_id, "Lorem ipsum", "Lorem ipsum"))

        return self.facultate.cauta_disciplina(disciplina_id)

    def modify_student_name(self, student_id: int, nume: str):
        """
        Metoda care schimba numele unui student din baza de date (Facultatea) dupa id, daca exista
        :param student_id: int, id-ul studentului
        :param nume: string, noul nume al studentului
        :return: -, daca datele sunt valide
        :raises: ValidationError, daca id-ul studentului nu are exact 5 cifre sau este negativ, sau daca numele acestuia are caractere
        diferite de literele alfabetului si de caracterul "-"
        """
        ValidatorStudent().valideaza(Student(student_id, nume))

        self.facultate.modifica_nume_student(student_id, nume)

    def add_nota(self, student_id: int, disciplina_id: int, value: float):
        """
        Metoda care creeaza o nota a unui student la o disciplina iar apoi o adauga in baza de date (Facultatea)
        :param student_id: int, id-ul studentului
        :param disciplina_id: int, id-ul disciplinei
        :param value: float, nota studentului la disciplina
        :return: -, daca datele sunt valide
        :raises: ValidationError, daca id-ul disciplinei este negativ si/sau daca id-ul studentului nu are exact 5 cifre sau este negativ,
        sau daca numele acestuia are caractere diferite de literele alfabetului si de caracterul "-"
                 InvalidGradeError, daca nota nu este in intervalul [1, 10]
        """
        nota = Nota(student_id, disciplina_id, value)

        ValidatorStudent().valideaza(Student(student_id, "Lorem ipsum"))

        ValidatorDisciplina().valideaza(Disciplina(disciplina_id, "Lorem ipsum", "Lorem ipsum"))

        if not 1 <= value <= 10:
             raise InvalidGradeError("Nota trebuie sa ia valori intre 1 si 10")

        self.facultate.adauga_nota(nota)

    def get_note_student(self, student_id: int, disciplina_id: int):
        """
        Metoda care creeaza o lista cu notele unui student cu id-ul student_id la o disciplina cu id-ul disciplina_id, iar apoi o returneaza
        :param student_id: int, id-ul studentului
        :param disciplina_id: int, id-ul disciplinei
        :return: lista cu notele unui student la o disciplina, daca datele sunt valide
        :raises: ValidationError, daca id-ul disciplinei este negativ si/sau daca id-ul studentului nu are exact 5 cifre sau este negativ
        """
        ValidatorStudent().valideaza(Student(student_id, "Lorem ipsum"))

        ValidatorDisciplina().valideaza(Disciplina(disciplina_id, "Lorem ipsum", "Lorem ipsum"))

        return self.facultate.ia_note_student(student_id, disciplina_id)

    def get_nume_tuplu(self, tuplu: tuple):
        """
        Metoda care ia numele studentului dintr-un tuplu
        :param tuplu: tuple, ce contine numele si nota studentului la o disciplina (string, float)
        :return: string, numele studentului
        """
        return tuplu[0]

    def get_nota_tuplu(self, tuplu: tuple):
        """
        Metoda care ia nota studentului dintr-un tuplu
        :param tuplu: tuple, ce contine numele si nota studentului la o disciplina (string, float)
        :return: float, nota studentului
        """
        return tuplu[1]

    def get_studenti_si_note_alfabetic(self, disciplina_id: int):
        """
        Metoda care creeaza si returneaza o lista cu numele si noteles tudentilor la o disciplina, ordonata alfabetic dupa nume
        :param disciplina_id: id, id-ul disciplinei
        :return: lista de studenți și notele lor la o disciplină dată, ordonat alfabetic după nume, daca datele sunt valide sau nu sunt erori
        :raises: ValidationError, daca id-ul disciplinei este negativ
                 NoStatisticError, daca nici un student nu are o nota la disciplina cu id-ul disciplina_id
        """
        Statistici1 = []

        ValidatorDisciplina().valideaza(Disciplina(disciplina_id, "Lorem ipsum", "Lorem ipsum"))

        for student in self.facultate.studenti:
            try:
                note = self.get_note_student(student.get_id(), disciplina_id)
                for nota in note:
                    Statistici1.append((student.get_nume(), nota.get_value()))
            except NoGradesError:
                continue

        Statistici1.sort(key=self.get_nume_tuplu)

        if Statistici1:
            return Statistici1
        else:
            raise NoStatisticsError("Nu exista nici un student cu o nota la aceasta disciplina")

    def get_studenti_si_note_dupaNota(self, disciplina_id: int):
        """
        Metoda care creeaza si returneaza o lista de note cu notele studentilor la o disciplina, ordonata crescator dupa note
        :param disciplina_id: id, id-ul disciplinei
        :return: lista de studenți și notele lor la o disciplină dată, ordonat după notă, daca datele sunt valide sau nu sunt erori
        :raises: ValidationError, daca id-ul disciplinei este negativ
                 NoStatisticError, daca nici un student nu are o nota la disciplina cu id-ul disciplina_id
        """
        Statistici2 = []

        ValidatorDisciplina().valideaza(Disciplina(disciplina_id, "Lorem ipsum", "Lorem ipsum"))

        for student in self.facultate.studenti:
            try:
                note = self.get_note_student(student.get_id(), disciplina_id)
                for nota in note:
                    Statistici2.append((student.get_nume(), nota.get_value()))
            except NoGradesError:
                continue

        Statistici2.sort(key=self.get_nota_tuplu)

        if Statistici2:
            return Statistici2
        else:
            raise NoStatisticsError("Nu exista nici un student cu o nota la aceasta disciplina")

    def modify_disciplina_nume(self, disciplina_id: int, nume_disciplina: str):
        """
        Metoda care schimba numele unei discipline din baza de date (Facultatea) dupa id, daca exista
        :param disciplina_id: int, id-ul disciplinei
        :param nume_disciplina: string, numele disciplinei cu id-ul disciplina_id
        :return: -, daca datele sunt valide
        :raises: ValidationError, daca id-ul disciplinei este negativ
        """
        ValidatorDisciplina().valideaza(Disciplina(disciplina_id, nume_disciplina, "Lorem ipsum"))

        self.facultate.modifica_nume_disciplina(disciplina_id, nume_disciplina)

    def modify_disciplina_nume_profesor(self, disciplina_id: int, nume_profesor: str):
        """
        Metoda care schimba numele profesorului unei discipline din baza de date (Facultatea) dupa id, daca exista
        :param disciplina_id:  int, id-ul disciplinei
        :param nume_profesor: string, numele profesorului al disciplinei cu id-ul disciplina_id
        :return: -, daca datele sunt valide
        :raises: ValidationError, daca id-ul disciplinei este negativ
        """
        ValidatorDisciplina().valideaza(Disciplina(disciplina_id, "Lorem ipsum", nume_profesor))

        self.facultate.modifica_nume_profesor_disciplina(disciplina_id, nume_profesor)
