# Программирование на языке высокого уровня (Python).
# Задание № 04_03_04. Вариант 22
#
# Выполнил: Ташлыков П.С.
# Группа: ПИН-б-о-22-1
# E-mail: tashlykovplaton@yandex.ru


from line_segment import LineSegment
from test_line_segment import TestLineSegment, unittest

if __name__ == "__main__":

    segment1 = LineSegment(down=float('-inf'), up=4)
    segment2 = LineSegment(down=1, up=float('inf'))
    segment3 = segment1 & segment2

    assert str(segment1) == '(-inf; 4)'
    assert str(segment2) == '(1; inf)'
    assert str(segment3) == '(1; 4)'
    assert segment1.distance() == float('inf')
    assert segment3.distance() == 3

    segment1.set_down_border(3)
    segment2.set_up_border(4)
    assert str(segment1) == '(3; 4)'
    assert str(segment2) == '(1; 4)'

    segment5 = LineSegment.from_string('(1; 4)')
    assert segment3 == segment5

    segment6 = LineSegment(down=float('-inf'), up=4)
    segment6.save('line_segment.json')
    segment7 = LineSegment.load('line_segment.json')
    assert segment7 == segment6
    #unittest.TextTestRunner().run(unittest.TestLoader().loadTestsFromTestCase(TestLineSegment))