# code example for Section 1.3 字符串转换成整数

# Given a string, convert it to a integer without using the int()
# For example, from '124'to 124


def str_to_int(s):
    # empty check
    if s == '':
        return 'The input is illegal!'
        
    n = list(s)
    
    # sign check
    flag = 1
    if n[0] == '-':
        flag = -1
        n.pop(0)
        
    l = len(n)
    
    sum = 0
    for i in range(l):
        tmp = ord(n[l-i-1])-ord('0')
        
        if not (tmp>=0 and tmp<=9):
            return 'Illegal symbols'
            
        sum += 10**i*tmp
    # Python can automatically promote integers to higher precision type. So there is no need to check for overflow.
    
    return sum*flag
    
print str_to_int('')
print str_to_int('  ')
print str_to_int('-125964')
print str_to_int('1259648888888888888888888888')
