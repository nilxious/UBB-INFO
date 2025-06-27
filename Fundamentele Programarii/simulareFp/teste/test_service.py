import unittest
from business.service_statistici import ServiceStatistici
from repo.repo_statistici import RepoStatistici
from validators.validator_statistica import ValidatorStatistica
from domain.statistica import Statistica

class TestService(unittest.TestCase):
    def setUp(self):
        self.__repo = RepoStatistici("C:/Users/Catalin/Documents/FundamenteleProgramarii/simulareFp/statistici_pt_teste")

        self.__statistica1 = Statistica("Denmark",2024,0.8,1.2,5947000)
        self.__statistica2 = Statistica("France",2021,2.1,4.9,68100000)
        self.__statistica3 = Statistica("Denmark",2020,1.2,1.4,5940000)

        self.__repo.adauga_statistica(self.__statistica1)
        self.__repo.adauga_statistica(self.__statistica2)
        self.__repo.adauga_statistica(self.__statistica3)

        self.__validator = ValidatorStatistica()
        self.__service = ServiceStatistici(self.__repo, self.__validator)

    def test_add_statistica(self):
        numeBun, anBun, inflatieBuna, unemploymentBun, populatieBuna = "Japan",2024,0.8,1.2,5947000
        statisticaBuna = Statistica("Japan",2024,0.8,1.2,5947000)

        self.__service.add_statistica(numeBun, anBun, inflatieBuna, unemploymentBun, populatieBuna)

        self.assertEqual(self.__repo.get_all(), [self.__statistica1, self.__statistica2, self.__statistica3, statisticaBuna])

    def tearDown(self):
        self.__repo.reset_repo()
