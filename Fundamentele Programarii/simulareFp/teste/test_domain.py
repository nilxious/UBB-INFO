import unittest
from domain.statistica import Statistica

class TestDomain(unittest.TestCase):
    def setUp(self):
        self.__statistica1 = Statistica("Denmark",2024,0.8,1.2,5947000)

    def test_gettere(self):
        self.assertEqual(self.__statistica1.get_nume(), "Denmark")
        self.assertEqual(self.__statistica1.get_an(), 2024)
        self.assertEqual(self.__statistica1.get_inflatie(), 0.8)
        self.assertEqual(self.__statistica1.get_rate(), 1.2)
        self.assertEqual(self.__statistica1.get_populatie(), 5947000)