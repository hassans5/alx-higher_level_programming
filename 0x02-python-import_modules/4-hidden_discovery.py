#!/usr/bin/python3.8
import dis

def print_hidden():
    pass

def print_school():
    pass

def my_secret_santa():
    pass

if __name__ == "__main__":
    bytecode = __import__('hidden_4').__dict__['__builtins__'].__dict__['__import__']('dis').Bytecode(__import__('hidden_4'))
    names = set()

    for instruction in bytecode:
        if instruction.opname == 'LOAD_GLOBAL' and instruction.argval not in ['__name__', '__doc__']:
            names.add(instruction.argval)

    for name in sorted(names):
        print(name)
