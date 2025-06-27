import unittest
from domain.student import Student
from domain.disciplina import Disciplina
from domain.nota import Nota
from errors import (AddStudentError, AddDisciplineError, RemoveStudentError, SearchDisciplineError,
                        RemoveDisciplineError, SearchStudentError, NoGradesError)


from repository.repoStudenti import RepoStudenti
from repository.repoDiscipline import RepoDiscipline
from repository.repoNote import RepoNote

class TestRepository(unittest.TestCase):

    def setUp(self):
        self.studenti = RepoStudenti()
        self.discipline = RepoDiscipline()
        self.note = RepoNote()

        self.student1 = Student(10000, "Bob Marin")
        self.student2 = Student(10001, "Ioan Andrei")
        self.disciplina1 = Disciplina(1, "Matematica", "Profesor Mate")
        self.nota_valida2 = Nota(10000, 1, 8)
        self.nota_valida = Nota(10000, 1, 7)
        self.nota_invalida_student = Nota(99999, 1, 7)
        self.nota_invalida_disciplina = Nota(10000, 99999, 10)

    def test_adauga_student(self):
        self.studenti.adauga_student(self.student1)
        assert self.student1 in self.studenti.get_all_students()

        try:
            self.studenti.adauga_student(self.student1)
            assert False
        except AddStudentError:
            pass

    def test_sterge_student(self):
        self.studenti.adauga_student(self.student1)
        self.studenti.sterge_student(self.student1.get_id())
        assert self.student1 not in self.studenti.get_all_students()

        try:
            self.studenti.sterge_student(99999)
            assert False
        except RemoveStudentError:
            pass

    def test_cauta_student(self):
        self.studenti.adauga_student(self.student1)
        result = self.studenti.cauta_student(self.student1.get_id())
        assert result == self.student1

        try:
            self.studenti.cauta_student(99999)
            assert False
        except SearchStudentError:
            pass

    def test_adauga_disciplina(self):
        self.discipline.adauga_disciplina(self.disciplina1)
        assert self.disciplina1 in self.discipline.get_all_disciplines()

        try:
            self.discipline.adauga_disciplina(self.disciplina1)
            assert False
        except AddDisciplineError:
            pass

    def test_sterge_disciplina(self):
        self.discipline.adauga_disciplina(self.disciplina1)
        self.discipline.sterge_disciplina(self.disciplina1.get_id())
        assert self.disciplina1 not in self.discipline.get_all_disciplines()

        try:
            self.discipline.sterge_disciplina(9)
            assert False
        except RemoveDisciplineError:
            pass

    def test_cauta_disciplina(self):
        self.discipline.adauga_disciplina(self.disciplina1)

        result = self.discipline.cauta_disciplina(self.disciplina1.get_id())
        assert result == self.disciplina1

        try:
            self.discipline.cauta_disciplina(999)
            assert False
        except SearchDisciplineError:
            pass

    def test_adauga_nota(self):
        self.studenti.adauga_student(self.student1)
        self.discipline.adauga_disciplina(self.disciplina1)

        self.note.adauga_nota(self.nota_valida)
        assert self.nota_valida in self.note.get_all_note()

    def test_ia_note_student(self):
        self.studenti.adauga_student(self.student1)
        self.studenti.adauga_student(self.student2)
        self.discipline.adauga_disciplina(self.disciplina1)
        self.note.adauga_nota(self.nota_valida)
        self.note.adauga_nota(self.nota_valida2)

        note = self.note.ia_note_student(self.student1.get_id(), self.disciplina1.get_id())
        assert note == [self.nota_valida, self.nota_valida2]

        try:
            self.note.ia_note_student(self.student2.get_id(), self.disciplina1.get_id())
            assert False
        except NoGradesError:
            pass

    def test_modifica_nume_student(self):
        self.studenti.adauga_student(self.student1)

        self.studenti.modifica_nume_student(self.student1.get_id(), "Scarlatescu Mihai")
        assert self.student1.get_nume() == "Scarlatescu Mihai"

    def test_modifica_nume_disciplina(self):
        self.discipline.adauga_disciplina(self.disciplina1)

        self.discipline.modifica_nume_disciplina(self.disciplina1.get_id(), "Chineza")
        assert self.disciplina1.get_nume() == "Chineza"

    def test_modifica_nume_profesor_disciplina(self):
        self.discipline.adauga_disciplina(self.disciplina1)

        self.discipline.modifica_nume_profesor_disciplina(self.disciplina1.get_id(), "Profesor Nou")
        assert self.disciplina1.get_profesor() == "Profesor Nou"

def run_tests_repository():
    suite = unittest.TestLoader().loadTestsFromTestCase(TestRepository)
    runner = unittest.TextTestRunner()
    result = runner.run(suite)
    if result.wasSuccessful():
        print("Testele din repo au mers")
    else:
        print("Niste teste din repo au crapat")

"""def run_tests_repository():
    test_repo = TestRepository()

    test_repo.test_adauga_student()
    test_repo.test_sterge_student()
    test_repo.test_cauta_student()
    test_repo.test_adauga_disciplina()
    test_repo.test_sterge_disciplina()
    test_repo.test_cauta_disciplina()
    test_repo.test_adauga_nota()
    test_repo.test_ia_note_student()
    test_repo.test_modifica_nume_student()
    test_repo.test_modifica_nume_disciplina()
    test_repo.test_modifica_nume_profesor_disciplina()

    print("testele din repository au mers")"""


