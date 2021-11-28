import sys
def input(): return sys.stdin.readline().rstrip()
from collections import Counter
def main():
    s = input()
    s_c = Counter('{:03d}'.format(int(s)))
    #print(s_c)
    if len(s) == 1:
        max_8 = 2
    elif len(s) == 2:
        max_8 = 13
    else:
        max_8 = 125
    for i in range(max_8):
        simo_3 = '{:03d}'.format(8*i) #下3桁がこの値になれば8の倍数
        simo_3_c = Counter(simo_3)
        for simo_3_c_key, simo_3_c_v in simo_3_c.items():
            if s_c[simo_3_c_key] < simo_3_c_v:
                break
        else:
            print("Yes")
            break
    else:
        print("No")
    

if __name__=='__main__':
    main()