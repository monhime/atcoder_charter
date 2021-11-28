import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    k = int(input())
    keta = 1
    mod = 7%k
    if k % 7 == 0:
        max_k = 9*k//7
    else:
        max_k = 9*k
    if k %2 == 0 or k%5 == 0:
        print(-1)
    while keta < max_k:
        if mod == 0:
            print(keta)
            break
        mod = (mod*10 + 7)%k
        keta += 1


if __name__=='__main__':
    main()