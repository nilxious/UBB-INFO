import random
import string

from domain.disciplina import Disciplina
from validare.validare_disciplina import ValidatorDisciplina

class ServiceDiscipline(object):
    def __init__(self, repoDiscipline):
        self.__repoDiscipline = repoDiscipline

    def remove_disciplina(self, id: int):
        """
        Metoda care sterge o disciplina din baza de date a disciplinelor, daca aceasta exista
        :param id: int, id-ul disciplinei
        :return: -, daca datele sunt valide
        :raises: ValidationError, daca id-ul disciplinei este negativ
        """
        ValidatorDisciplina().valideaza(Disciplina(id, "Lorem ipsum", "Lorem ipsum"))

        self.__repoDiscipline.sterge_disciplina(id)

    def add_disciplina(self, id: int, nume: str, profesor: str):
        """
        Metoda care creeaza si adauga o disciplina cu parametrii id, nume, profesor in baza de date a disciplinelor
        in cazul in care aceasta nu exista deja
        :param id: int, id-ul disciplinei
        :param nume: string, numele materiei
        :param profesor: string, numele profesorului
        :raises ValidationError, daca id-ul disciplinei este negativ
        :return: -, daca datele sunt valide
        """
        disciplinaNoua = Disciplina(id, nume, profesor)

        ValidatorDisciplina().valideaza(disciplinaNoua)

        self.__repoDiscipline.adauga_disciplina(disciplinaNoua)

    def search_disciplina(self, disciplina_id: int):
        """
        Metoda care cauta o disciplina din baza de date a disciplinelor, dupa id, iar daca exista o returneaza
        :param disciplina_id: int, id-ul disciplinei
        :return: disciplina cautata, daca datele sunt valide si disciplina cu id-ul disciplina_id exista
        :raises: ValidationError, daca id-ul disciplinei este negativ
        """
        ValidatorDisciplina().valideaza(Disciplina(disciplina_id, "Lorem ipsum", "Lorem ipsum"))

        return self.__repoDiscipline.cauta_disciplina(disciplina_id)

    def modify_disciplina_nume(self, disciplina_id: int, nume_disciplina: str):
        """
        Metoda care schimba numele unei discipline din baza de date a disciplinelor, dupa id, daca exista
        :param disciplina_id: int, id-ul disciplinei
        :param nume_disciplina: string, numele disciplinei cu id-ul disciplina_id
        :return: -, daca datele sunt valide
        :raises: ValidationError, daca id-ul disciplinei este negativ
        """
        ValidatorDisciplina().valideaza(Disciplina(disciplina_id, nume_disciplina, "Lorem ipsum"))

        self.__repoDiscipline.modifica_nume_disciplina(disciplina_id, nume_disciplina)

    def modify_disciplina_nume_profesor(self, disciplina_id: int, nume_profesor: str):
        """
        Metoda care schimba numele profesorului unei discipline din baza de date a disciplinelor, dupa id, daca exista
        :param disciplina_id:  int, id-ul disciplinei
        :param nume_profesor: string, numele profesorului al disciplinei cu id-ul disciplina_id
        :return: -, daca datele sunt valide
        :raises: ValidationError, daca id-ul disciplinei este negativ
        """
        ValidatorDisciplina().valideaza(Disciplina(disciplina_id, "Lorem ipsum", nume_profesor))

        self.__repoDiscipline.modifica_nume_profesor_disciplina(disciplina_id, nume_profesor)

    def get_all_disciplines(self):
        """
        Metoda care returneaza baza de date a disciplinelor (lista de discipline
        :return: lista de discipline
        """
        disciplines = self.__repoDiscipline.get_all_disciplines()
        return self.__repoDiscipline.get_all_disciplines()

    def generate_nume_prenume_random(self):
        """
        Metoda care genereaza un nume si un prenume aleatoriu
        :return: numele complet, de tip string
        """
        def string_random():
            length = random.randint(5, 10)
            return ''.join(random.choices(string.ascii_lowercase, k=length))

        nume = string_random().capitalize()
        prenume = string_random().capitalize()

        nume_complet = nume + " " +     prenume

        return nume_complet

    def generate_nume_disciplina_random(self):
        """
        Metoda care creeaza un nume aleatoriu al unei discipline
        :return: numele disciplinei, tip string
        """
        def string_random():
            length = random.randint(5, 10)
            return ''.join(random.choices(string.ascii_lowercase, k=length))

        disciplina = string_random().capitalize()

        return disciplina

    def generate_random_disciplines(self):
        """
        Metoda care genereaza discipline cu nume de disciplina, nume de profesor si id aleatoriu
        :return: -
        """
        nume_profesor_random = self.generate_nume_prenume_random()
        nume_disciplina_random = self.generate_nume_disciplina_random()
        id_random = random.randint(1,200)
        self.add_disciplina(id_random, nume_profesor_random, nume_disciplina_random)

