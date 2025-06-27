import unittest
from controller.serviceStudenti import ServiceStudenti
from controller.serviceDiscipline import ServiceDiscipline
from controller.serviceNote import ServiceNote

from repository.repoStudenti import RepoStudenti
from repository.repoDiscipline import RepoDiscipline
from repository.repoNote import RepoNote

from errors import AddStudentError, ValidationError, RemoveStudentError, AddDisciplineError, RemoveDisciplineError, \
    SearchDisciplineError, SearchStudentError, InvalidGradeError, NoGradesError, NoDisciplineOrStudent
from domain.nota import Nota


class TestService(unittest.TestCase):
    def setUp(self):
        self.repoStudenti = RepoStudenti()
        self.studentService = ServiceStudenti(self.repoStudenti)

        self.repoDiscipline = RepoDiscipline()
        self.disciplineService = ServiceDiscipline(self.repoDiscipline)

        self.repoNote = RepoNote()
        self.noteService = ServiceNote(self.repoNote, self.repoStudenti, self.repoDiscipline)

        self.repoStudenti.reset()
        self.repoDiscipline.reset()
        self.repoNote.reset()

    def test_add_student(self):

        try:
            self.studentService.add_student(10000, "Homorozan Catalin-Stefan")
        except AddStudentError:
            assert False

        try:
            self.studentService.add_student(10000, "Homorozan Catalin-Stefan")
            assert False
        except AddStudentError:
            pass

        try:
            invalid_id = 1234
            self.studentService.add_student(1234, "Lorem Ipsum")
            assert False
        except ValidationError:
            pass

        try:
            nume_invalid = "M4ri2 I0ana"
            self.studentService.add_student(12345, nume_invalid)
            assert False
        except ValidationError:
            pass

    def test_remove_student(self):

        self.studentService.add_student(10000, "Homorozan Catalin-Stefan")

        try:
            self.studentService.remove_student(10000)
        except RemoveStudentError:
            pass

        try:
            self.studentService.remove_student(99999)
            assert False
        except RemoveStudentError:
            pass

        try:
            self.studentService.remove_student(1234)
            assert False
        except ValidationError:
            pass

    def test_add_disciplina(self):

        try:
            self.disciplineService.add_disciplina(1, "Matematica", "Profesor Mate")
        except AddDisciplineError:
            assert False

        try:
            self.disciplineService.add_disciplina(1, "Romana", "Profesor Romana")
            assert False
        except AddDisciplineError:
            pass

        try:
            self.disciplineService.add_disciplina(-2, "Materie", "Profesor Materie")
            assert False
        except ValidationError:
            pass

    def test_remove_disciplina(self):
        self.setUp()

        self.disciplineService.add_disciplina(1, "Matematica", "Profesor Mate")\

        try:
            self.disciplineService.remove_disciplina(1)
        except RemoveDisciplineError:
            assert False

        try:
            self.disciplineService.remove_disciplina(2)
            assert False
        except RemoveDisciplineError:
            pass

        try:
            self.disciplineService.remove_disciplina(-7)
            assert False
        except ValidationError:
            pass

    def test_search_disciplina(self):

        self.disciplineService.add_disciplina(3, "Romana", "Profesor Romana")

        try:
            disciplinaCautata = self.disciplineService.search_disciplina(3)
        except SearchDisciplineError:
            assert False

        try:
            disciplinaCautataInvalida = self.disciplineService.search_disciplina(9)
            assert False
        except SearchDisciplineError:
            pass

        try:
            self.disciplineService.search_disciplina(-2)
            assert False
        except ValidationError:
            pass

    def test_search_student(self):

        self.studentService.add_student(10000, "Homorozan Catalin-Stefan")

        try:
            studentCautat = self.studentService.search_student(10000)
        except SearchStudentError:
            assert False

        try:
            studentCautatInvalid = self.studentService.search_student(99999)
            assert False
        except SearchStudentError:
            pass

        try:
            self.studentService.search_student(1234)
            assert False
        except ValidationError:
            pass

    def test_add_nota(self):

        self.disciplineService.add_disciplina(1, "Matematica", "Profesor Mate")
        self.studentService.add_student(10000, "Homorozan Catalin-Stefan")

        try:
            self.noteService.add_nota(1234, 1, 10)
            assert False
        except ValidationError:
            pass

        try:
            self.noteService.add_nota(10000, 2, 10)
            assert False
        except SearchDisciplineError:
            pass

        try:
            self.noteService.add_nota(10000, 1, 0)
            assert False
        except InvalidGradeError:
            pass

        try:
            self.noteService.add_nota(10000, 1, 11)
            assert False
        except InvalidGradeError:
            pass

        try:
            self.noteService.add_nota(10000, 1, 9)
        except (ValidationError, InvalidGradeError):
            assert False

        found = False
        for nota in self.repoNote.get_all_note():
            if nota.get_student_id() == 10000 and nota.get_disciplina_id() == 1 and nota.get_value() == 9:
                found = True
                break

        assert found

    def test_get_note_student(self):
        self.studentService.add_student(10000, "Homorozan Catalin-Stefan")
        self.studentService.add_student(10001, "Bogdan Andrei")
        self.disciplineService.add_disciplina(1, "Informatica", "Profesor Informatica")
        self.noteService.add_nota(10000, 1, 10)
        self.noteService.add_nota(10000, 1, 9)
        self.noteService.add_nota(10000, 1, 8)

        noteStudent1 = self.noteService.get_note_student(10000, 1)
        assert noteStudent1 == [Nota(10000, 1, 10), Nota(10000, 1, 9), Nota(10000, 1, 8)]

        try:
            noteStudent2 = self.noteService.get_note_student(10001, 1)
            assert False
        except NoGradesError:
            pass

        try:
            noteInvalideLaValidation = self.noteService.get_note_student(1234, 1)
            assert False
        except ValidationError:
            pass

        try:
            noteInvalideLaValidation = self.noteService.get_note_student(10000, -1)
            assert False
        except ValidationError:
            pass

    def test_get_studenti_si_note_alfabetic(self):
        self.studentService.add_student(10000, "Homorozan Catalin-Stefan")
        self.studentService.add_student(10001, "Xenovia Zendaya")
        self.studentService.add_student(10002, "Andrei Bogdan")
        self.disciplineService.add_disciplina(1, "Matematica", "Profesor Mate")
        self.noteService.add_nota(10000, 1, 8)
        self.noteService.add_nota(10001, 1, 3)
        self.noteService.add_nota(10002, 1, 10)

        note_la_disciplina_alfabetic = self.noteService.get_studenti_si_note_alfabetic(1)
        assert note_la_disciplina_alfabetic == [('Andrei Bogdan', 10), ('Homorozan Catalin-Stefan', 8), ('Xenovia Zendaya', 3)]

    def test_get_studenti_si_note_dupaNota(self):
        self.studentService.add_student(10000, "Homorozan Catalin-Stefan")
        self.studentService.add_student(10001, "Xenovia Zendaya")
        self.studentService.add_student(10002, "Andrei Bogdan")
        self.disciplineService.add_disciplina(1, "Matematica", "Profesor Mate")
        self.noteService.add_nota(10000, 1, 8)
        self.noteService.add_nota(10001, 1, 3)
        self.noteService.add_nota(10002, 1, 10)

        note_la_disciplina_dupaNota = self.noteService.get_studenti_si_note_dupaNota(1)
        assert note_la_disciplina_dupaNota == [('Xenovia Zendaya', 3), ('Homorozan Catalin-Stefan', 8), ('Andrei Bogdan', 10)]

    def test_get_statistici(self):
        self.studentService.add_student(10000, "Homorozan Catalin-Stefan")
        self.studentService.add_student(10001, "Xenovia Zendaya")
        self.studentService.add_student(10002, "Andrei Bogdan")
        self.disciplineService.add_disciplina(1, "Matematica", "Profesor Mate")
        self.disciplineService.add_disciplina(2, "Romana", "Profesor Romana")
        self.disciplineService.add_disciplina(3, "Geografie", "Profesor Geografie")


        self.noteService.add_nota(10002, 1, 10)
        self.noteService.add_nota(10002, 2, 10)
        self.noteService.add_nota(10002, 3, 4)
        self.noteService.add_nota(10002, 1, 7)

        self.noteService.add_nota(10001, 1, 7)
        self.noteService.add_nota(10001, 2, 3)
        self.noteService.add_nota(10001, 3, 3)

        self.noteService.add_nota(10000, 1, 5)
        self.noteService.add_nota(10000, 2, 8)
        self.noteService.add_nota(10000, 3, 10)

        statisticiExpected = [('Xenovia Zendaya', 4.333333333333333)]
        assert statisticiExpected == self.noteService.get_statistici()

    def test_modify_student(self):
        self.studentService.add_student(10000, "Homorozan Catalin-Stefan")
        student = self.studentService.search_student(10000)

        self.studentService.modify_student_name(10000, "Scarlatescu Mihai")
        assert(student.get_nume() == "Scarlatescu Mihai")

        try:
            self.studentService.modify_student_name(10000, "Num3 Inval1d")
            assert False
        except ValidationError:
            pass

        try:
            self.studentService.modify_student_name(10001, "Bogdan Andrei")
            assert False
        except SearchStudentError:
            pass

    def test_modify_disciplina_nume(self):
        self.disciplineService.add_disciplina(1, "Informatica", "Profesor Informatica")

        disciplina = self.disciplineService.search_disciplina(1)

        self.disciplineService.modify_disciplina_nume(1, "Fundamentele Programarii")
        assert(disciplina.get_nume() == "Fundamentele Programarii")

        try:
            self.disciplineService.modify_disciplina_nume(2, "Something")
            assert False
        except SearchDisciplineError:
            pass

    def test_modify_disciplina_nume_profesor(self):
        self.disciplineService.add_disciplina(1, "Informatica", "Profesor Informatica")

        disciplina = self.disciplineService.search_disciplina(1)

        self.disciplineService.modify_disciplina_nume_profesor(1, "Profesor Informatica Nou")
        assert(disciplina.get_profesor() == "Profesor Informatica Nou")

        try:
            self.disciplineService.modify_disciplina_nume_profesor(2, "Marian Popescu")
            assert False
        except SearchDisciplineError:
            pass

    def test_get_statistici_invers(self):
        self.studentService.add_student(10000, "Homorozan Catalin-Stefan")
        self.studentService.add_student(10001, "Xenovia Zendaya")
        self.studentService.add_student(10002, "Andrei Bogdan")
        self.disciplineService.add_disciplina(1, "Matematica", "Profesor Mate")
        self.disciplineService.add_disciplina(2, "Romana", "Profesor Romana")
        self.disciplineService.add_disciplina(3, "Geografie", "Profesor Geografie")
        self.disciplineService.add_disciplina(4, "Informatica", "Profesor Informatica")
        self.disciplineService.add_disciplina(5, "Engleza", "Profesor Engleza")
        self.disciplineService.add_disciplina(6, "ASC", "Profesor ASC")
        self.disciplineService.add_disciplina(7, "Analiza Matematica", "Profesor Analiza")
        self.disciplineService.add_disciplina(8, "Algebra", "Profesor Algebra")
        self.disciplineService.add_disciplina(9, "Geometrie", "Profesor Geometrie")
        self.disciplineService.add_disciplina(10, "Istorie", "Profesor Istorie")

        self.noteService.add_nota(10002, 1, 10)
        self.noteService.add_nota(10002, 1, 9)
        self.noteService.add_nota(10001, 1, 7)
        self.noteService.add_nota(10000, 1, 5)

        self.noteService.add_nota(10001, 2, 3)
        self.noteService.add_nota(10002, 2, 8)
        self.noteService.add_nota(10000, 2, 10)

        self.noteService.add_nota(10001, 3, 6)
        self.noteService.add_nota(10002, 3, 4)
        self.noteService.add_nota(10000, 3, 5)

        self.noteService.add_nota(10001, 4, 1)
        self.noteService.add_nota(10002, 4, 4)
        self.noteService.add_nota(10002, 4, 9)
        self.noteService.add_nota(10000, 4, 10)

        self.noteService.add_nota(10001, 5, 10)
        self.noteService.add_nota(10002, 5, 10)
        self.noteService.add_nota(10000, 5, 10)
        self.noteService.add_nota(10000, 5, 10)

        self.noteService.add_nota(10001, 6, 5)
        self.noteService.add_nota(10002, 6, 5)
        self.noteService.add_nota(10000, 6, 5)

        self.noteService.add_nota(10001, 7, 6)
        self.noteService.add_nota(10002, 7, 8)
        self.noteService.add_nota(10000, 7, 1)

        self.noteService.add_nota(10001, 8, 9)
        self.noteService.add_nota(10002, 8, 7)
        self.noteService.add_nota(10000, 8, 9)

        self.noteService.add_nota(10001, 9, 1)
        self.noteService.add_nota(10002, 9, 1)
        self.noteService.add_nota(10000, 9, 1)

        self.noteService.add_nota(10001, 10, 2)
        self.noteService.add_nota(10002, 10, 2)
        self.noteService.add_nota(10000, 10, 2)

        expectedResult = [('Geometrie', 1.0), ('Istorie', 2.0)]
        assert self.noteService.get_statistici_invers() == expectedResult


def run_tests_service():
    suite = unittest.TestLoader().loadTestsFromTestCase(TestService)
    runner = unittest.TextTestRunner()
    result = runner.run(suite)
    if result.wasSuccessful():
        print("Testele din service au mers")
    else:
        print("Niste teste din service au crapat")

"""def run_tests_service():
    test_service = TestService()

    test_service.test_add_student()
    test_service.test_remove_student()
    test_service.test_search_student()
    test_service.test_add_disciplina()
    test_service.test_remove_disciplina()
    test_service.test_search_disciplina()
    test_service.test_add_nota()
    test_service.test_get_note_student()
    test_service.test_get_studenti_si_note_alfabetic()
    test_service.test_get_studenti_si_note_dupaNota()
    test_service.test_get_statistici()
    test_service.test_modify_student()
    test_service.test_modify_disciplina_nume()
    test_service.test_modify_disciplina_nume_profesor()
    test_service.test_get_statistici_invers()

    print("testele din service au mers")"""