import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=input()
    ans=0
    for nn in n:
        if nn=="2":ans+=1
    print(ans)

if __name__=='__main__':
    main()