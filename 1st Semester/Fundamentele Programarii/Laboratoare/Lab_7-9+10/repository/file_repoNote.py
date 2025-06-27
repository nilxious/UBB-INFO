from domain.nota import Nota
from repository.repoNote import RepoNote
import os

class FileRepoNote(RepoNote):

    def __init__(self, fisier):
        super().__init__()
        self.fisier = fisier
        if not os.path.exists(self.fisier):
            open(self.fisier, "w").close()
        self.__read_all_from_file()

    def __read_all_from_file(self):
        with open(self.fisier, 'r') as file:
            linii = file.readlines()
            self.__note = []
            for linie in linii:
                linie = linie.strip()
                if linie != "":
                    parti = linie.split(", ")
                    student_id = int(parti[0])
                    disciplina_id = int(parti[1])
                    nota_value = float(parti[2])
                    nota = Nota(student_id, disciplina_id, nota_value)
                    RepoNote.adauga_nota(self, nota)

    def __write_all_to_file(self):
        with open(self.fisier, 'w') as file:
            for nota in RepoNote.get_all_note(self):
                file.write(nota.to_file_string() + '\n')

    def adauga_nota(self, nota):
        RepoNote.adauga_nota(self, nota)
        self.__write_all_to_file()

    def ia_note_student(self, student_id: int, disciplina_id: int):
        return RepoNote.ia_note_student(self, student_id, disciplina_id)

    def reset(self):
        RepoNote.reset(self)
