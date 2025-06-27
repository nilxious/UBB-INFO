class Nota:
    def __init__(self, student_id: int, disciplina_id: int, value: float):
        self.__student_id = student_id
        self.__disciplina_id = disciplina_id
        self.__value = value

    def get_student_id(self):
        return self.__student_id

    def get_disciplina_id(self):
        return self.__disciplina_id

    def get_value(self):
        return self.__value

    def __str__(self):
        return f"{self.__value}"

    def __eq__(self, other):
        if isinstance(other, Nota):
            return (self.__student_id == other.__student_id and
                    self.__disciplina_id == other.__disciplina_id and
                    self.__value == other.__value)
        return False

    def to_file_string(self):
        return f"{self.__student_id}, {self.__disciplina_id}, {self.__value}"