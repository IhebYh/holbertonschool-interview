#!/usr/bin/python3
""" Make Change Module """

def makeChange(coins, total):
    """ Make Change Module """
    if total == 0 : 
        return 0
    total_coins = sum(coins)
    if total_coins > total:
        return -1
    coins_tmp = coins
    coins_tmp.sort()
    still_counting = True
    change = 1
    while (still_counting):
        if total_coins == total or not coins_tmp:
            change += 1
            still_counting = False
        elif total_coins + coins_tmp[-1] <= total:
            change += 1
            total_coins += coins_tmp[-1]
        else :
            coins_tmp.pop()
    return change
