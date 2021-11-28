import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    s=input()
    LR=['AA','AB','AX','AY','BA','BB','BX','BY','XA','XB','XX','XY','YA','YB','YX','YY']
    ans=10**10
    for i in range(15):
        L=LR[i]
        for j in range(i+1,16):
            R=LR[j]
            cunt=0
            k=0
            while k<n:
                if k<n-1 and (s[k:k+2]==L or s[k:k+2]==R):
                    k+=2
                else:
                    k+=1
                cunt+=1
            ans=min(ans,cunt)
    print(ans)

if __name__=='__main__':
    main()