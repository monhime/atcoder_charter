import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    S=[]
    for i in range(1,1001):
        S.append(str(i))
    S.sort()
    for s in S:
        print(s)

if __name__=='__main__':
    main()