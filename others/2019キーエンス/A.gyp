import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    a,b,c,d=sorted(list(map(int,input().split())))
    if a==1 and b==4 and c==7 and d==9:
        print("YES")
    else:print("NO")

if __name__=='__main__':
    main()