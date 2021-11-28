import sys
def input(): return sys.stdin.readline().rstrip()

def main():
    n = int(input())
    x = input()

    x_1_cunt = x.count('1')
    x_num = int(x, 2)
    first_x_mod_0 = x_num %  (x_1_cunt + 1) #0を1にする
    if x_1_cunt > 1:
        first_x_mod_1 = x_num %  (x_1_cunt - 1) #1を0にする

    for i in range(n):
        if x[i] == '1' and x_1_cunt == 1: #i番目だけ1のとき→操作回数0
            print(0)
            continue
        if x[i] == '0':
            x_num_i = (first_x_mod_0 + pow(2, n - i - 1, x_1_cunt + 1)) % (x_1_cunt + 1)
        else:
            x_num_i = (first_x_mod_1 - pow(2, n - i - 1, x_1_cunt - 1)) % (x_1_cunt - 1)
        
        cunt = 1 #操作回数
        while x_num_i:
            cunt += 1
            x_num_i = x_num_i % bin(x_num_i).count('1')

        print(cunt)


if __name__=='__main__':
    main()