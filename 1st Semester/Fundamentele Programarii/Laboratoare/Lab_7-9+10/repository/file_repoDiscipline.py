from domain.disciplina import Disciplina
import os
from repository.repoDiscipline import RepoDiscipline

class FileRepoDiscipline(RepoDiscipline):

    def __init__(self, fisier):
        super().__init__()
        self.fisier = fisier
        if not os.path.exists(self.fisier):
            open(self.fisier, "w").close()
        self.__read_all_from_file()

    def __read_all_from_file(self):
        with open(self.fisier, 'r') as file:
            linii = file.readlines()
            self.__discipline = []
            for linie in linii:
                linie = linie.strip()
                if linie != "":
                    parti = linie.split(", ")
                    nume_disciplina = parti[0]
                    id = int(parti[1])
                    nume_profesor = parti[2]
                    disciplina = Disciplina(id, nume_disciplina, nume_profesor)
                    RepoDiscipline.adauga_disciplina(self, disciplina)
                    #self.adauga_disciplina(disciplina)

    def __write_all_to_file(self):
        with open(self.fisier, 'w') as file:
            for disciplina in RepoDiscipline.get_all_disciplines(self):
                file.write(disciplina.to_file_string() + '\n')

    def adauga_disciplina(self, disciplina):
        RepoDiscipline.adauga_disciplina(self, disciplina)
        self.__write_all_to_file()

    def modifica_nume_disciplina(self, disciplina_id, nume_disciplina_noua):
        RepoDiscipline.modifica_nume_disciplina(self, disciplina_id, nume_disciplina_noua)
        self.__write_all_to_file()

    def modifica_nume_profesor_disciplina(self, disciplina_id, nume_profesor_nou):
        RepoDiscipline.modifica_nume_profesor_disciplina(self, disciplina_id, nume_profesor_nou)
        self.__write_all_to_file()

    def sterge_disciplina(self, disciplina_id):
        RepoDiscipline.sterge_disciplina(self, disciplina_id)
        self.__write_all_to_file()

    def cauta_disciplina(self, disciplina_id):
        return RepoDiscipline.cauta_disciplina(self, disciplina_id)

    def get_all_disciplines(self):
        return RepoDiscipline.get_all_disciplines(self)

    def reset(self):
        RepoDiscipline.reset(self)