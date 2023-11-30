#!/usr/bin/python3
from sys import argv

if __name__ == "__main__":
    argc = len(argv) - 1
    if argc == 0:
        print("0")
    else:
        result = sum(int(arg) for arg in argv[1:])
        print(result)
