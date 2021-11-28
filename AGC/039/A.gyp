import sys
def input(): return sys.stdin.readline().rstrip()
def run_length(s):
    ans=[]
    if len(s)==1:
        ans.append((s,1))
        return ans
    s_pre=s[0]
    cunt=1
    for i,ss in enumerate(s[1:],1):
        if ss==s_pre:
            cunt+=1
        else:
            ans.append((s_pre,cunt))
            cunt=1
            s_pre=ss
    ans.append((s_pre,cunt))
    return ans

def main():
    s=input()
    k=int(input())
    s_lis=run_length(s)
    ans=0    
    if len(s_lis)==1:
        print(k*s_lis[0][1]//2)
    else:
        for tup in s_lis:
            ans+=tup[1]//2  
        if s_lis[0][0]==s_lis[-1][0]:
            a=s_lis[0][1]
            b=s_lis[-1][1]
            print(ans*k-(a//2+b//2-(a+b)//2)*(k-1))
        else:
            print(ans*k)


if __name__=='__main__':
    main()