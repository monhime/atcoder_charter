import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    s=input()
    s_len=len(s)
    g=[0]*s_len
    g[0]=1
    if s[1]==s[0]:g[1]=1
    else: g[1]=2
    for i in range(2,s_len):
        if s[i]==s[i-1]:
            g[i]=g[i-3]+2
        else:
            g[i]=g[i-1]+1
    print(g[-1])

if __name__=='__main__':
    main()