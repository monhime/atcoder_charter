import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    a,b=map(int,input().split())
    P=[int(_) for _ in input().split()]
    Q=[int(_) for _ in input().split()]
    X=['x']*10
    for p in P:
        X[p-1]='.'
    for q in Q:
        X[q-1]='o'
    print(X[6]+' '+X[7]+' '+X[8]+' '+X[9])
    print(' '+X[3]+' '+X[4]+' '+X[5])
    print('  '+X[1]+' '+X[2])
    print('   '+X[0])

if __name__=='__main__':
    main()