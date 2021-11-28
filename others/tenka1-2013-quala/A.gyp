import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    p=42
    while p<=130000000:
        p*=2
    print(p)

if __name__=='__main__':
    main()