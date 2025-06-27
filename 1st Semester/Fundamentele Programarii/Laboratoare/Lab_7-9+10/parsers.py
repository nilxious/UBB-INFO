import re
from errors import UserInputError

def stergeSauCautaStudentData(text: list)-> int:
    errors = []

    try:
        student_id = int(text[1][1:])
    except ValueError:
        errors.append("id-ul studentului trebuie sa fie de tip int")

    if len(errors) > 0:
        error_message = ', '.join(errors)
        raise UserInputError(error_message)
    else:
        return student_id

def adaugaStudentData(text: list)-> tuple:
    errors = []

    nume_student = text[1][1:]

    numeSplit = re.split(r'[ -]', nume_student)
    for i in range(len(numeSplit)):
        numeSplit[i] = numeSplit[i].capitalize()
    nume_student = ' '.join(numeSplit)

    try:
        student_id = int(text[2][1:])
    except ValueError:
        errors.append("id-ul studentului trebuie sa fie de tip int")

    if len(errors) > 0:
        error_message = ', '.join(errors)
        raise UserInputError(error_message)
    else:
        return student_id, nume_student

def modificaStudentData(text: list)-> tuple:
    errors = []

    nume_student = text[2][1:]

    numeSplit = re.split(r'[ -]', nume_student)
    for i in range(len(numeSplit)):
        numeSplit[i] = numeSplit[i].capitalize()

    nume_student = ' '.join(numeSplit)

    try:
        student_id = int(text[1][1:])
    except ValueError:
        errors.append("id-ul studentului trebuie sa fie de tip int")

    if len(errors) > 0:
        error_message = ', '.join(errors)
        raise UserInputError(error_message)
    else:
        return student_id, nume_student

def adaugaDisciplinaData(text: list)-> tuple:
    errors = []

    nume_disciplina = text[1][1:].capitalize()

    try:
        disciplina_id = int(text[2][1:])
    except ValueError:
        errors.append("id-ul disciplinei trebuie sa fie de tip int")

    nume_profesor = text[3][1:]
    numeSplit = re.split(r'[ -]', nume_profesor)
    for i in range(len(numeSplit)):
        numeSplit[i] = numeSplit[i].capitalize()
    nume_profesor = ' '.join(numeSplit)

    if len(errors) > 0:
        error_message = ', '.join(errors)
        raise UserInputError(error_message)
    else:
        return nume_disciplina, disciplina_id, nume_profesor

def adaugaNotaData(text: list)-> tuple:
    errors = []

    try:
        student_id = int(text[1][1:])
    except ValueError:
        errors.append("id-ul studentului trebuie sa fie de tip int")

    try:
        disciplina_id = int(text[2][1:])
    except ValueError:
        errors.append("id-ul disciplinei trebuie sa fie de tip int")

    try:

        nota = float(text[3][1:])
    except ValueError:
        errors.append("nota trebuie sa fie de tip float")

    if len(errors) > 0:
        error_message = ', '.join(errors)
        raise UserInputError(error_message)
    else:
        return student_id, disciplina_id, nota

def studentNoteData(text: list)-> tuple:
    errors = []

    try:
        student_id = int(text[1][1:])
    except ValueError:
        errors.append("id-ul studentului trebuie sa fie de tip int")

    try:
        disciplina_id = int(text[2][1:])
    except ValueError:
        errors.append("id-ul disciplinei trebuie sa fie de tip int")

    if len(errors) > 0:
        error_message = ', '.join(errors)
        raise UserInputError(error_message)
    else:
        return student_id, disciplina_id

def cautaDisciplinaData(text: list)-> int:
    errors = []

    try:
        disciplina_id = int(text[1][1:])
    except ValueError:
        errors.append("id-ul disciplinei trebuie sa fie de tip int")

    if len(errors) > 0:
        error_message = ', '.join(errors)
        raise UserInputError(error_message)
    else:
        return disciplina_id

def modificaDisciplinaData(text: list)-> tuple:
    errors = []

    try:
        disciplina_id = int(text[1][1:])
    except ValueError:
        errors.append("id-ul disciplinei trebuie sa fie de tip int")

    nume_disciplina = text[2][1:]

    numeSplit = re.split(r'[ -]', nume_disciplina)
    for i in range(len(numeSplit)):
        numeSplit[i] = numeSplit[i].capitalize()

    nume_disciplina = ' '.join(numeSplit)

    if len(errors) > 0:
        error_message = ', '.join(errors)
        raise UserInputError(error_message)
    else:
        return disciplina_id, nume_disciplina
