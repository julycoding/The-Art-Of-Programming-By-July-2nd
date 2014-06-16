/*
 * By Frederick-S
 * 2014-03-08
 */

// 1. 穷举

/*
 * @param {Array} arr 目标数组
 * @param {Number} number 在数组中查找两个数，使得其和为 number
 * @example
 * var arr = solution1([1, 2], 3);
 */
function solution1(arr, number) {
    for (var i = 0, length = arr.length; i < length; i++) {
        for (var j = i + 1; j < length; j++) {
            if (arr[i] + arr[j] == number) {
                return [arr[i], arr[j]];
            }
        }
    }

    return [];
}

// 2. 二分查找

/*
 * @param {Array} arr 目标数组
 * @param {Number} number 在数组中查找两个数，使得其和为 number
 * @example
 * var arr = solution2([1, 2], 3);
 */
function solution2(arr, number) {
    arr.sort(function (a, b) {
        return a - b;
    });

    var index = 0;
    for (var i = 0, length = arr.length; i < length; i++) {
        index = binarySearch(arr, number - arr[i], 0, length - 1);

        if (index >= 0 && index != i) {
            return [arr[i], arr[index]];
        }
    }

    return [];
}

function binarySearch(arr, key, low, high) {
    var mid = 0;

    while (low <= high) {
        mid = Math.floor((low + high) / 2);

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] > key) {
            high -= 1;
        } else if (arr[mid] < key) {
            low += 1;
        }
    }

    return -1;
}

// 3. 双数组指针扫描

/*
 * @param {Array} arr 目标数组
 * @param {Number} number 在数组中查找两个数，使得其和为 number
 * @example
 * var arr = solution3([1, 2], 3);
 */
function solution3(arr, number) {
    var subtraction = arr.map(function (value, index, array) {
        return number - value;
    });

    arr.sort(function (a ,b) {
        return a - b;
    })

    subtraction.sort(function (a, b) {
        return b - a;
    })

    var i = 0, length = arr.length, j = length - 1;

    while (i < length && j > -1) {
        if (arr[i] < subtraction[j]) {
            i++;
        } else if (arr[i] > subtraction[j]) {
            j--;
        } else {
            if (i != j) {
                return [arr[i], number - arr[i]];
            }
        }
    }

    return [];
}

// 4. 借助 hash

/*
 * @param {Array} arr 目标数组
 * @param {Number} number 在数组中查找两个数，使得其和为 number
 * @example
 * var arr = solution4([1, 2], 3);
 */
function solution4(arr, number) {
    var hash = {};

    arr.forEach(function (value, index, array) {
        hash[value] = value;
    });

    for (var i = 0, length = arr.length; i < length; i++) {
        if (hash[number - arr[i]]) {
            return [arr[i], number - arr[i]];
        }
    }

    return [];
}

// 5. 双指针两端扫描

/*
 * @param {Array} arr 目标数组
 * @param {Number} number 在数组中查找两个数，使得其和为 number
 * @example
 * var arr = solution5([1, 2], 3);
 */
function solution5(arr, number) {
    var i = 0, j = arr.length - 1;

    arr.sort(function (a, b) {
        return a - b;
    })

    while (i < j) {
        if (arr[i] + arr[j] > number) {
            j--;
        } else if (arr[i] + arr[j] < number) {
            i++;
        } else {
            return [arr[i], arr[j]];
        }
    }

    return [];
}
