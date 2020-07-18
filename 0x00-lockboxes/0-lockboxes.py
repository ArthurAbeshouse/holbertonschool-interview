#!/usr/bin/python3


def canUnlockAll(boxes):
    visits = [0] * len(boxes)
    visits[0] = 1
    list_stack = [0]

    while len(list_stack):
        box = list_stack.pop()
        for box_contents in boxes[box]:
            if box_contents >= 0 and box_contents < len(boxes)\
               and not visits[box_contents]:
                visits[box_contents] = 1
                list_stack.append(box_contents)
    return all(visits)
