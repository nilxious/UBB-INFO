class Statistica:
    def __init__(self, nume: str, an: int, inflatie: float, unemployment_rate: float, populatie: int):
        self.__nume = nume
        self.__an = an
        self.__inflatie = inflatie
        self.__unemployment_rate = unemployment_rate
        self.__populatie = populatie

    def get_nume(self):
        """
        Metoda care returneaza tara statisticii
        :return: numele tarii, de tip string
        """
        return self.__nume

    def get_an(self):
        """
        Metoda care returneaza anul statisticii
        :return: anul, tip int
        """
        return self.__an

    def get_inflatie(self):
        """
        Metoda care returneaza inflatia statisticii
        :return: rata de inflatiem tip float
        """
        return self.__inflatie

    def get_rate(self):
        """
        Metoda care returneaza rata de somaj a statisticii
        :return: rata de somaj. tip float
        """
        return self.__unemployment_rate

    def get_populatie(self):
        """
        Metoda care returneaza populatia statisticii
        :return: populatia, tip int
        """
        return self.__populatie

    def __str__(self):
        return (f"{self.__nume},{self.__an},{self.__inflatie},{self.__unemployment_rate},{self.__populatie}")

    def __eq__(self, otherStat):
        if(type(otherStat) is Statistica):
            return otherStat.get_nume() == self.__nume and otherStat.get_an() == self.__an and otherStat.get_inflatie() == self.__inflatie and otherStat.get_rate() == self.__unemployment_rate and otherStat.get_populatie() == self.__populatie



