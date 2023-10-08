# Программирование на языке высокого уровня (Python).
# Задание № 04_03_06. Вариант 22
#
# Выполнил: Ташлыков П.С.
# Группа: ПИН-б-о-22-1
# E-mail: tashlykovplaton@yandex.ru


class WritingAffiliation:
    NAME = 'Пишущая принадлежность'

    def __init__(self, *, color: str, width: float) -> None:
        self._color = color
        self._width = width

    def __str__(self) -> str:
        return self.NAME

    @property
    def color(self) -> str:
        return self._color

    @property
    def width(self) -> float:
        return self._width

    def write(self, text: str) -> None:
        print(f'С помощью "{self.NAME}" написали "{text}"')
