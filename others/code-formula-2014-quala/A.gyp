import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    a=int(input())
    for i in range(101):
        if a==i**3:
            print("YES")
            sys.exit()
    else:
        print("NO")

if __name__=='__main__':
    main()