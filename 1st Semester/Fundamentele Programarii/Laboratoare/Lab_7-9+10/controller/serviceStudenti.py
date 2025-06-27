import random
import string

from domain.student import Student
from validare.validare_student import ValidatorStudent


class ServiceStudenti(object):
    def __init__(self, repoStudenti):
        self.__repoStudenti = repoStudenti

    def add_student(self, id: int, nume: str):
        """
        Metoda care creeaza un student cu parametrii id si nume, dupa care il adauga in baza de date a studentilor

        :param id: int, trebuind sa aiba exact 5 cifre
        :param nume: string, numele studentului
        :return: -, daca datele sunt valide
        :raises: ValidationError, daca id-ul studentului nu are exact 5 cifre sau este negativ, sau daca numele acestuia are caractere
        diferite de literele alfabetului si de caracterul "-"
        """
        studentNou = Student(id, nume)
        ValidatorStudent().valideaza(studentNou)

        self.__repoStudenti.adauga_student(studentNou)

    def remove_student(self, id: int):
        """
        Metoda care sterge un student din baza de date a studentilor, daca acesta exista
        :param id: int, id-ul studentului
        :return: -, daca datele sunt valide
        :raises: ValidationError, daca id-ul studentului nu are exact 5 cifre sau este negativ, sau daca numele acestuia are caractere
        diferite de literele alfabetului si de caracterul "-"
        """
        ValidatorStudent().valideaza(Student(id, "Lorem ipsum"))

        self.__repoStudenti.sterge_student(id)

    def search_student(self, id: int):
        """
        Metoda care cauta un student din baza de date a studentilor, dupa id, iar daca exista il returneaza
        :param id: int, id-ul studentului
        :return: studentul cautat, daca datele sunt valide si stundetul cu id-ul id exista
        :raises: ValidationError, daca id-ul studentului nu are exact 5 cifre sau este negativ, sau daca numele acestuia are caractere
        diferite de literele alfabetului si de caracterul "-"
        """
        ValidatorStudent().valideaza(Student(id, "Lorem ipsum"))

        return self.__repoStudenti.cauta_student(id)

    def modify_student_name(self, student_id: int, nume: str):
        """
        Metoda care schimba numele unui student din baza de date a studentilor, dupa id, daca exista
        :param student_id: int, id-ul studentului
        :param nume: string, noul nume al studentului
        :return: -, daca datele sunt valide
        :raises: ValidationError, daca id-ul studentului nu are exact 5 cifre sau este negativ, sau daca numele acestuia are caractere
        diferite de literele alfabetului si de caracterul "-"
        """
        ValidatorStudent().valideaza(Student(student_id, nume))

        self.__repoStudenti.modifica_nume_student(student_id, nume)

    def get_all_students(self):
        """
        Metoda care returneaza baza de date a studentilor (lista de studenti)
        :return: lista de studenti
        """
        return self.__repoStudenti.get_all_students()

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

        nume_complet = nume + " " + prenume

        return nume_complet

    def generate_random_students(self):
        """
        Metoda care genereaza studenti cu nume si id aleatoriu, adaugandu-i in baza de date a studentilor
        :return: -
        """
        nume_random = self.generate_nume_prenume_random()
        id_random = random.randint(10000, 99999)
        self.add_student(id_random, nume_random)
