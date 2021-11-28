import sys
def input(): return sys.stdin.readline().rstrip()
def dfs(s,mxs):
    if len(s)==n:
        print(s)
    else:
        for i in range(ord('a'),ord(mxs)+1):
            dfs(s+chr(i),chr(i+1) if i ==ord(mxs) else mxs)

def main():
    global n
    n=int(input())
    dfs('','a')
    

if __name__=='__main__':
    main()