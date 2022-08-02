#!/usr/bin/python3
"""
You have n number of locked boxes in front of you.
Each box is numbered sequentially from 0 to n - 1 and
each box may contain keys to the other boxes.
"""


def canUnlockAll(boxes):
    boxesNbr = len(boxes) - 1
    unlockedBoxes = []
    for i in range(0, boxesNbr):
        if type(boxes[i]) == list:
            for j in range(0, len(boxes[i])):
                if boxes[i][j] >= 0 and boxes[i][j] <= boxesNbr:
                    if not unlockedBoxes.__contains__(boxes[i][j]):
                        unlockedBoxes.append(boxes[i][j])
        else:
            if boxes[i] >= 0 and boxes[i] <= boxesNbr:
                if not unlockedBoxes.__contains__(boxes[i]):
                    unlockedBoxes.append(boxes[i])
    canUnlock = len(unlockedBoxes) == (boxesNbr) or len(unlockedBoxes) == (boxesNbr + 1)
    return canUnlock
