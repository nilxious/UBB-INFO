from errors import (AddStudentError, SearchStudentError, RemoveStudentError)

class RepoStudenti(object):
    def __init__(self):
        self.__studenti = []

    def adauga_student(self, student):
        """
        Metoda care adauga un student in lista de studenti
        :param student: obiect de clasa Student
        :return: -, daca nu sunt erori
        :raises: AddStudentError, daca deja exista un student cu acelasi id in lista de studenti
        """
        if len(self.__studenti) > 0:
            for studentExistent in self.__studenti:
                if studentExistent.get_id() == student.get_id():
                    raise AddStudentError("Deja exista un student cu acest id!")
        self.__studenti.append(student)

    def sterge_student(self, id: int):
        """
        Metoda care sterge un student din lista de studenti
        :param id: int, id-ul studentului
        :return: -, daca nu sunt erori
        :raises: RemoveStudentError, daca nu exista nici un student cu student_id-ul = id
        """
        removed = False
        for student in self.__studenti:
            if student.get_id() == id:
                removed = True
                self.__studenti.remove(student)
        if not removed:
            raise RemoveStudentError("Nu exista nici un student cu acest ID!")

    def sterge_student_recursiv(self, id: int, index = 0):
        """
        Metoda care sterge o disciplina din lista de discipline folosind recursivitate
        :param id: int, id-ul disciplinei
        :param index: int, indexul curent pentru parcurgerea recursiva
        :return: -, daca nu sunt erori
        :raises: RemoveDisciplineError, daca nu exista nici o disciplina cu disciplina_id-ul = id
        """
        if index >= len(self.__studenti):
            raise RemoveStudentError("Nu exista nici o disciplina cu acest ID!")

        if self.__studenti[index].get_id() == id:
            self.__studenti.pop(index)
            return

        self.sterge_student_recursiv(id, index + 1)

    def cauta_student(self, id: int):
        """
        Metoda care cauta un student in lista de studenti si apoi il returneaza, daca exista
        :param id: int, id-ul studentului
        :return: studentul cautat, daca nu sunt erori
        :raises: SearchStudentError, daca nu exista nici un student in lista de stundeti cu student_id-ul = id
        """
        if len(self.__studenti) > 0:
            for student in self.__studenti:
                if student.get_id() == id:
                    return student
        raise SearchStudentError(f"Studentul cu ID-ul {id} nu a fost gasit.")


    def modifica_nume_student(self, student_id: int, nume: str):
        """
        Metoda care modifica numele unei student cu id-ul student_id, daca exista, cu noul nume
        :param student_id: int, id-ul studentului
        :param nume: string, noul nume al studentului
        :return: -, daca nu sunt erori
        :raises: SearchStudentErrror, in cazul in care nu exista studnetul cu id-ul student_id
        """
        try:
            studentDeModificat = self.cauta_student(student_id)
            studentDeModificat.set_nume(nume)
        except SearchStudentError as e:
            raise e

    def get_all_students(self):
        return self.__studenti

    def reset(self):
        self.__studenti.clear()