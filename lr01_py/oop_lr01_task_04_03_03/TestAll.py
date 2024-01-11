import unittest
from deposit import TimeDeposit, BonusTimeDeposit, CompoundTimeDeposit

class TestDeposit(unittest.TestCase):

    def test_time_deposit(self):
        deposit = TimeDeposit("Сохраняй", interest_rate=5, period_limit=(6, 18), sum_limit=(1000, 100000))
        self.assertEqual(deposit.name, "Сохраняй")
        self.assertEqual(deposit.currency, "руб.")
        self.assertEqual(deposit.get_profit(5000, 12), 250.0)
        self.assertEqual(deposit.get_sum(5000, 12), 5250.0)

    def test_bonus_time_deposit(self):
        deposit = BonusTimeDeposit("Бонусный 2", interest_rate=5, period_limit=(6, 18), sum_limit=(1000, 100000),
                                   bonus=dict(percent=5, sum=2000))
        self.assertEqual(deposit.name, "Бонусный 2")
        self.assertEqual(deposit.currency, "руб.")
        self.assertEqual(deposit.get_profit(2500, 12), 131.25)
        self.assertEqual(deposit.get_sum(2500, 12), 2631.25)

    def test_compound_time_deposit(self):
        deposit = CompoundTimeDeposit("С капитализацией", interest_rate=5, period_limit=(6, 18), sum_limit=(1000, 100000))
        self.assertEqual(deposit.name, "С капитализацией")
        self.assertEqual(deposit.currency, "руб.")
        self.assertEqual(deposit.get_profit(3000, 6), 75.79)
        self.assertEqual(deposit.get_sum(3000, 6), 3075.79)

    @classmethod
    def run_all_tests(cls):
        suite = unittest.TestLoader().loadTestsFromTestCase(cls)
        unittest.TextTestRunner(verbosity=2).run(suite)

# Пример вызова из другого файла:
# if __name__ == '__main__':
#     TestDeposit.run_all_tests()
