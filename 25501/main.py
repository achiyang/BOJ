def recursion(s, l, r, d=1):
    if l >= r: return 1, d
    elif s[l] != s[r]: return 0, d
    else: return recursion(s, l+1, r-1, d+1)

def isPalindrome(s):
    return recursion(s, 0, len(s)-1)

n = int(input())

for i in range(n):
    print(" ".join(map(str, isPalindrome(input()))))