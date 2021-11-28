import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    c=int(input())
    L1=[]
    L2=[]
    L3=[]
    for i in range(c):
        L=[int(_) for _ in input().split()]
        L.sort()
        L1.append(L[0])
        L2.append(L[1])
        L3.append(L[2])
    print(max(L1)*max(L2)*max(L3))


if __name__=='__main__':
    main()