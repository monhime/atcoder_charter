import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    x_a,y_a,x_b,y_b,x_c,y_c=map(int,input().split())
    x_1=x_b-x_a
    y_1=y_b-y_a
    x_2=x_c-x_a
    y_2=y_c-y_a
    print(abs(x_2*y_1-x_1*y_2)/2)


if __name__=='__main__':
    main()