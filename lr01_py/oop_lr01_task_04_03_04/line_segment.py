# Программирование на языке высокого уровня (Python).
# Задание № 04_03_04. Вариант 22
#
# Выполнил: Ташлыков П.С.
# Группа: ПИН-б-о-22-1
# E-mail: tashlykovplaton@yandex.ru


import json
from typing import Optional


class LineSegment:
    def __init__(self, *, down: float, up: float) -> None:
        self._down, self._up = down, up
        self._check_border()

    def __str__(self) -> str:
        return f'({self._down}; {self._up})'

    def __repr__(self) -> str:
        return f'({self._down}; {self._up})'

    def __eq__(self, other: 'LineSegment') -> bool:
        return self._to_tuple() == other._to_tuple()

    def __ne__(self, other: 'LineSegment') -> bool:
        return not self.__eq__(other)

    @classmethod
    def from_string(cls, str_interval) -> 'LineSegment':
        down, up = map(float, str_interval.replace('(', '').replace(')', '').split('; '))
        return LineSegment(down=down, up=up)

    @classmethod
    def from_dict(cls, dct_interval: dict[str, float]) -> 'LineSegment':
        return LineSegment(**{key: float(value) for key, value in dct_interval.items()})

    @classmethod
    def load(cls, filename: str) -> 'LineSegment':
        with open(filename, 'rb') as file:
            return LineSegment.from_dict(json.load(file))

    @property
    def down(self) -> float:
        return self._down

    @property
    def up(self) -> float:
        return self._up

    def _check_border(self):
        if self._up < self._down:
            raise TypeError('Конечное значение должно быть больше начального')

    def _to_dict(self) -> dict[str, float]:
        return {
            'down': str(self.down) if abs(self.down) == float('inf') else self.down,
            'up': str(self.up) if abs(self.up) == float('inf') else self.up,
        }

    def _to_tuple(self) -> tuple[float, float]:
        return self.down, self.up

    def set_up_border(self, up: float) -> None:
        self._up = up
        self._check_border()

    def set_down_border(self, down: float) -> None:
        self._down = down
        self._check_border()

    def save(self, filename: str) -> None:
        with open(filename, 'w', encoding='utf8') as file:
            file.write(
                json.dumps({key: str(value) for key, value in self._to_dict().items()})
            )

    def __and__(self, other: 'LineSegment') -> Optional['LineSegment']:
        try:
            result = LineSegment(down=max(self.down, other.down), up=min(self.up, other.up))
        except TypeError:
            result = None
        return result

    def distance(self) -> float:
        return self.up - self.down
