# -*- coding:utf-8 -*-


def more_than_half_number(array):
    if not array:
        return False

    count = 1
    value = array[0]
    for i in range(1, len(array) - 1):
        if array[i] == value:
            count += 1
        else:
            count -= 1
            if count == 0:
                value = array[i]
                count = 1
    count = sum(item == value for item in array)
    if count * 2 > len(array):
        return value


if __name__ == '__main__':
    print more_than_half_number([0, 3, 1, 3, 2, 3, 4, 3, 3, 3])
