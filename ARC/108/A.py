import sys
def input(): return sys.stdin.readline().rstrip()
def make_divisors(n): #https://qiita.com/LorseKudos/items/9eb560494862c8b4eb56
    lower_divisors , upper_divisors = [], []
    i = 1
    while i*i <= n:
        if n % i == 0:
            lower_divisors.append(i)
        i += 1
    return lower_divisors

def main():
    s, p = map(int,input().split())
    dev = make_divisors(p)
    for d in dev:
        if s - d == p//d:
            print("Yes")
            break
    else:
        print("No")

if __name__=='__main__':
    main()