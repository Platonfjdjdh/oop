# Программирование на языке высокого уровня (Python).
# Задание № 04_03_02. Вариант 22
#
# Выполнил: Ташлыков П.С.
# Группа: ПИН-б-о-22-1
# E-mail: tashlykovplaton@yandex.ru


class Пицца:
    """Класс Пицца содержит общие атрибуты для пиццы.

    Дочерние классы будут их конкретизировать.
    """

    def __init__(self):
        """Конструктор класса.

        Инициализирует атрибуты пиццы (значения по умолчанию).
        """
        self.название = "Заготовка"
        self.тесто = "тонкое"  # тонкое или пышное
        self.соус = "кечтуп"   # или другой
        self.начинка = []      # список начинок (по умолчанию - нет)

        self.цена = 0

    def __str__(self):
        """Вернуть информацию о пицце: название, тесто, соус, начинка.

        Формат вывода:

        Пицца: Пепперони | Цена: 350.00 р.
        Тесто: тонкое Соус: томатный
        Начинка: пепперони, сыр моцарелла
        """

        return f'Пицца: {self.название} | Цена: {self.цена:.2f} р.\n' \
               f'   Тесто: {self.тесто} Соус: {self.соус}\n' \
               f'   Начинка: {", ".join(self.начинка)}'

    def подготовить(self):
        """Сообщить о процессе подготовки.

        Формат вывода:

        Начинаю готовить пиццу Пепперони
          - замешиваю тонкое тесто...
          - добавляю соус: томатный...
          - и, конечно: пепперони, сыр моцарелла...
        """
        print(
            f'Начинаю готовить пицуу {self.название}',
            f' - замешиваю {self.тесто} тесто...',
            f' - добавляю соус: {self.соус}...',
            f' - и, конечно: {", ".join(self.начинка)}...',
            sep='\n'
        )

    def испечь(self):
        """Сообщить о процессе запекания пиццы.

        Формат вывода: произвольное сообщение.
        """
        print('Выпекаю пиццу... Готово!')

    def нарезать(self):
        """Сообщить о процессе нарезки.

        Формат вывода: произвольное сообщение.
        """
        print('Нарезаю на аппетитные кусочки...')

    def упаковать(self):
        """Сообщить о процессе упаковки.

        Формат вывода: произвольное сообщение.
        """
        print('Упаковываю в фирменную упаковку и готово!')


class ПиццаПепперони(Пицца):
    """Класс ПиццаПепперони дополняет класс Пицца."""

    def __init__(self):
        super().__init__()

        self.название = 'Пипперони'
        self.соус = 'томатный'
        self.тесто = 'тонкое'
        self.начинка = [
            'томаты', 'колбаса салями', 'сыр моцарелла',
            'перец чили', 'чеснок', 'сушённый базелик',
            'оливковое масло'
        ]

        self.цена = 550

class ПиццаБарбекю(Пицца):
    """Класс ПиццаБарбекю дополняет класс Пицца."""

    def __init__(self):
        super().__init__()

        self.название = 'Барбекю'
        self.соус = 'барбекю'
        self.тесто = 'тонкое'
        self.начинка = [
            'томаты', 'говядина', 'сыр моцарелла',
            'баклажан', 'шампиньоны', 'лук сладкий',
            'солённый огурец'
        ]

        self.цена = 625


class ПиццаДарыМоря(Пицца):
    """Класс ПиццаДарыМоря дополняет класс Пицца."""

    def __init__(self):
        super().__init__()

        self.название = 'Дары моря'
        self.соус = 'чесночный'
        self.тесто = 'тонкое'
        self.начинка = [
            'семга', 'креветки', 'сыр моцарелла',
            'мидии', 'маслины', 'лук красный'
        ]

        self.цена = 700
