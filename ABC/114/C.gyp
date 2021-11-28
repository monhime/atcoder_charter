import sys
def input(): return sys.stdin.readline().rstrip()
def dfs(s):
    if int(s)>n:return 0
    ret=1 if all(s.count(c)>0 for c in '753') else 0
    for c in '753':
        ret+=dfs(s+c)
    return ret
def main():
    global n
    n=int(input())
    print(dfs('0'))

if __name__=='__main__':
    main()