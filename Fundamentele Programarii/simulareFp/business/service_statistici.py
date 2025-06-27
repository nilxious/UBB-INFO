from domain.statistica import Statistica
from validators.validator_statistica import ValidatorStatistica


class ServiceStatistici:
    def __init__(self, repoStatistici, validatorStatistici):
        self.__repoStatistici = repoStatistici
        self.__validatorStatistici = validatorStatistici

    def add_statistica(self, nume: str, an: int, inflatie: float, rate: float, populatie: int):
        """
        Metoda care valideaza datele unei statistii
        :param nume: numele tarii, tip string
        :param an: anul, tip int
        :param inflatie: rata de inflatie, tip float
        :param rate: rata de somaj, tip float
        :param populatie: populatie, tip int
        :return: -, daca nu sunt erori
        :raises: ValidationError, in cazul in care datele nu sunt corecte
        """
        statistica = Statistica(nume, an, inflatie, rate, populatie)

        self.__validatorStatistici.valideaza(statistica)

        self.__repoStatistici.adauga_statistica(statistica)


