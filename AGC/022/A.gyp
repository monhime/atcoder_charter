import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    s=input()
    if len(s)==26:
        for i in range(25,0,-1):
            if s[i]<s[i-1]:
                continue
            else:
                sx=s[i-1]
                for j in range(1,25):
                    sy=chr(ord(sx)+j)
                    if sy in s[i:]:
                        print(s[:i-1]+sy)
                        sys.exit()
        else:
            print(-1)
    else:
        for i in range(26):
            if chr(ord('a')+i) in s:
                continue
            print(s+chr(ord('a')+i))
            break

if __name__=='__main__':
    main()