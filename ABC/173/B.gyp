import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n = int(input())
    ac, wa, tle, re =0, 0, 0, 0
    for i in range(n):
        s = input()
        if s == "AC":
            ac += 1
        elif s == "WA":
            wa += 1
        elif s == "TLE":
            tle += 1
        else:
            re += 1

    print("AC x {}".format(ac))
    print("WA x {}".format(wa)) 
    print("TLE x {}".format(tle))
    print("RE x {}".format(re))

if __name__=='__main__':
    main()