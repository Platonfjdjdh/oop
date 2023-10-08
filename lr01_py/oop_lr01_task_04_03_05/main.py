# Программирование на языке высокого уровня (Python).
# Задание № 04_03_05. Вариант 22
#
# Выполнил: Ташлыков П.С.
# Группа: ПИН-б-о-22-1
# E-mail: tashlykovplaton@yandex.ru


from lr01_py.oop_lr01_task_04_03_05.line_segment_collection import LineSegmentCollection, LineSegment

if __name__ == "__main__":
    segments =[
        LineSegment(down=float('-inf'), up=15),
        LineSegment(down=-134, up=float('inf')),
        LineSegment(down=-4, up=17),
    ]
    collection = LineSegmentCollection(*segments)
    assert str(collection) == '[(-inf; 15), (-134; inf), (-4; 17)]'
    assert collection[2] == LineSegment(down=-4, up=17)

    collection.add(LineSegment(down=-177, up=177))
    segments.append(LineSegment(down=-177, up=177))
    assert collection == LineSegmentCollection(*segments)

    collection.remove(3)
    del segments[3]
    assert collection == LineSegmentCollection(*segments)

    collection.save('line_segment_collection.json')
    collection_from_json = LineSegmentCollection.load('line_segment_collection.json')
    assert collection == collection_from_json

