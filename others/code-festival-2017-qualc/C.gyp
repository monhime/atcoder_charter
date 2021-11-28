import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    s=input()
    new_s=""
    for ss in s:
        if ss!='x':
            new_s+=ss
    if new_s[::-1]!=new_s:
        print(-1)
        sys.exit()
    right=len(s)-1
    left=0
    ans=0
    while right-left>0:
        if s[right]!=s[left]:
            if s[right]=='x':
                ans+=1
                right-=1
            elif s[left]=='x':
                ans+=1
                left+=1
        else:
            right-=1
            left+=1
    print(ans)



if __name__=='__main__':
    main()