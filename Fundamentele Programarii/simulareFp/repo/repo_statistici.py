from errors.errors import RepositoryError
from domain.statistica import Statistica

class RepoStatistici:
    def __init__(self, cale_fisier):
        self.__cale_fisier = cale_fisier
        self.__statistici = []
        self.citeste_din_fisier()

    def adauga_statistica(self, statistica_noua):
        """
        Metoda care adauga o statistica in lista de statistici
        :param statistica_noua: statistica de adaugat
        :return: -, daca nu sunt erori
        :raises RepositoryError, in cazul in care deja exista o statistica cu ace
        """
        statistici = self.get_all()
        if statistici:
            for statistica in statistici:
                if statistica_noua.get_nume() == statistica.get_nume() and statistica_noua.get_an() == statistica.get_an():
                    raise RepositoryError("Nu poate exista aceeasi tara cu acelasi an de mai multe ori")

        self.__statistici.append(statistica_noua)
        self.scrie_in_fisier()

    def get_all(self):
        return self.__statistici

    def citeste_din_fisier(self):
        """
        Metoda care citeste din fisier statisticile si le introduce in lista de statistici
        :return: -
        """
        with open(self.__cale_fisier, "r") as f:
            for linie in f:
                if linie != "":
                    parti = linie.split(",")
                    print(parti)
                    nume = str(parti[0])
                    an = int(parti[1])
                    inflatie = float(parti[2])
                    rate = float(parti[3])
                    populatie = int(parti[4])
                    statistica_noua = Statistica(nume, an, inflatie, rate, populatie)
                    try:
                        self.adauga_statistica(statistica_noua)
                    except RepositoryError:
                        continue

    def scrie_in_fisier(self):
        """
        Metoda care scrie in fisier statisticile
        :return: -
        """
        with open(self.__cale_fisier, "w") as f:
            for statistica in self.get_all():
                f.write(str(statistica)+'\n')

    def reset_repo(self):
        """
        Metoda care reseteaza datele din fisierul cu statistici dar si lista de statisici
        :return: -
        """
        self.__statistici = []
        with open(self.__cale_fisier, "w") as f:
            f.truncate(0)