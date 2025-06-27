from errors.errors import ValidationError

class ValidatorSpectacol:
    def valideaza(self, spectacol):
        """
        Metoda care valideaza un spectacol
        :param spectacol: spectacolul de validat
        :return: -, daca nu sunt erori
        :raises: ValidationError, daca datele spectacolului nu sunt conforme
        """
        titlu = spectacol.titlu()
        artist = spectacol.artist()
        gen = spectacol.gen()
        durata = spectacol.durata()

        errors = []

        valide = ["Comedie", "Concert", "Balet", "Altele"]

        if titlu.strip() == "":
            errors.append("Titlul trebuie sa fie nevid")

        if artist.strip() == "":
            errors.append("Artistul trebuie sa fie nevid")

        if durata <= 0:
            errors.append("Durata e intreg pozitiv")

        if gen not in valide:
            errors.append("Genul trebuie sa fie una dintre: Comedie, Concert, Balet, Altele")

        if len(errors)>0:
            error_message = '\n'.join(errors)
            raise ValidationError(error_message)
