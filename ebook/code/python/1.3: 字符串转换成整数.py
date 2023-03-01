# code example for Section 1.3 字符串转换成整数

# Given a string, convert it to a integer without using the int()
# For example, from '124'to 124


# Author: Steven S.L. Xie
# Email: stevenslxie at gmail.com
# Last updated: 2014, Dec, 27
def empty_check(s):
    if s == '' or s is None:
        return False
    return True
        
def sign_check(n):
    if n[0] == '-':
        n.pop(0)
        return n, -1
    return n,1
    
def illegal_symbol_check(char):
    if not (char>=0 and char<=9):
        return False
    return True

def str_to_int(s):
    if not empty_check(s):
        return 'Illegal input.'
    n = list(s)
    n, flag = sign_check(n)
    l = len(n)
    
    sum = 0
    for i in range(l):
        tmp = ord(n[l-i-1])-ord('0')
        
        if not illegal_symbol_check(tmp):
            return 'Illegal symbols'
            
        sum += 10**i*tmp
    # Python can automatically promote integers to higher precision type. So there is no need to check for overflow.
    return sum*flag
    

print str_to_int('')
print str_to_int('  ')
print str_to_int('-125964')
print str_to_int('1259648888888888888888888888')

