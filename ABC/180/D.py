import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    x, y, a, b = map(int,input().split())
    prod_time = 0 #aをかける回数
    x_prod_multi_a = x 
    ans = 0
    while x_prod_multi_a < y:
        ans = max(ans, -(-(y - x_prod_multi_a)//b) - 1 + prod_time)

        prod_time += 1
        x_prod_multi_a *= a
    print(ans)


if __name__=='__main__':
    main()