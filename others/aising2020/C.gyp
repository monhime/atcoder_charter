import sys
def input(): return sys.stdin.readline().rstrip()
def f(x,y,z):
    return x**2 + y**2 + z**2 + x*y + y*z + z*x
def main():
    n = int(input())
    A = [0]*(n+1)
    for x in range(1,100):
        for y in range(x, 100):
            for z in range(y, 100):
                num = f(x,y,z)
                if num > n:
                    break
                if x == y and y == z:
                    A[num] += 1
                elif x == y or y == z or z == x:
                    A[num] += 3
                else:
                    A[num] += 6
    for i in range(1,n+1):
        print(A[i])

if __name__=='__main__':
    main()