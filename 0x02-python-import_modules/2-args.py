#!/usr/bin/python3
from sys import argv

if __name__ == "__main__":
    argc = len(argv) - 1
    if argc == 0:
        print("{} argument{}.".format(argc, 's' if argc != 1 else ''))
    else:
        print("{} argument{}:".format(argc, 's' if argc != 1 else ''))
        for i in range(1, argc + 1):
            print("{}: {}".format(i, argv[i]))
