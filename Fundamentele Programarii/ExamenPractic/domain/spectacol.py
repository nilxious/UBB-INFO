class Spectacol:
    def __init__(self, titlu: str, artist: str, gen: str, durata: int):
        self.__titlu = titlu
        self.__artist = artist
        self.__gen = gen
        self.__durata = durata

    def titlu(self):
        """
        Metoda care returneaza titlul unui spectacol
        :return: titlul, tip string
        """
        return self.__titlu

    def artist(self):
        """
        Metoda care returneaza artistul unui spectacol
        :return: artistul, tip string
        """
        return self.__artist

    def gen(self):
        """
        Metoda care returneaza genul unui spectacol
        :return: genul, tip string
        """
        return self.__gen

    def durata(self):
        """
        Metoda care returneaza durata unui spectacol
        :return: durata, tip int
        """
        return self.__durata

    def set_gen(self, gen_nou: str):
        """
        Metoda care actualizeaza genul unui spectacol
        :param gen_nou: genul nou cu care va fi actualizat spectacolul, tip string
        :return: -
        """
        self.__gen = gen_nou

    def set_durata(self, durata_noua: int):
        """
        Metoda care actualizeaza durata unui spectacol
        :param durata_noua: durata noua cu care va fi actualizat spectacolul, tip int
        :return: -
        """
        self.__durata = durata_noua

    def __eq__(self, other):
        """
        Metoda care verifica daca doua spectacole sunt identice
        :param other: al doilea spectacol, tip Spectacol
        :return: True, daca cele doua spectacole sunt egale
                 False, daca cele doua nu sunt egale sau daca sunt de tipuri diferite
        """
        if type(other) == type(self):
            return self.__titlu == other.titlu() and self.__artist == other.artist() and self.__gen == other.gen() \
                and self.__durata == other.durata()
        else:
            return False

    def string_to_file(self):
        """
        Metoda care returneaza insiruirea datelor unui spectacol
        :return: insiruirea datelor, separate prin cate o virgula, tip string
        """
        return f"{self.__titlu},{self.__artist},{self.__gen},{self.__durata}"

    def string_to_export(self):
        """
        Metoda care returneaza insiruirea datelor unui spectacol in formatul pentru export
        :return: insiruirea datelor, separate prin cate o virgula, tip string
        """
        return f"{self.__artist},{self.__titlu},{self.__durata},{self.__gen}"