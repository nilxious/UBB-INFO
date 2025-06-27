from errors import ValidationError
import re

class ValidatorStudent:
    def valideaza(self, student):
        """
         Valideaza un student dat
         :param student: stundetul de validat
         :return: -
         :raises: ValueError cu mesajele de eroare daca melodia nu este valida
         """
        pattern = "^[a-zA-Z -]*$"
        errors = []
        cnp = student.get_id()
        nume = student.get_nume()
        if not re.match(pattern, nume):
            errors.append("Numele contine caractere invalide")
        if nume.isspace():
            errors.append("Numele este gol")
        if cnp < 0 :
            errors.append("ID-ul studentului nu poate fi negativ")
        if len(str(cnp)) != 5:
            errors.append("ID-ul studentului trebuie sa contina 5 cifre")

        if len(errors) > 0:
            error_message = ','.join(errors)
            raise ValidationError(error_message)