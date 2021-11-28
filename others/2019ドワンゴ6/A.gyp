import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    s=[""]*n
    t=[0]*n
    for i in range(n):
        ss,tt=input().split()
        s.append(ss)
        t.append(int(tt))
    x=input()
    print(sum(t[s.index(x)+1:]))

if __name__=='__main__':
    main()