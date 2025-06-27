from errors import (AddStudentError, AddDisciplineError, SearchStudentError, SearchDisciplineError, RemoveStudentError,
                    NoGradesError, RemoveDisciplineError, NoDisciplineOrStudent)

class Facultate(object):
    def __init__(self):
        self.studenti = []
        self.discipline = []
        self.note = []

    def adauga_student(self, student):
        """
        Metoda care adauga un student in lista de studenti
        :param student: obiect de clasa Student
        :return: -, daca nu sunt erori
        :raises: AddStudentError, daca deja exista un student cu acelasi id in lista de studenti
        """
        if len(self.studenti) > 0:
            for studentExistent in self.studenti:
                if studentExistent.get_id() == student.get_id():
                    raise AddStudentError("Deja exista un student cu acest id!")
        self.studenti.append(student)

    def sterge_student(self, id: int):
        """
        Metoda care sterge un student din lista de studenti
        :param id: int, id-ul studentului
        :return: -, daca nu sunt erori
        :raises: RemoveStudentError, daca nu exista nici un student cu student_id-ul = id
        """
        removed = False
        for student in self.studenti:
            if student.get_id() == id:
                removed = True
                self.studenti.remove(student)
        if not removed:
            raise RemoveStudentError("Nu exista nici un student cu acest ID!")

    def sterge_disciplina(self, id: int):
        """
        Metoda care sterge o disciplina din lista de discipline
        :param id: int, id-ul disciplinei
        :return: -, daca nu sunt erori
        :raises: RemoveDisciplineError, daca nu exista nici o disciplina cu disciplina_id-ul = id
        """
        removed = False
        for disciplina in self.discipline:
            if disciplina.get_id() == id:
                removed = True
                self.discipline.remove(disciplina)
        if not removed:
            raise RemoveDisciplineError("Nu exista nici o disciplina cu acest ID!")

    def adauga_disciplina(self, disciplina):
        """
        Metoda care adauga o disciplina in lista de discipline
        :param disciplina: obiect de clasa Disciplina
        :return: -, daca nu sunt erori
        :raises: AddDisciplineError, daca deja exista o disciplina cu id-ul = disciplina_id
        """
        idDisciplina = disciplina.get_id()
        if len(self.discipline) > 0:
            for disciplinaExistenta in self.discipline:
                if disciplinaExistenta.get_id() == idDisciplina:
                    raise AddDisciplineError("Deja exista o disciplina cu acest id!")
        self.discipline.append(disciplina)

    def cauta_student(self, id: int):
        """
        Metoda care cauta un student in lista de studenti si apoi il returneaza, daca exista
        :param id: int, id-ul studentului
        :return: studentul cautat, daca nu sunt erori
        :raises: SearchStudentError, daca nu exista nici un student in lista de stundeti cu student_id-ul = id
        """
        if len(self.studenti) > 0:
            for student in self.studenti:
                if student.get_id() == id:
                    return student
        raise SearchStudentError(f"Studentul cu ID-ul {id} nu a fost gasit.")

    def cauta_disciplina(self, id: int):
        """
        Metoda care cauta o disciplina in lista de discipline si apoi o returneaza, daca exista
        :param id: int, id-ul disciplinei
        :return: disciplina cautata, daca nu sunt erori
        :raises: SearchDisciplineError, daca nu exista nici o disciplina in lista de discipline cu disciplina_id-ul = id
        """
        if len(self.discipline) > 0:
            for disciplina in self.discipline:
                if disciplina.get_id() == id:
                    return disciplina
        raise SearchDisciplineError(f"Disciplina cu ID-ul {id} nu a fost gasita.")

    def adauga_nota(self, nota):
        """
        Metoda care adauga o nota unui student la o disciplina in lista de note
        :param nota: obiect de clasa Nota
        :return: -, daca nu sunt erori
        :raises: NoDisciplineOrStudent, in cazul in care nu exista disciplina cu id-ul disciplina_id sau nu exista studentul cu id-ul student_id
        """
        errors = []

        try:
            student = self.cauta_student(nota.get_student_id())
        except SearchStudentError as e:
            errors.append(str(e))

        try:
            disciplina = self.cauta_disciplina(nota.get_disciplina_id())
        except SearchDisciplineError as e:
            errors.append(str(e))

        if len(errors) > 0:
            error_message = ', '.join(errors)
            raise NoDisciplineOrStudent(error_message)
        else:
            self.note.append(nota)

    def ia_note_student(self, student_id: int, disciplina_id: int):
        """
        Metoda care creeaza si returneaza lista de note la o disciplina a unui student
        :param student_id: int, id-ul studentului
        :param disciplina_id: int, id-ul disciplina
        :return: lista de note a unui student la o disciplina, daca nu sunt erori
        :raises: NoGradesError, in cazul in care studentul cu id-ul student_id nu are nici o nota la disciplina cu id-ul disciplina_id
                 NoDisciplineOrStudent, in cazul in care nu exista disciplina cu id-ul disciplina_id sau nu exista studentul cu id-ul student_id
        """
        errors = []

        try:
            self.cauta_disciplina(disciplina_id)
        except SearchDisciplineError as e:
            errors.append(str(e))

        try:
            self.cauta_student(student_id)
        except SearchStudentError as e:
            errors.append(str(e))

        if len(errors) > 0:
            error_message = ', '.join(errors)
            raise NoDisciplineOrStudent(error_message)

        else:
            noteDisciplina = [nota for nota in self.note
            if nota.get_student_id() == student_id and nota.get_disciplina_id() == disciplina_id]

            if not noteDisciplina:
                raise NoGradesError(f"Studentul cu ID-ul {student_id} nu are nici o nota la aceasta disciplina")

        return noteDisciplina

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

    def modifica_nume_disciplina(self, disciplina_id: int, nume_disciplina: str):
        """
        Metoda care modifica numele unei discipline cu id-ul disciplina_id, daca exista, cu noul nume nume_disciplina
        :param disciplina_id: int, id-ul disciplinei
        :param nume_disciplina: string, numele disciplnei noi
        :return: -, daca nu sunt erori
        :raises: SearchStudentErrror, in cazul in care nu exista studnetul cu id-ul student_id
        """
        try:
            disciplinaDeModificat = self.cauta_disciplina(disciplina_id)
            disciplinaDeModificat.set_nume(nume_disciplina)
        except SearchDisciplineError as e:
            raise e

    def modifica_nume_profesor_disciplina(self, disciplina_id: int, nume_profesor: str):
        """
        Metoda care modifica numele profesorului unei discipline cu id-ul disciplina_id, daca exista, cu noul nume nume_profesor
        :param disciplina_id: int, id-ul disciplinei
        :param nume_profesor: string, numele noului profesor
        :return: -, daca nu sunt erori
        :raises: SearchStudentErrror, in cazul in care nu exista studnetul cu id-ul student_id
        """
        try:
            disciplinaDeModificat = self.cauta_disciplina(disciplina_id)
            disciplinaDeModificat.set_nume_profesor(nume_profesor)
        except SearchDisciplineError as e:
            raise e