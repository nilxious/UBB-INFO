from errors.errors import ValidationError, RepositoryError

class UI:
    def __init__(self, service):
        self.__service = service

    def print_menu(self):
        print("1. Adauga spectacol: ")
        print("2. Modifica spectacol: ")
        print("3. Genereaza spectacole: ")
        print("4. Exporta spectacole sortate dupa autor si titlu: ")
        print("E. Exit")

    def ui_adauga_spectacol(self, titlu: str, artist: str, gen: str, durata: int):
        try:
            self.__service.add_spectacol(titlu,artist,gen,durata)
            print("Spectacol adaugat!")
        except ValidationError as e:
            print(e)

    def ui_modifica_spectacol(self, titlu: str, artist: str, gen_nou: str, durata_noua: int):
        try:
            self.__service.modify_spectacol(titlu, artist, gen_nou, durata_noua)
            print("Spectacol modificat!")
        except ValidationError as e:
            print(e)
        except RepositoryError as e:
            print(e)

    def ui_genereaza_spectacole(self, numar_de_generat: int):
        print("Spectacole generate:")
        generate = self.__service.generate_spectacole(numar_de_generat)
        for spectacol in generate:
            print(spectacol.string_to_file())

    def ui_exporteaza_spectacole(self, cale_noua):

        filtrate = self.__service.filter_spectacole()

        with open(cale_noua, "w") as f:
            for spectacol in filtrate:
                f.write(spectacol.string_to_export()+'\n')

    def run(self):
        while True:
            self.print_menu()
            command = input("Introduce o comanda: ").strip().upper()
            match command:
                case "1":
                    try:
                        titlu = input("Introduce titlu: ")
                        artist = input("Introduce artist: ")
                        gen = input("Introduce gen: ")
                        durata = int(input("Introduce durata: "))
                        self.ui_adauga_spectacol(titlu, artist, gen, durata)
                    except ValueError as e:
                        print(e)

                case "2":
                    try:
                        titlu = input("Introduce titlul spectacolului pe care vrei sa il modifici: ")
                        artist = input("Introduce artistul spectacolului pe care vrei sa il modifici: ")
                        gen_nou = input("Introduce genul nou al spectacolului: ")
                        durata_noua = int(input("Introduce noua durata a spectacolului: "))
                        self.ui_modifica_spectacol(titlu,artist,gen_nou,durata_noua)
                    except ValueError as e:
                        print(e)

                case "3":
                    try:
                        numar_de_generat = int(input("Introduce numarul de piese pe care vrei sa le generezi aleator: "))
                        if numar_de_generat <=0:
                            raise ValueError("Trebuie sa introduci o valoare strict pozitiva!")
                        self.ui_genereaza_spectacole(numar_de_generat)
                    except ValueError as e:
                        print(e)

                case "4":
                    try:
                        cale_noua = input("Introduce numele fisierului: ")
                        cale_noua = cale_noua+'.txt'
                        self.ui_exporteaza_spectacole(cale_noua)
                    except ValueError as e:
                        print(e)

                case "E":
                    break
