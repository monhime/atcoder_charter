h,w=map(int,input().split())
s=[input() for i in range(h)]
s=[s_x for s_x in s if '#' in s_x]
s=[s_y for s_y in zip(*s) if '#' in s_y]
for ss in zip(*s):
    print(''.join(ss))
    