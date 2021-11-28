import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    A=input()
    len_a=len(A)
    if len_a==1:
        print(0)
        sys.exit()
    ans=25*len_a
    cunt=0
    for i in range(len_a//2):
        if A[i]==A[-1-i]:
            cunt+=1
    if cunt==len_a//2 and len_a%2==1:
        ans-=25
    elif cunt==len_a//2-1:
        ans-=2

    print(ans)


if __name__=='__main__':
    main()