import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    cunt_a=0
    cunt_b=0
    cunt_ba=0
    cunt_ab=0
    for i in range(n):
        s=input()
        if s[0]=='B' and s[-1]=='A':
            cunt_ba+=1
        elif s[0]=='B': 
            cunt_b+=1
        elif s[-1]=='A':
            cunt_a+=1
        for j in range(len(s)-1):
            if s[j:j+2]=="AB":
                cunt_ab+=1
    if cunt_a==0 and cunt_b==0 and cunt_ba>0:
        print(cunt_ab+cunt_ba-1)
    else:
        print(cunt_ab+cunt_ba+min(cunt_a,cunt_b))
    
if __name__=='__main__':
    main()