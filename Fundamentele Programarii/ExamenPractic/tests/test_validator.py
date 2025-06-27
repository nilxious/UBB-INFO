import unittest

from validator.validator_spectacole import ValidatorSpectacol
from domain.spectacol import Spectacol
from errors.errors import ValidationError

class TestValidator(unittest.TestCase):
    def setUp(self):
        self.__validator = ValidatorSpectacol()

    def test_validare(self):
        test1 = Spectacol("Titlu1", "Artist1", "Comedie", 12345)
        try:
            self.__validator.valideaza(test1)
            assert True
        except ValidationError:
            assert False

        test2 = Spectacol("","Artist1","Comedie", 12345)
        try:
            self.__validator.valideaza(test2)
            assert False
        except ValidationError:
            assert True

        test3 = Spectacol("Titlu1", "", "Comedie", 12345)
        try:
            self.__validator.valideaza(test3)
            assert False
        except ValidationError:
            assert True

        test4 = Spectacol("", "", "Comedie", 12345)
        try:
            self.__validator.valideaza(test4)
            assert False
        except ValidationError:
            assert True

        test5 = Spectacol("Artist1", "Titlu1", "X", 12345)
        try:
            self.__validator.valideaza(test5)
            assert False
        except ValidationError:
            assert True

        test6 = Spectacol("Artist1", "Titlu1", "Altele", -1)
        try:
            self.__validator.valideaza(test6)
            assert False
        except ValidationError:
            assert True

        test7 = Spectacol("Artist1", "Titlu1", "Altele", 0)
        try:
            self.__validator.valideaza(test7)
            assert False
        except ValidationError:
            assert True

        test8 = Spectacol("", "", "X", -1)
        try:
            self.__validator.valideaza(test8)
            assert False
        except ValidationError:
            assert True

if __name__ == '__main__':
    unittest.main(verbosity=1)
