#!/usr/bin/python3
""" rain """


def rain(walls):
    """ calculate square units after the rain"""
    peak1 = 0
    peak2 = 0
    distance = 0
    water = 0
    for i in range(0, len(walls)):
        if walls[i] != 0:
            if peak1 == 0:
                peak1 = walls[i]
                distance = 0
            else:
                peak2 = walls[i]
                water += min(peak1, peak2) * distance
                peak1 = peak2
                peak2 = 0
                distance = 0
        else:
            distance += 1
    return water
