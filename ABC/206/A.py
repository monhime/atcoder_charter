import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n = int(input())
    if 1.08*n//1 < 206:
        print("Yay!")
    elif 1.08*n//1 == 206:
        print("so-so")
    else:
        print(":(")

if __name__=='__main__':
    main()