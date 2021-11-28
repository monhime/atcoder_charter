import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    k=int(input())
    keta_n=len(str(n))
    ans=0
    left=n//10**(keta_n-1)
    if k==1:
        ans=(keta_n-1)*9+left
    elif k==2:
        for i in range(2,keta_n):
            ans+=81*(i-1)
        ans+=(left-1)*(keta_n-1)*9
        left2=n%10**(keta_n-1)
        left2_keta=len(str(left2))
        left2_num=left2//10**(left2_keta-1)
        ans+=(left2_keta-1)*9+left2_num
    elif k==3:
        for i in range(3,keta_n):
            ans+=729*(i-1)*(i-2)//2   
        ans+=(left-1)*(keta_n-1)*(keta_n-2)//2
        left2=n%10**(keta_n-1)
        left2_keta=len(str(left2))
        left2_num=left2//10**(left2_keta-1)
        ans+=(left2_keta-1)*(left2_keta-2)//2*81+(left2_keta-1)*left2_num*9
        left3=n%10**(left2_keta-1)
        left3_keta=len(str(left3))
        left3_num=left3//10**(left3_keta-1)        
        ans+=(left3_keta-1)*9+left3_num
    print(ans)

if __name__=='__main__':
    main()