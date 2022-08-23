#!usr/bin/python3

import math

def minOperations(n):
    """
    Given a number n, write a method that calculates
    the fewest number of operations needed to result
    in exactly n H characters in the file.
    """
    if math.sqrt(n)**2 == n:
        return int(math.sqrt(n) * 2)
    elif n % 2 == 0:
        return int(n / 2 + 1)
    return 0
