from errors import NoGradesError


class RepoNote(object):
    def __init__(self):
        self.__note = []

    def adauga_nota(self, nota):
        """
        Metoda care adauga o nota unui student la o disciplina in lista de note
        :param nota: obiect de clasa Nota
        :return: -, daca nu sunt erori
        :raises: NoDisciplineOrStudent, in cazul in care nu exista disciplina cu id-ul disciplina_id sau nu exista studentul cu id-ul student_id
        """
        self.__note.append(nota)

    def ia_note_student(self, student_id: int, disciplina_id: int):
        """
        Metoda care creeaza si returneaza lista de note la o disciplina a unui student
        :param student_id: int, id-ul studentului
        :param disciplina_id: int, id-ul disciplina
        :return: lista de note a unui student la o disciplina, daca nu sunt erori
        :raises: NoGradesError, in cazul in care studentul cu id-ul student_id nu are nici o nota la disciplina cu id-ul disciplina_id
                 NoDisciplineOrStudent, in cazul in care nu exista disciplina cu id-ul disciplina_id sau nu exista studentul cu id-ul student_id
        """
        noteDisciplina = [nota for nota in self.__note
            if nota.get_student_id() == student_id and nota.get_disciplina_id() == disciplina_id]

        if not noteDisciplina:
            raise NoGradesError(f"Studentul cu ID-ul {student_id} nu are nici o nota la aceasta disciplina")

        return noteDisciplina

    def get_all_note(self):
        return self.__note

    def reset(self):
        self.__note.clear()