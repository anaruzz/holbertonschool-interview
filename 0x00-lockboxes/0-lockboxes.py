#!/usr/bin/python3
#Script that determines if all the boxes can be opened

def canUnlockAll(boxes):
    """
    function that determines if all boxes can be opened
    """
    if len(boxes) == 0:
        return False

    keys = [0]
    t = 1
    for key in keys:
        for i in boxes[key]:
            if i not in keys:
                if i != key and i < len(boxes):
                    keys.append(i)
                    t += 1
    if t != len(boxes):
        return False
    return True
