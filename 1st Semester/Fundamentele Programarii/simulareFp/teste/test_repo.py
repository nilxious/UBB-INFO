import unittest
from repo.repo_statistici import RepoStatistici
from domain.statistica import Statistica
from errors.errors import RepositoryError

class TestRepo(unittest.TestCase):
    def setUp(self):
        self.__repo = RepoStatistici("C:/Users/Catalin/Documents/FundamenteleProgramarii/simulareFp/statistici_pt_teste")

        self.__statistica1 = Statistica("Denmark",2024,0.8,1.2,5947000)
        self.__statistica2 = Statistica("France",2021,2.1,4.9,68100000)
        self.__statistica3 = Statistica("Denmark",2020,1.2,1.4,5940000)

        self.__repo.adauga_statistica(self.__statistica1)
        self.__repo.adauga_statistica(self.__statistica2)
        self.__repo.adauga_statistica(self.__statistica3)

        self.__statistica4 = Statistica("Denmark", 2020, 1.5, 2.4, 6000000)
        self.__statistica5 = Statistica("Paraguay", 2020, 1.5, 2.4, 6000000)

    def test_get_all(self):
        expectedStatistici = [self.__statistica1, self.__statistica2, self.__statistica3]
        self.assertEqual(self.__repo.get_all(), expectedStatistici)

    def test_adauga_statistica(self):
        self.__repo.adauga_statistica(self.__statistica5)
        expectedStatistici = [self.__statistica1, self.__statistica2, self.__statistica3, self.__statistica5]
        self.assertEqual(self.__repo.get_all(), expectedStatistici)

        try:
            self.__repo.adauga_statistica(self.__statistica4)
            assert False
        except RepositoryError:
            assert True

    def tearDown(self):
        self.__repo.reset_repo()
