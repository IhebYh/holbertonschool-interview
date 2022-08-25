#!/usr/bin/python3
"""
Minimum Operations Model
"""

def minOperations(n):
    """
    Given a number n, write a method that calculates
    the fewest number of operations needed to result
    in exactly n H characters in the file.
    """
    if n < 2 or type(n) is not int:
        return 0
    op = 0
    counter = 2
    while n > 1:
        if n % counter == 0:
            op += counter
            n /= counter
        else:
            counter += 1
    return op
