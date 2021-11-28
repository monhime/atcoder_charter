import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    s=input()
    n=len(s)
    target="keyence"
    if s==target:
        print("YES")
        sys.exit()
    for i in range(n):#文字列開始
        for j in range(n):#文字列終了
            for k in range(i,j+1):
                #区間[i,j]が予想
                s_exp=s[:i]+s[j+1:]
                if s_exp==target:
                    print("YES")
                    sys.exit()
    print("NO")



if __name__=='__main__':
    main()