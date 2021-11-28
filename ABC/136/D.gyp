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
    run_s=run_length(s)
    n=len(s)
    ans=[0]*n
    index=-1
    for i in range(len(run_s)//2):
        index+=run_s[2*i][1]
        ans[index]+=(run_s[2*i][1]+1)//2+run_s[2*i+1][1]//2
        ans[index+1]+=run_s[2*i][1]//2+(run_s[2*i+1][1]+1)//2
        index+=run_s[2*i+1][1]
    print(*ans)

if __name__=='__main__':
    main()