from errors.errors import ValidationError

class ValidatorStatistica:
    def valideaza(self, statistica):
        errors = []

        if statistica.get_inflatie() > 100 or statistica.get_rate() > 100:
            errors.append("Inflatia si/sau rata somajului nu sunt valide")

        if statistica.get_populatie() < 0:
            errors.append("Populatia nu poate fi un numar negativ")

        if len(errors)>0:
            mesaj = ""
            for string in errors:
                mesaj = mesaj.join(string + ",")
            raise ValidationError(mesaj)