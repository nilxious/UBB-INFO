from errors import ValidationError

class ValidatorDisciplina:
    def valideaza(self, disciplina):
        """
        Valideaza o disciplina data
        :param disciplina: disciplina de validat
        :return: -
        :raises: ValidationError cu mesajele de eroare daca disciplina nu este valida
        """
        errors = []
        idDisciplina = disciplina.get_id()

        if idDisciplina < 0:
            errors.append("ID-ul disciplinei nu poate fi negativ")

        if len(errors) > 0:
            error_message = '\n'.join(errors)
            raise ValidationError(error_message)