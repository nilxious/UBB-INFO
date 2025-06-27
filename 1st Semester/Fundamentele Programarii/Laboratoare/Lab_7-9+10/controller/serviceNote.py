from domain.nota import Nota
from domain.student import Student
from domain.disciplina import Disciplina
from validare.validare_disciplina import ValidatorDisciplina
from validare.validare_student import ValidatorStudent
from errors import InvalidGradeError, NoGradesError, NoStatisticsError

class ServiceNote(object):
    def __init__(self, repoNote, repoStudenti, repoDiscipline):
        self.__repoNote = repoNote
        self.__repoStudenti = repoStudenti
        self.__repoDiscipline = repoDiscipline

    def add_nota(self, student_id: int, disciplina_id: int, value: float):
        """
        Metoda care creeaza o nota a unui student la o disciplina iar apoi o adauga in baza de date (Facultatea)
        :param student_id: int, id-ul studentului
        :param disciplina_id: int, id-ul disciplinei
        :param value: float, nota studentului la disciplina
        :return: -, daca datele sunt valide
        :raises: ValidationError, daca id-ul disciplinei este negativ si/sau daca id-ul studentului nu are exact 5 cifre sau este negativ,
        sau daca numele acestuia are caractere diferite de literele alfabetului si de caracterul "-"
                 InvalidGradeError, daca nota nu este in intervalul [1, 10]
        """
        nota = Nota(student_id, disciplina_id, value)

        ValidatorStudent().valideaza(Student(student_id, "Lorem ipsum"))

        ValidatorDisciplina().valideaza(Disciplina(disciplina_id, "Lorem ipsum", "Lorem ipsum"))

        if not 1 <= value <= 10:
             raise InvalidGradeError("Nota trebuie sa ia valori intre 1 si 10")

        student = self.__repoStudenti.cauta_student(nota.get_student_id())

        disciplina = self.__repoDiscipline.cauta_disciplina(nota.get_disciplina_id())

        self.__repoNote.adauga_nota(nota)

    def get_note_student(self, student_id: int, disciplina_id: int):
        """
        Metoda care creeaza o lista cu notele unui student cu id-ul student_id la o disciplina cu id-ul disciplina_id, iar apoi o returneaza
        :param student_id: int, id-ul studentului
        :param disciplina_id: int, id-ul disciplinei
        :return: lista cu notele unui student la o disciplina, daca datele sunt valide
        :raises: ValidationError, daca id-ul disciplinei este negativ si/sau daca id-ul studentului nu are exact 5 cifre sau este negativ
        """
        ValidatorStudent().valideaza(Student(student_id, "Lorem ipsum"))

        ValidatorDisciplina().valideaza(Disciplina(disciplina_id, "Lorem ipsum", "Lorem ipsum"))

        self.__repoDiscipline.cauta_disciplina(disciplina_id)

        self.__repoStudenti.cauta_student(student_id)

        return self.__repoNote.ia_note_student(student_id, disciplina_id)

    #def get_nume_tuplu(self, tuplu: tuple):
    #   """
    #   Metoda care ia numele studentului dintr-un tuplu
    #   :param tuplu: tuple, ce contine numele si nota studentului la o disciplina (string, float)
    #   :return: string, numele studentului
    #   """
    #    return tuplu[0]

    #def get_nota_tuplu(self, tuplu: tuple):
    #   """
    #   Metoda care ia nota studentului dintr-un tuplu
    #   :param tuplu: tuple, ce contine numele si nota studentului la o disciplina (string, float)
    #   :return: float, nota studentului
    #   """
    #   return tuplu[1]

    def bubble_sort(self, lista: list, key=lambda x: x, reverse=False):
        """
        Metoda care sorteaza o lista conform metodei bubble sort
        :param lista: lista cu notele si numele studentilor
        :param key: functie cu care comparam
        :param reverse: bool, True/False
        :return: lista sortata
        """
        n = len(lista)
        for j in range(1, n):
            for i in range(n - j):
                if reverse:
                    if key(lista[i]) < key(lista[i + 1]):
                        lista[i], lista[i + 1] = lista[i + 1], lista[i]
                else:
                    if key(lista[i]) > key(lista[i + 1]):
                        lista[i], lista[i + 1] = lista[i + 1], lista[i]
        return lista

    def shell_sort(self, lista, key=lambda x: x, reverse=False):
        """
        Metoda care sorteaza o lista utilizand metoda shell sort
        :param lista: list
        :param key: functie cu care comparam
        :param reverse: bool, True/False
        :return: lista sortata
        """
        n = len(lista)
        gap = n // 2

        while gap > 0:
            for i in range(gap, n):
                temp = lista[i]
                j = i
                if reverse:
                    while j >= gap and key(lista[j - gap]) < key(temp):
                        lista[j] = lista[j - gap]
                        j -= gap
                else:
                    while j >= gap and key(lista[j - gap]) > key(temp):
                        lista[j] = lista[j - gap]
                        j -= gap
                lista[j] = temp
            gap //= 2

        return lista

    def get_studenti_si_note_alfabetic(self, disciplina_id: int):
        """
        Metoda care creeaza si returneaza o lista cu numele si noteles tudentilor la o disciplina, ordonata alfabetic dupa nume
        :param disciplina_id: id, id-ul disciplinei
        :return: lista de studenți și notele lor la o disciplină dată, ordonat alfabetic după nume, daca datele sunt valide sau nu sunt erori
        :raises: ValidationError, daca id-ul disciplinei este negativ
                 NoStatisticError, daca nici un student nu are o nota la disciplina cu id-ul disciplina_id
        """
        Statistici1 = []

        ValidatorDisciplina().valideaza(Disciplina(disciplina_id, "Lorem ipsum", "Lorem ipsum"))

        for student in self.__repoStudenti.get_all_students():
            try:
                note = self.get_note_student(student.get_id(), disciplina_id)
                for nota in note:
                    Statistici1.append((student.get_nume(), nota.get_value()))
            except NoGradesError:
                continue

        self.bubble_sort(Statistici1, key=lambda x: x[0], reverse=False)

        if Statistici1:
            return Statistici1
        else:
            raise NoStatisticsError("Nu exista nici un student cu o nota la aceasta disciplina")

    def get_studenti_si_note_dupaNota(self, disciplina_id: int):
        """
        Metoda care creeaza si returneaza o lista de note cu notele studentilor la o disciplina, ordonata crescator dupa note
        :param disciplina_id: id, id-ul disciplinei
        :return: lista de studenți și notele lor la o disciplină dată, ordonat după notă, daca datele sunt valide sau nu sunt erori
        :raises: ValidationError, daca id-ul disciplinei este negativ
                 NoStatisticError, daca nici un student nu are o nota la disciplina cu id-ul disciplina_id
        """
        Statistici2 = []

        ValidatorDisciplina().valideaza(Disciplina(disciplina_id, "Lorem ipsum", "Lorem ipsum"))

        for student in self.__repoStudenti.get_all_students():
            try:
                note = self.get_note_student(student.get_id(), disciplina_id)
                for nota in note:
                    Statistici2.append((student.get_nume(), nota.get_value()))
            except NoGradesError:
                continue

        self.shell_sort(Statistici2, key=lambda x: x[1], reverse=False)

        if Statistici2:
            return Statistici2
        else:
            raise NoStatisticsError("Nu exista nici un student cu o nota la aceasta disciplina")

    def calculeaza_media_la_discipline(self, student_id: id):
        """
        Metoda care calculeaza media la toate discipline a unui studentul
        :param student_id: id-ul studentului, tip int
        :return: Media de tip float, in cazul in care studentul are note, None in cazul in care studentul nu are note
        """
        lista_discipline = self.__repoDiscipline.get_all_disciplines()
        total_note = 0
        sumaNoteDiscipline = 0
        for disciplina in lista_discipline:
            try:
                note = self.get_note_student(student_id, disciplina.get_id())

                for nota in note:
                    sumaNoteDiscipline += nota.get_value()
                    total_note += 1
            except NoGradesError:
                continue

        if total_note != 0:
            media = sumaNoteDiscipline/total_note
        else:
            media = None

        return media

    def calculeaza_media_la_studenti_la_o_disciplina(self, disciplina_id: id):
        lista_studenti = self.__repoStudenti.get_all_students()

        sumaNote = 0
        nrNote = 0

        for student in lista_studenti:
            try:
                note = self.get_note_student(student.get_id(), disciplina_id)
                for nota in note:
                    sumaNote = sumaNote + nota.get_value()
                    nrNote = nrNote + 1
            except NoGradesError:
                continue

        if nrNote != 0:
            media = sumaNote/nrNote
        else:
            media = None

        return media

    def get_statistici(self):
        """
        Metoda care creeaza si returneaza o lista de medii cu primele 20% din mediile studentilor la toate disciplinele, ordonata crescator dupa medii
        :return: lista de studenți și notele lor la o disciplină dată, ordonat după notă, daca datele sunt valide sau nu sunt erori
        :raises: NoStatisticError, daca nici un student nu are o nota la vreo disciplina
        """
        Statistici3 = []

        lista_studenti = self.__repoStudenti.get_all_students()

        if len(lista_studenti) <= 0:
            raise NoStatisticsError("Nu exista nici un student")
        else:
            for student in lista_studenti:
                media = self.calculeaza_media_la_discipline(student.get_id())
                if media is not None:
                    Statistici3.append((student.get_nume(), media))

        self.bubble_sort(Statistici3, key=lambda x: x[1], reverse=False)

        if Statistici3:
            if len(lista_studenti) <= 5:
                return Statistici3[:1]
            else:
                primii_20lasuta = len(Statistici3)//5
                return Statistici3[:primii_20lasuta]
        else:
            raise NoStatisticsError("Nu exista nici un student cu o nota la nici o disciplina")

    def get_statistici_invers(self):
        """
        Metoda care creeaza si returneaza o lista cu primele 20% de discipline si mediile acestora, ordonata crescator dupa medii
        :return: lista de discipline și media ei luand in calcul toti studentii, ordonat după medie, daca datele sunt valide sau nu sunt erori
        :raises: NoStatisticError, daca nici o disciplina nu are note
        """
        Statistici4 = []

        lista_discipline = self.__repoDiscipline.get_all_disciplines()

        if len(lista_discipline) <= 0:
            raise NoStatisticsError("Nu exista nici o disciplina")
        else:
            for disciplina in lista_discipline:
                media = self.calculeaza_media_la_studenti_la_o_disciplina(disciplina.get_id())
                if media is not None:
                    Statistici4.append((disciplina.get_nume(), media))

        self.shell_sort(Statistici4, key=lambda x: x[1], reverse=False)

        if Statistici4:
            if len(lista_discipline) <= 5:
                return Statistici4[:1]
            else:
                primii_20lasuta = len(Statistici4)//5
                return Statistici4[:primii_20lasuta]
        else:
            raise NoStatisticsError("Nu exista nici o disciplina cu note")
