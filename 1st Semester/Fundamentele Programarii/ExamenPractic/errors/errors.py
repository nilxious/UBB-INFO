class CustomError(Exception):
    pass

class RepositoryError(CustomError):
    """
    Eroare pentru repository
    """
    pass

class ValidationError(CustomError):
    """
    Eroare pentru service/validare
    """
    pass