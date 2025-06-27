import unittest
from repository.repo_spectacole import RepositorySpectacole
from domain.spectacol import Spectacol
from business.service_spectacole import ServiceSpectacole
from validator.validator_spectacole import ValidatorSpectacol
from errors.errors import ValidationError
import random

class TestService(unittest.TestCase):
    def setUp(self):
        self.__repo = RepositorySpectacole("C:/Users/Catalin/Documents/FundamenteleProgramarii/Practic/fisier_de_test.txt")

        self.__spectacol1 = Spectacol("Ceva2","Artist2","Comedie",3600)
        self.__spectacol2 = Spectacol("Ceva1", "Artist1", "Concert", 1500)
        self.__spectacol3 = Spectacol("Ceva3", "Artist3", "Altele", 1800)

        self.__repo.adauga_spectacol(self.__spectacol1)
        self.__repo.adauga_spectacol(self.__spectacol2)
        self.__repo.adauga_spectacol(self.__spectacol3)

        self.__validator = ValidatorSpectacol()
        self.__service = ServiceSpectacole(self.__repo, self.__validator)

    def test_add_spectacol(self):
        titlu_invalid = ""
        artist_invalid = ""
        gen_invalid = "X"
        durata_invalida = -4

        titlu = "Titlu1"
        artist = "Artist1"
        gen = "Comedie"
        durata = 12345

        try:
            self.__service.add_spectacol(titlu_invalid,artist,gen,durata)
            assert False
        except ValidationError:
            assert True

        try:
            self.__service.add_spectacol(titlu,artist_invalid,gen,durata)
            assert False
        except ValidationError:
            assert True

        try:
            self.__service.add_spectacol(titlu,artist,gen_invalid,durata)
            assert False
        except ValidationError:
            assert True

        try:
            self.__service.add_spectacol(titlu,artist,gen,durata_invalida)
            assert False
        except ValidationError:
            assert True

    def test_modify_spectacol(self):
        titlu_invalid = ""
        artist_invalid = ""
        gen_invalid = "X"
        durata_invalida = -4

        titlu = "Ceva1"
        artist = "Artist1"
        gen = "Comedie"
        durata = 12345
        durata_noua = 333333

        try:
            self.__service.modify_spectacol(titlu,artist,gen_invalid,durata_noua)
            assert False
        except ValidationError:
            assert True

        try:
            self.__service.modify_spectacol(titlu,artist,gen,durata_invalida)
            assert False
        except ValidationError:
            assert True

        try:
            self.__service.modify_spectacol(titlu,artist,gen_invalid,durata_invalida)
            assert False
        except ValidationError:
            assert True

    def test_get_all(self):
        expected = [self.__spectacol1,self.__spectacol2,self.__spectacol3]

        self.assertEqual(self.__service.get_all(), expected)

    def test_generate_spectacole(self):
        random.seed(10)
        spectacole_de_generat = 5

        self.__generat1 = Spectacol("zizib ejaba","pakof eniho","Concert",2889)
        self.__generat2 = Spectacol("poza xude","dira tuxe","Comedie",5182)
        self.__generat3 = Spectacol("buni kage","xumip avuro","Balet",2975)
        self.__generat4 = Spectacol("kedo lawo","rahe varifu","Balet",3777)
        self.__generat5 = Spectacol("boqi rifigi","gapu kiqe","Comedie",3045)

        expected = [self.__generat1,self.__generat2,self.__generat3,self.__generat4,self.__generat5]

        generate = self.__service.generate_spectacole(spectacole_de_generat)

        self.assertEqual(expected,generate)


    def test_export_spectacole(self):
        filtrate = self.__service.filter_spectacole()
        expected = [self.__spectacol2,self.__spectacol1,self.__spectacol3]
        self.assertEqual(filtrate,expected)


    def tearDown(self):
        self.__repo.reset()

if __name__ == '__main__':
    unittest.main(verbosity =  1)