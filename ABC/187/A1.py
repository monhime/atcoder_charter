import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    a, b = input().split()
    s_a = int(a[0]) + int(a[1]) + int(a[2])
    s_b = int(b[0]) + int(b[1]) + int(b[2])
    print(max(s_a, s_b))

if __name__=='__main__':
    main()