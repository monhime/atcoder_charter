import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    s=input()
    len_s=len(s)
    i=0
    cunt_a=0
    ans=0
    while i<len_s:
        if s[i]=='A':  
            cunt_a+=1
        elif i<len_s-1 and s[i:i+2]=="BC" and cunt_a>0:
            ans+=cunt_a
            i+=1
        else:
            cunt_a=0
        i+=1
    print(ans)




if __name__=='__main__':
    main()