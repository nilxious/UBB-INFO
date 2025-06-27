from domain.spectacol import Spectacol
from errors.errors import RepositoryError

class RepositorySpectacole:
    def __init__(self, cale_fisier):
        self.__spectacole = []
        self.__cale_fisier = cale_fisier
        self.citeste_din_fisier()

    def citeste_din_fisier(self):
        """
        Metoda care citeste din fisier spectacolele si le adauga in baza de date
        :return: -
        """
        with open(self.__cale_fisier, "r") as f:
            for linie in f:
                linie = linie.strip()
                if linie != "":
                    parti = linie.split(",")
                    titlu = parti[0]
                    artist = parti[1]
                    gen = parti[2]
                    durata = int(parti[3])
                    spectacol = Spectacol(titlu,artist,gen,durata)
                    self.__spectacole.append(spectacol)

    def scrie_in_fisier(self):
        """
        Metoda care scrie in fisier baza de date
        :return: -
        """
        spectacole = self.ia_all()
        with open(self.__cale_fisier, "w") as f:
            for spectacol in spectacole:
                f.write(spectacol.string_to_file()+'\n')

    def adauga_spectacol(self, spectacol_nou):
        """
        Metoda care adauga un spectacol nou in lista de spectacole, afisand schmbarea in fisier
        :param spectacol_nou: spectacolul nou, tip Spectacol
        :return: -
        """
        self.__spectacole.append(spectacol_nou)
        self.scrie_in_fisier()

    def modifica_spectacol(self, titlu, artist, gen_nou, durata_noua):
        """
        Metoda care modifica genul si durata unui spectacol
        :param titlu: titlul spectacolului de modificat, tip string
        :param artist: artistul spectacolului de modificat, tip string
        :param gen_nou: genul nou al spectacolului de modificat, tip string
        :param durata_noua: durata noua a spectacolului de modificat, tip int
        :return: -, daca nu sunt erori
        :raises: RepositoryError, daca nu exista un spectacol cu titlul si artistul specificat
        """
        spectacole = self.ia_all()
        modificat = False
        for spectacol in spectacole:
            if spectacol.titlu() == titlu and spectacol.artist() == artist:
                spectacol.set_gen(gen_nou)
                spectacol.set_durata(durata_noua)
                self.scrie_in_fisier()
                modificat = True

        if not modificat:
            raise RepositoryError("Nu exista spectacol cu acest titlu si artist")


    def ia_all(self):
        """
        Metoda care returneaza lista de spectacole
        :return: lista de spectacole
        """
        return self.__spectacole

    def reset(self):
        """
        Metoda care reseteaza baza de date
        :return: -
        """
        with open(self.__cale_fisier, "w") as f:
            f.write("")
        self.__spectacole = []