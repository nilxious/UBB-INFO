from errors import (AddDisciplineError, SearchDisciplineError, RemoveDisciplineError)

class RepoDiscipline(object):
    def __init__(self):
        self.__discipline = []

    def sterge_disciplina(self, id: int):
        """
        Metoda care sterge o disciplina din lista de discipline
        :param id: int, id-ul disciplinei
        :return: -, daca nu sunt erori
        :raises: RemoveDisciplineError, daca nu exista nici o disciplina cu disciplina_id-ul = id
        """
        removed = False
        for disciplina in self.__discipline:
            if disciplina.get_id() == id:
                removed = True
                self.__discipline.remove(disciplina)
        if not removed:
            raise RemoveDisciplineError("Nu exista nici o disciplina cu acest ID!")

    def sterge_disciplina_recursiv(self, id: int, index = 0):
        """
        Metoda care sterge o disciplina din lista de discipline folosind recursivitate
        :param id: int, id-ul disciplinei
        :param index: int, indexul curent pentru parcurgerea recursiva
        :return: -, daca nu sunt erori
        :raises: RemoveDisciplineError, daca nu exista nici o disciplina cu disciplina_id-ul = id
        """
        if index >= len(self.__discipline):
            raise RemoveDisciplineError("Nu exista nici o disciplina cu acest ID!")

        if self.__discipline[index].get_id() == id:
            self.__discipline.pop(index)
            return

        self.sterge_disciplina_recursiv(id, index + 1)


    def adauga_disciplina(self, disciplina):
        """
        Metoda care adauga o disciplina in lista de discipline
        :param disciplina: obiect de clasa Disciplina
        :return: -, daca nu sunt erori
        :raises: AddDisciplineError, daca deja exista o disciplina cu id-ul = disciplina_id
        """
        idDisciplina = disciplina.get_id()
        if len(self.__discipline) > 0:
            for disciplinaExistenta in self.__discipline:
                if disciplinaExistenta.get_id() == idDisciplina:
                    raise AddDisciplineError("Deja exista o disciplina cu acest id!")
        self.__discipline.append(disciplina)

    def cauta_disciplina(self, id: int):
        """
        Metoda care cauta o disciplina in lista de discipline si apoi o returneaza, daca exista
        :param id: int, id-ul disciplinei
        :return: disciplina cautata, daca nu sunt erori
        :raises: SearchDisciplineError, daca nu exista nici o disciplina in lista de discipline cu disciplina_id-ul = id

        Complexitate timp:
            - Best Case : O(1)
            Se întâmplă dacă elementul căutat este primul din listă. Metoda returnează imediat fără a mai parcurge restul listei.

            - Worst Case : O(n)
            Se întâmplă atunci când:
            Elementul căutat se află la finalul listei.
            Elementul nu există, iar metoda parcurge întreaga listă înainte de a ridica excepția SearchDisciplineError.

            - Average Case : O(n)
            În medie, metoda trebuie să parcurgă aproximativ jumătate din listă (n/2, dar 1/2 este constantă) pentru a găsi elementul căutat.

            Per total complexitatea este O(n).
        """
        if len(self.__discipline) > 0:
            for disciplina in self.__discipline:
                if disciplina.get_id() == id:
                    return disciplina
        raise SearchDisciplineError(f"Disciplina cu ID-ul {id} nu a fost gasita.")

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

    def get_all_disciplines(self):
        return self.__discipline

    def reset(self):
        self.__discipline.clear()