import sys
from operator import itemgetter
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    A=[(int(i)+1,int(a)) for i,a in enumerate(input().split())]
    A.sort(key=itemgetter(1))
    print(" ".join(map(str,list(zip(*A))[0])))
if __name__=='__main__':
    main()