import unittest
from domain.spectacol import Spectacol

class TestDomain(unittest.TestCase):
    def setUp(self):
        pass

    def test_gettere(self):
        spectacol = Spectacol("Ceva1", "Ceva2", "Comedie", 12345)

        self.assertEqual(spectacol.titlu(), "Ceva1")

        self.assertEqual(spectacol.artist(),"Ceva2")

        self.assertEqual(spectacol.gen(),"Comedie")

        self.assertEqual(spectacol.durata(),12345)

    def test_settere(self):
        spectacol = Spectacol("Ceva1", "Ceva2", "Ceva3", 12345)

        spectacol.set_gen("Comedie")
        self.assertEqual(spectacol.gen(),"Comedie")

        spectacol.set_durata(99999)
        self.assertEqual(spectacol.durata(),99999)

    def test_eq(self):
        spectacol1 = Spectacol("Ceva", "Ceva", "Comedie", 12345)

        spectacol2 = Spectacol("Ceva", "Ceva", "Comedie", 12345)

        self.assertEqual(spectacol1,spectacol2)

if __name__ == '__main__':
    unittest.main(verbosity =  1)
