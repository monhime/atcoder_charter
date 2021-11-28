import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n, x, m = map(int,input().split())
    sum_lis = [-1] * m #余りが最初にiのときの和
    a_lis_i = [-1] * m #余りが最初にiのときのindex
    a = x
    sum_a = a
    sum_lis[a] = sum_a
    a_lis_i[a] = 0
    for i in range(1, n):
        a = pow(a, 2, m)
        sum_a += a
        if sum_lis[a] != -1: #2週目
            loop_i = i - a_lis_i[a] #1循環の個数
            loop_sum = sum_a - sum_lis[a] #1循環の和
            loop_cunt = (n - 1 - i)//loop_i #i+1以降の循環個数
            sum_a += loop_sum*loop_cunt #ループ分まとめて足す
            i += loop_i*loop_cunt
            for j in range(i + 1, n):
                a = pow(a, 2, m)
                sum_a += a             
            print(sum_a)
            sys.exit()
        sum_lis[a] = sum_a
        a_lis_i[a] = i
    print(sum_a)

if __name__=='__main__':
    main()