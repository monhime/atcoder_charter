import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    s=[_ for _ in input().split()]
    user=[]
    for ss in s:
        if '@' in ss:
            if ss[0]!='@':
                user.extend(ss.split('@')[1:])
            else:
                user.extend(ss.split('@'))
    usr=list(set(user))
    usr.sort()
    for u in usr:
        if u!='':
            print(u)

if __name__=='__main__':
    main()