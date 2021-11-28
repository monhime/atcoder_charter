import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    s=input()
    d_1=-1
    d_2=-1
    for ss in s:
        if '0'<=ss and ss<='9':
            if d_1==-1:
                d_1=int(ss)
            else:
                d_2=int(ss)
    if d_2==-1:
        print(d_1)
    else:
        print(d_1*10+d_2)

if __name__=='__main__':
    main()