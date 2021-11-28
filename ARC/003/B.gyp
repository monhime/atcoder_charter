import sys
def input(): return sys.stdin.readline().rstrip()
from operator import itemgetter
def main():
    n=int(input())
    dic=[]
    for i in range(n):
        s=input()
        dic.append((s[::-1],s))
    dic.sort()
    for i in range(n):
        print(dic[i][1])

if __name__=='__main__':
    main()