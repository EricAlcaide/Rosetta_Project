def isPalindrome(n):
    str1=str(n)
    str2 = str1[::-1]
    if str1==str2:
        return True
    else:
        return False

n=int(input())
if isPalindrome(n):
    print('Yes')
else:
    print('No')                