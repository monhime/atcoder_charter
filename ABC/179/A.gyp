import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    s = input()
    if s[-1] != 's':
        print(s+'s')
    else:
        print(s+'es')

if __name__=='__main__':
    main()