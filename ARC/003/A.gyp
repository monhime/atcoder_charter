import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    s=input()
    ans=0
    for ss in s:
        if ss!='F':
            ans+=ord('E')-ord(ss)
    print(ans/n)
if __name__=='__main__':
    main()