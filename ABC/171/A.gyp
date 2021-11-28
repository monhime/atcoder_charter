import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    s = input()
    if 'a' <= s and s <= 'z':
        print("a")
    else:
        print("A")

if __name__=='__main__':
    main()