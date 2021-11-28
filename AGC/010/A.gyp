import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    _=input()
    A=[int(a) for a in input().split() if int(a)%2==1]
    if len(A)%2:print("NO")
    else:print("YES")

if __name__=='__main__':
    main()