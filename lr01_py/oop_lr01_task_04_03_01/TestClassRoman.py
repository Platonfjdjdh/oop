import unittest
from roman import Roman

class TestRomanClass(unittest.TestCase):

    def setUp(self):
        self.roman_1 = Roman("X")
        self.roman_2 = Roman(5)
        self.arabic_num = 2016
        self.roman_num = "MMXVI"

    def test_addition(self):
        result = self.roman_1 + self.roman_2
        self.assertEqual(str(result), "XV")

    def test_subtraction(self):
        result = self.roman_1 - self.roman_2
        self.assertEqual(str(result), "V")

    def test_multiplication(self):
        result = self.roman_1 * self.roman_2
        self.assertEqual(str(result), "L")

    def test_division(self):
        result = self.roman_1 // self.roman_2
        self.assertEqual(str(result), "II")

    def test_to_arabic(self):
        result = Roman.to_arabic(self.roman_num)
        self.assertEqual(result, self.arabic_num)

    def test_to_roman(self):
        result = Roman.to_roman(self.arabic_num)
        self.assertEqual(result, self.roman_num)

if __name__ == '__main__':
    unittest.main()