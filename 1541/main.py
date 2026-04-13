import sys
import re

s = sys.stdin.readline().rstrip().split('-', maxsplit=1)
if len(s) == 2:
    print(sum(map(int,s[0].split('+'))) - sum(map(int,re.split(r'[+-]', s[1]))))
else:
    print(sum(map(int,s[0].split('+'))))