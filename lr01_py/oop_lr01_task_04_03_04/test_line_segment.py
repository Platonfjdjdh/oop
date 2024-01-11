import unittest
from line_segment import LineSegment

class TestLineSegment(unittest.TestCase):
    def setUp(self):
        # Подготовка данных для тестов
        self.segment1 = LineSegment(down=float('-inf'), up=4)
        self.segment2 = LineSegment(down=1, up=float('inf'))
        self.segment3 = self.segment1 & self.segment2
        self.segment1_updated = LineSegment(down=3, up=4)
        self.segment2_updated = LineSegment(down=1, up=4)

    def test_str_representation(self):
        self.assertEqual(str(self.segment1), '(-inf; 4)')
        self.assertEqual(str(self.segment2), '(1; inf)')
        self.assertEqual(str(self.segment3), '(1; 4)')

    def test_distance_calculation(self):
        self.assertEqual(self.segment1.distance(), float('inf'))
        self.assertEqual(self.segment3.distance(), 3)

    def test_borders_update(self):
        self.assertEqual(str(self.segment1), '(-inf; 4)')
        self.assertEqual(str(self.segment2), '(1; inf)')

    def test_from_string_method(self):
        segment5 = LineSegment.from_string('(1; 4)')
        self.assertEqual(self.segment3, segment5)

    def test_save_and_load_methods(self):
        self.segment6 = LineSegment(down=float('-inf'), up=4)
        self.segment6.save('line_segment.json')
        self.segment7 = LineSegment.load('line_segment.json')
        self.assertEqual(self.segment7, self.segment6)

    # Другие тесты, если необходимо

    def tearDown(self):
        # Очистка данных после тестов
        pass

if __name__ == '__main__':
    unittest.main()