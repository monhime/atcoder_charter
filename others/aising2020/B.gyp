import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n = int(input())
    A = list(map(int,input().split()))
    cunt=0
    for i, a in enumerate(A):
        if i%2==0 and a%2:
            cunt+=1
    print(cunt)


if __name__=='__main__':
    main()