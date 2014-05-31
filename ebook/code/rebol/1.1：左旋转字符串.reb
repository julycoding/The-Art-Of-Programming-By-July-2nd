REBOL [
	Title: "字符串旋转问题,例如abcdef,左旋2位,变成 cdefab"
       Date: 2014-03-30
       File:  %1.1：左旋转字符串.reb
       Author: "network061(yping061@gmail.com)"
       Version: 1.0.0
]
;Version 1
leftShift1: func[
                "暴力移位法"
                str [ string! ] 
                m  [ integer! ] ;要左旋的位数
][ 
    while[ m > 0] [
          left_shift_one str
          -- m
     ]
     return str
]

 left_shift_one:  func [   
                 str [ string! ]  ;字符串
                 /local  temp index ;temp用于交换位置时临时存放字符   index 遍历字串的索引变量
            
] [
     assert [ str  != null]
     temp: str/1 ;保存第一个字符,rebol语言特性:整数索引从1开始,数对(pair!类型,例如像素大小)索引从0开始
     index: 2
      while [ index <= length? str] [
        str/(index - 1): str/:index 
         ++ index
      ]
      str/(length? str): temp
]

;Version 2  三步反转法
leftShift2: func[
              str [ string! ]
              m  [ integer! ]
][
     m %= length? str
     reverse str 1 m
     reverse str m + 1 length? str
     reverse str 1 length? str

     return str
]

reverse: func[
            str [ string! ]
            start [ integer! ]
            end [ integer! ]
            /local temp 
][
    while[ start <= end][
        temp: str/:start
        str/:start: str/:end
        str/:end: temp
        ++ start
        -- end
    ]
]

str: "abcdefghijk"
print [ "The origin str is " str ]
print [ "Left Shift  V1 :" leftShift1 str 6 ]
print [ "Left Shift  V2 :" leftShift2 str 6 ]
