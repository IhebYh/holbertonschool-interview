#!/usr/bin/python3
import sys
import signal


def handler(sig, frame):
    print("File size: {}".format(fileSize))
    for status in statuses:
        print("{}: {}".format(status, statuses[status]))
        statuses[status] = 0
    sys.exit(0)


counter = 0
fileSize = 0
statuses = {'200': 0,
            '401': 0,
            '403': 0,
            '404': 0,
            '405': 0,
            '500': 0
            }
signal.signal(signal.SIGINT, handler)
while sys.stdin.readable():
    line = sys.stdin.readline()
    lineSplitted = line.split(" ")
    fileSize += int(lineSplitted[-1])
    if statuses.__contains__(lineSplitted[-2]):
        statuses[lineSplitted[-2]] += 1
        counter += 1
    if counter == 10:
        print("File size: {}".format(fileSize))
        for status in statuses:
            print("{}: {}".format(status, statuses[status]))
            statuses[status] = 0
        counter = 0
        fileSize = 0
