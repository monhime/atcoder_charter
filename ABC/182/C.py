import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n = input()
    len_n = len(n)
    sum_n = 0 #各桁の和
    for nn in n:
        sum_n += int(nn)
    cunt_min = 20
    for bit_n in range(2**len_n - 1):#2**n通りのbit_n番目を探索
        bit = bit_n
        i = 0 #操作対称
        cunt = 0 #回数
        sum_nn = sum_n
        while bit > 0:
            if (bit&1) == 1:# bitの最下位が1であれば操作
                sum_nn -= int(n[i])
                cunt += 1
            bit >>= 1 #bitを1桁右にずらす
            i += 1 #操作の対象番号ずらす
        if sum_nn % 3 == 0:
            cunt_min = min(cunt_min, cunt)

    if cunt_min == 20:
        print(-1)
    else:
        print(cunt_min)

if __name__=='__main__':
    main()