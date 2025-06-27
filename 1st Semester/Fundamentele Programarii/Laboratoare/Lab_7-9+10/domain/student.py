class Student:
    def __init__(self, id: int, nume: str):
        self.__id = id
        self.__nume = nume

    def get_id(self):
        return self.__id

    def get_nume(self):
        return self.__nume

    def set_nume(self, nume: str):
        self.__nume = nume

    def __str__(self):
        return f"Nume: {self.__nume}, ID: {self.__id}"

    def to_file_string(self):
        return f"{self.__nume}, {self.__id}"
