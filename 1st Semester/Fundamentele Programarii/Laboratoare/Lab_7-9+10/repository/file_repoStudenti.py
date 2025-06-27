from domain.student import Student
from repository.repoStudenti import RepoStudenti
import os

class FileRepoStudenti(RepoStudenti):

    def __init__(self, fisier):
        super().__init__()
        self.fisier = fisier
        if not os.path.exists(self.fisier):
            open(self.fisier, "w").close()
        self.__read_all_from_file()

    def __read_all_from_file(self):
        with open(self.fisier, 'r') as file:
            linii = file.readlines()
            self.__studenti = []
            for linie in linii:
                linie = linie.strip()
                if linie != "":
                    parti = linie.split(",")
                    nume = parti[0]
                    id = int(parti[1])
                    student = Student(id, nume)
                    RepoStudenti.adauga_student(self, student)

    def __write_all_to_file(self):
        with open(self.fisier, 'w') as file:
            for student in RepoStudenti.get_all_students(self):
                file.write(student.to_file_string() + '\n')

    def adauga_student(self, student):
        RepoStudenti.adauga_student(self, student)
        self.__write_all_to_file()

    def modifica_nume_student(self, student_id, nume):
        RepoStudenti.modifica_nume_student(self, student_id, nume)
        self.__write_all_to_file()

    def sterge_student(self, student_id):
        RepoStudenti.sterge_student(self, student_id)
        self.__write_all_to_file()

    def cauta_student(self, id):
        return RepoStudenti.cauta_student(self, id)

    def get_all_students(self):
        return RepoStudenti.get_all_students(self)

    def reset(self):
        RepoStudenti.reset(self)