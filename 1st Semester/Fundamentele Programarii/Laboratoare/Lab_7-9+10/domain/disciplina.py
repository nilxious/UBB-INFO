class Disciplina:
    def __init__(self, id: int, nume: str, profesor: str):
        self.__id = id
        self.__nume = nume
        self.__profesor = profesor

    def get_id(self):
        return self.__id

    def get_nume(self):
        return self.__nume

    def get_profesor(self):
        return self.__profesor

    def set_nume(self, nume: str):
        self.__nume = nume

    def set_nume_profesor(self, nume_profesor: str):
        self.__profesor = nume_profesor

    def __str__(self):
        return f"Nume: {self.__nume}, ID: {self.__id}, Profesor: {self.__profesor}"

    def to_file_string(self):
        return f"{self.__nume}, {self.__id}, {self.__profesor}"