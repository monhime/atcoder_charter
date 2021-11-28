import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    s=input()
    left,right=0,0
    cunt=0
    i=0
    while i<len(s)-1:
        if s[i:i+2]=="25":
            left=i
            right=i+2
            while right<len(s)-1 and s[right:right+2]=="25":
                right+=2
            n=(right-left)//2
            cunt+=(n+1)*n//2
            i=right
        else:
            i+=1
    print(cunt)

if __name__=='__main__':
    main()