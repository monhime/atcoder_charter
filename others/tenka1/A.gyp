import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    s=input()
    ans=0
    for ss in s:
        if ss=='1':ans+=1
    print(ans)

if __name__=='__main__':
    main()