# test_data.py
from line_segment import LineSegment
from line_segment_collection import LineSegmentCollection

class TestData:
    @staticmethod
    def get_line_segment_collection_data():
        # Придуманные тестовые данные для LineSegmentCollection
        segment1 = LineSegment(down=float('-inf'), up=4)
        segment2 = LineSegment(down=1, up=float('inf'))
        segment3 = segment1 & segment2

        segments_data = [
            LineSegment(down=float('-inf'), up=15),
            LineSegment(down=-134, up=float('inf')),
            LineSegment(down=-4, up=17),
        ]

        collection_data = LineSegmentCollection(*segments_data)

        # Тесты для LineSegmentCollection
        assert str(collection_data) == '[(-inf; 15), (-134; inf), (-4; 17)]'
        assert collection_data[2] == LineSegment(down=-4, up=17)

        collection_data.add(LineSegment(down=-177, up=177))
        segments_data.append(LineSegment(down=-177, up=177))
        assert collection_data == LineSegmentCollection(*segments_data)

        collection_data.remove(3)
        del segments_data[3]
        assert collection_data == LineSegmentCollection(*segments_data)

        return collection_data

    @staticmethod
    def get_another_line_segment_collection_data():
        # Другие придуманные тестовые данные для LineSegmentCollection
        segment4 = LineSegment(down=-10, up=0)
        segment5 = LineSegment(down=5, up=10)
        segment6 = LineSegment(down=7, up=15)

        another_segments_data = [
            LineSegment(down=-20, up=0),
            LineSegment(down=-5, up=12),
            LineSegment(down=8, up=18),
        ]

        another_collection_data = LineSegmentCollection(*another_segments_data)

        # Тесты для другого LineSegmentCollection
        assert str(another_collection_data) == '[(-20; 0), (-5; 12), (8; 18)]'
        assert another_collection_data[1] == LineSegment(down=-5, up=12)

        another_collection_data.add(LineSegment(down=-15, up=5))
        another_segments_data.append(LineSegment(down=-15, up=5))
        assert another_collection_data == LineSegmentCollection(*another_segments_data)

        another_collection_data.remove(2)
        del another_segments_data[2]
        assert another_collection_data == LineSegmentCollection(*another_segments_data)

        return another_collection_data
    @staticmethod
    def run_all_tests():
        print("Running all tests...\n")

        # Тесты для LineSegmentCollection
        collection_data = TestData.get_line_segment_collection_data()
        another_collection_data = TestData.get_another_line_segment_collection_data()

        # Дополнительные тесты, если необходимо

        print("All tests passed!")