from pen import Pen
from pencil import Pencil
from gel_pen import GelPen

class TestData:
    @staticmethod
    def run_all_tests():
        print("Тест запущен")
        TestData.test_pen()
        TestData.test_pencil()
        TestData.test_gel_pen()

    @staticmethod
    def test_pen():
        pen = Pen(color='black', width=0.3)
        assert pen.remains == 100
        pen.write('some text')
        assert pen.remains == 99.9

    @staticmethod
    def test_pencil():
        pencil = Pencil(color='gray', width=0.1, length=10)
        assert pencil.length == 10
        assert pencil.width == 0.1
        pencil.write('some text')
        assert pencil.length == 10
        assert pencil.width == 0.11
        pencil.sharpen()
        assert pencil.length == 9.9
        assert pencil.width == 0.1

    @staticmethod
    def test_gel_pen():
        gel_pen = GelPen(color='green', width=0.2)
        assert gel_pen.remains == 100
        gel_pen.write('some text')
        assert gel_pen.remains == 99.9

