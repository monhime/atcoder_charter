import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    s=input()
    k=int(input())
    ans=""
    sx=s[k-1]
    for ss in s:
        if ss!=sx:
            ans+='*'
        else:
            ans+=sx 
    print(ans)

if __name__=='__main__':
    main()