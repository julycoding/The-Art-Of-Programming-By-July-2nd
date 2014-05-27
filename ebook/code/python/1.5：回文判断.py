# code example for section 1.5
# see https://github.com/julycoding/The-Art-Of-Programming-By-July/blob/master/ebook/zh/01.05.md
# 
# author jiang
# email  mail.jiang.cn@gmail.com
# created on 2014-5-27


def is_palindrome1(s):
  """
  code example for section 1.5 solution 1

  compatible with python 2.7.X and python 3.X
  """
  if not isinstance(s,str):
    raise ValueError('Please input a string!')
  front, back = 0, len(s)-1
  while front < back:
    if s[front] != s[back]:
      return False
    front += 1
    back -= 1
  return True


def is_palindrome2(s):
  """
  code example for section 1.5 solution 2

  compatible with python 2.7.X and python 3.X
  """
  if not isinstance(s,str):
    raise ValueError('Please input a string!')
  if len(s) % 2 == 0:
    # Python 3.X 中 x/y 的结果不是int，故需转换
    forward, backward = int((len(s)/2)-1), int(len(s)/2)
  else:
    forward, backward = int(len(s)/2), int(len(s)/2)
  while backward < len(s):
    if s[forward] != s[backward]:
      return False
    backward += 1
    forward -= 1
  return True


if __name__ == "__main__":
  s1 = 'abba'
  s2 = 'a'
  s3 = 'aca'
  s4 = 'aacc'
  print(is_palindrome1(s1))
  print(is_palindrome1(s2))
  print(is_palindrome1(s3))
  print(is_palindrome1(s4))
  print(is_palindrome2(s1))
  print(is_palindrome2(s2))
  print(is_palindrome2(s3))
  print(is_palindrome2(s4))
  try:
    print(is_palindrome1(2))
  except ValueError as e:
    print(e)
