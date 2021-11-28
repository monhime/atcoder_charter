import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    A=[int(_) for _ in input().split()]
    cunt=0
    for a in A:
        if a%2==0:cunt+=1
    print(3**n-2**cunt)

if __name__=='__main__':
    main()