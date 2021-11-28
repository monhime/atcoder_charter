import sys
def input(): return sys.stdin.readline().rstrip()
from collections import Counter
def main():
    n=int(input())
    s=input()
    if n<=3:
        print(-(-n//2))
        sys.exit()
    s_lis=[]
    for i in range(n-1):
        s_lis.append(s[i:i+2])
    L=Counter(s_lis).most_common(1)[0][0]
    new_s=""
    i=0
    while i<n:
        if i==n-1:
            new_s+=s[i]
            break
        elif s[i:i+2]!=L:
            new_s+=s[i]
            i+=1
        else:
            i+=2
    new_slis=[]
    if len(new_s)==0:   
        i=0
        ans=0
        while i<n:
            if i<n-1 and s[i:i+2]==L:
                i+=2
            else:
                i+=1
            ans+=1
    else:
        for i in range(len(new_s)-1):
            new_slis.append(new_s[i:i+2])
        R=Counter(new_slis).most_common(1)[0][0]    
        i=0
        ans=0
        while i<n:
            if i<n-1 and (s[i:i+2]==R or s[i:i+2]==L):
                i+=2
            else:
                i+=1
            ans+=1
    print(ans)


if __name__=='__main__':
    main()