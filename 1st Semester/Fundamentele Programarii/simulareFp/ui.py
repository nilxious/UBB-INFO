from errors.errors import ValidationError, RepositoryError

class Ui:
    def __init__(self, service):
        self.__service = service


    def ui_adauga_statistica(self, nume: str, an: int, inflatie: float, rate: float, populatie: float):
        try:
            self.__service.add_statistica(nume, an, inflatie, rate, populatie)
        except ValidationError as e:
            print(e)
        except RepositoryError as e:
            print(e)

    def print_menu(self):
        print("1. Adaugare statistica")
        print("2. Toate tarile care au rata medie de inflatie mai mica decat un numar citit + nr.maxim de someri pentru perioada inregistrata")
        print("3. Exit")

    def run(self):
        while True:
            self.print_menu()
            comanda = input("Introduceti o comanda: ").strip().lower()
            if comanda == "1":
                try:
                    nume = input("Introduceti o tara: ")
                    an = int(input("Introduceti un an: "))
                    inflatie = float(input("Introduceti o rata de inflatie: "))
                    rate = float(input("Introduceti o rata de somaj: "))
                    populatie = int(input("Introduceti numarul populatiei: "))
                    self.ui_adauga_statistica(nume, an, inflatie, rate, populatie)
                except ValueError as e:
                    print(e)

            elif comanda == "2":
                pass
            elif comanda == "3":
                print("Exiting...")
                break
