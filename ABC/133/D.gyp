def main():
    n,*A=map(int,open(0).read().split())
    B=[0]*n
    B[0]=sum(A)-sum(A[1::2])*2
    for i in range(1,n):
        B[i]=(A[i-1]-B[i-1]//2)*2
    print(' '.join(map(str,B)))
    
if __name__=='__main__':
    main()