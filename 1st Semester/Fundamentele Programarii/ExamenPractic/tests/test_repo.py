import unittest
from repository.repo_spectacole import RepositorySpectacole
from errors.errors import RepositoryError
from domain.spectacol import Spectacol

class TestRepository(unittest.TestCase):
    def setUp(self):
        self.__repo = RepositorySpectacole("C:/Users/Catalin/Documents/FundamenteleProgramarii/Practic/fisier_de_test.txt")

        self.__spectacol1 = Spectacol("Ceva1","Artist1","Comedie",3600)
        self.__spectacol2 = Spectacol("Ceva2", "Artist2", "Concert", 1500)
        self.__spectacol3 = Spectacol("Ceva3", "Artist3", "Altele", 1800)

        self.__repo.adauga_spectacol(self.__spectacol1)
        self.__repo.adauga_spectacol(self.__spectacol2)
        self.__repo.adauga_spectacol(self.__spectacol3)

        self.__spectacol_de_adaugat = Spectacol("Adaugat","Adaugat","Comedie",9999)

    def test_ia_all(self):
        expected = [self.__spectacol1, self.__spectacol2, self.__spectacol3]

        self.assertEqual(expected, self.__repo.ia_all())

    def test_adauga_spectacol(self):
        self.__repo.adauga_spectacol(self.__spectacol_de_adaugat)
        expected = [self.__spectacol1, self.__spectacol2, self.__spectacol3,self.__spectacol_de_adaugat]

        self.assertEqual(expected, self.__repo.ia_all())

    def test_modifica_spectacol(self):
        titlu = "Ceva1"
        artist = "Artist1"
        gen_nou = "Altele"
        durata_noua = 9999
        spectacol_modificat = Spectacol(titlu,artist,gen_nou,durata_noua)

        expected = [spectacol_modificat, self.__spectacol2, self.__spectacol3]

        self.__repo.modifica_spectacol(titlu,artist,gen_nou,durata_noua)

        self.assertEqual(expected, self.__repo.ia_all())

        titlu_prost = "a"
        artist_prost = "a"
        gen_nou = "Altele"
        durata_noua = 7777

        try:
            self.__repo.modifica_spectacol(titlu_prost,artist_prost,gen_nou,durata_noua)
            assert False
        except RepositoryError:
            assert True


    def test_reset(self):
        self.__repo.reset()
        self.assertEqual([], self.__repo.ia_all())

    def tearDown(self):
        self.__repo.reset()

if __name__ == '__main__':
    unittest.main(verbosity =  1)
