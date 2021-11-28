import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    a, v = map(int,input().split())
    b, w = map(int,input().split())
    t = int(input())
    if v <= w or (v-w)*t < abs(a-b):
        print("NO")
    else:
        print("YES")

if __name__=='__main__':
    main()