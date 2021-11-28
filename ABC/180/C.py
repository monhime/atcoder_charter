import sys
def input(): return sys.stdin.readline().rstrip()
def make_divisors(n): #https://qiita.com/LorseKudos/items/9eb560494862c8b4eb56
    lower_divisors , upper_divisors = [], []
    i = 1
    while i*i <= n:
        if n % i == 0:
            lower_divisors.append(i)
            if i != n // i:
                upper_divisors.append(n//i)
        i += 1
    return lower_divisors + upper_divisors[::-1]

def main():
    n = int(input())
    A = make_divisors(n)
    for a in A:
        print(str(a))

if __name__=='__main__':
    main()