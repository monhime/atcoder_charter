import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    na,nb=map(int,input().split())
    A=set([_ for _ in input().split()])
    B=set([_ for _ in input().split()])
    C=A&B
    D=A|B
    print(len(C)/len(D))


if __name__=='__main__':
    main()