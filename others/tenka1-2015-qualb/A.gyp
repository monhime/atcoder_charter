import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    A=[0]*20
    A[0]=100
    A[1]=100
    A[2]=200
    for i in range(3,20):
        A[i]=sum(A[i-3:i])
    print(A[-1])

if __name__=='__main__':
    main()