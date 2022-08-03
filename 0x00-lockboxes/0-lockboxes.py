#!/usr/bin/python3
"""
You have n number of locked boxes in front of you.
Each box is numbered sequentially from 0 to n - 1 and
each box may contain keys to the other boxes.
"""


def canUnlockAll(boxes):
    """ lockboxes problem """
    boxesNbr = len(boxes) - 1
    unlockedBoxes = []
    for i, box in enumerate(boxes):
        for key in box:
            if key <= boxesNbr:
                if not unlockedBoxes.__contains__(key):
                    unlockedBoxes.append(key)
    canUnlock = len(unlockedBoxes) == (boxesNbr) or len(unlockedBoxes) == (boxesNbr + 1)
    return canUnlock
