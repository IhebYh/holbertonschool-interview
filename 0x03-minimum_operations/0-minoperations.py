#!usr/bin/python3


def minOperations(n):
    """
    Given a number n, write a method that calculates
    the fewest number of operations needed to result
    in exactly n H characters in the file.
    """
    if n < 2 or type(n) != int:
        return 0
    op = 2
    counter = 1
    while counter <= n:
        if counter == n:
            op += 1
        else:
            op += 2
        counter += 1
    return op
