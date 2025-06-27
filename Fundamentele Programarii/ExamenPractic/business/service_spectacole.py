from domain.spectacol import Spectacol
import random

class ServiceSpectacole:
    def __init__(self, repo, validator):
        self.__repo = repo
        self.__validator = validator

    def add_spectacol(self, titlu: str, artist: str, gen: str, durata: int):
        """
        Metoda care valideaza si adauga un spectacol la baza de date
        :param titlu: titlul spectacolului, tip str
        :param artist: artistul spectacolului, tip str
        :param gen: genul spectacolului, tip str
        :param durata: durata spectacolului, tip int
        :return: -, daca nu sunt erori
        :raises: ValidationError, daca titlul/artistul/genul/durata nu sunt conforme
        """
        spectacol_fictiv = Spectacol(titlu,artist,gen,durata)

        self.__validator.valideaza(spectacol_fictiv)

        self.__repo.adauga_spectacol(spectacol_fictiv)

    def modify_spectacol(self, titlu: str, artist: str, gen_nou: str, durata_noua: int):
        """
        Metoda care modifica un spectacol
        :param titlu: titlul spectacolului care o sa fie modificat, tip string
        :param artist: artistul spectacolului care o sa fie modificat, tip string
        :param gen_nou: genul nou al spectacolului, tip string
        :param durata_noua: durata noua a spectacolului, tip int
        :return: -, daca nu sunt erorir
        :raises: ValidationError, daca genul nou si/sau durata_noua nu sunt conforme
        """
        spectacol_fictiv = Spectacol("Titlu", "Artist", gen_nou, durata_noua)

        self.__validator.valideaza(spectacol_fictiv)

        self.__repo.modifica_spectacol(titlu, artist, gen_nou, durata_noua)

    def generate_spectacole(self, numar_de_spectacole: int):
        """
        Metoda care genereaza spectacole aleator
        :param numar_de_spectacole: numarul de spectacole generate, tip int
        :return: lista de spectacole generate
        """
        vocale = "aeiou"
        consoane = "zqxwcdvfrbgtnhmjklp"
        spectacole_generate = []

        def generate_string(string_de_generat):
            """
            Functie care genereaza un string dupa un anumit format
            :param string_de_generat: lista care contine caracterele generate ale string-ului generat
            :return: string-ul generat
            """
            i = -1
            lungime = random.randint(9,11) - 1
            while len(string_de_generat) < lungime:
                if i == -1:
                    choice = random.choices(consoane, k=1)
                    string_de_generat.append(choice[0])
                    i *= -1
                if i == 1:
                    choice = random.choices(vocale, k=1)
                    string_de_generat.append(choice[0])
                    i *= -1
            mijloc = lungime//2
            string_de_generat = string_de_generat[:mijloc] + [' '] + string_de_generat[mijloc:]
            string_actual = ""
            for el in string_de_generat:
                string_actual = string_actual+el
            return string_actual

        for i in range(0,numar_de_spectacole):
            titlu_generat = generate_string([])
            artist_generat = generate_string([])
            durata = random.randint(1800, 7200)
            genuri = ["Comedie", "Concert", "Balet", "Altele"]
            gen = random.choices(genuri, k=1)
            spectacol_generat = Spectacol(titlu_generat, artist_generat, gen[0], durata)
            spectacole_generate.append(spectacol_generat)
            self.__repo.adauga_spectacol(spectacol_generat)

        return spectacole_generate

    def filter_spectacole(self):
        """
        Metoda care exporteaza spectacolele sortate dupa artist si titlu in alt fisier
        :param cale_noua: numele fisierului in care vor fi exportate, tip string
        :return: -,
        """
        spectacole = self.get_all()

        filtrate = sorted(spectacole, key = lambda x: (x.artist(), x.titlu()), reverse = False)

        return filtrate

    def get_all(self):
        """
        Metoda care returneaza lista de spectacole
        :return: lista de spectacole
        """
        return self.__repo.ia_all()