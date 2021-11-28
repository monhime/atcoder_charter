def main():
    import sys
    input = sys.stdin.readline #文字列をsplit()しない場合s=s[:-2]が必要

    n=int(input())
    D=[int(_) for _ in input().split()]
    D.sort()
    print(D[n//2]-D[n//2-1])

if __name__=='__main__':
    main()