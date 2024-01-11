# Программирование на языке высокого уровня (Python).
# Задание № 04_03_05. Вариант 22
#
# Выполнил: Ташлыков П.С.
# Группа: ПИН-б-о-22-1
# E-mail: tashlykovplaton@yandex.ru


import json

from line_segment import LineSegment


class LineSegmentCollection:
    def __init__(self, *data: LineSegment) -> None:
        self._data = list(data)[::] or []

    def __str__(self) -> str:
        return str(self._data)

    def __repr__(self) -> str:
        return str(self._data)

    def __getitem__(self, index: int) -> LineSegment:
        return self._data[index]

    def __eq__(self, other: 'LineSegmentCollection') -> bool:
        return self._data == other._data

    def __ne__(self, other: 'LineSegmentCollection') -> bool:
        return self._data != other._data

    def add(self, other: LineSegment) -> None:
        self._data.append(other)

    def remove(self, index: int) -> None:
        del self._data[index]

    def save(self, filename: str) -> None:
        data_dct = [segment._to_dict() for segment in self._data]
        with open(filename, 'w', encoding='utf8') as file:
            json.dump(data_dct, file)

    @classmethod
    def load(cls, filename: str) -> 'LineSegmentCollection':
        with open(filename, 'rb') as file:
            segments = json.load(file)
        return LineSegmentCollection(*[LineSegment.from_dict(segment) for segment in segments])
