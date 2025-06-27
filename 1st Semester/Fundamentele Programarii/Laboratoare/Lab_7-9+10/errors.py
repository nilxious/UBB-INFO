class CustomError(Exception):
    def __init__(self, message):
        self.__message = message
        super().__init__(self.__message)

class AddStudentError(CustomError):
    pass

class RemoveStudentError(CustomError):
    pass

class AddDisciplineError(CustomError):
    pass

class ValidationError(CustomError):
    pass

class SearchStudentError(CustomError):
    pass

class SearchDisciplineError(CustomError):
    pass

class NoGradesError(CustomError):
    pass

class InvalidGradeError(CustomError):
    pass

class RemoveDisciplineError(CustomError):
    pass

class NoStatisticsError(CustomError):
    pass

class NoDisciplineOrStudent(CustomError):
    pass

class UserInputError(CustomError):
    pass