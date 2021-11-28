import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    H=[int(_) for _ in input().split()]
    cunt_p=0
    while sum(H):
        in_p=False
        for i in range(n):
            if H[i]>0:
                H[i]-=1
                if in_p==False:
                    cunt_p+=1
                    in_p=True
            elif H[i]==0 and in_p:
                in_p=False
    print(cunt_p)
                



if __name__=='__main__':
    main()