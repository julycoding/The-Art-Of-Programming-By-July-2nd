/*
 * By Frederick-S
 * 2014-01-23
 */

// 1. 暴力轮询

/*
 * @param {String} a 较长的字符串
 * @param {Number} b 较短的字符串
 * @example
 * var result = compare1('ABCDEFGHLMNOPQRS', 'DCGSRQPO');
 */
function compare1(a, b) {
    var i, j, m = b.length, n = a.length;

    for (i = 0; i < m; i++) {
        for (j = 0; j < n && a[j] != b[i]; j++)
            ;

        if (j == n) {
            return false;
        }
    };

    return true;
}

// 2. 普通排序

/*
 * @param {String} a 较长的字符串
 * @param {Number} b 较短的字符串
 * @example
 * var result = compare2('ABCDEFGHLMNOPQRS', 'DCGSRQPO');
 */
function compare2(a, b) {
    a = a.split('').sort();
    b = b.split('').sort();

    for (var i = 0, j = 0, m = b.length, n = a.length; j < m; j++) {
        for (; i < n && a[i] < b[j]; i++)
            ;

        if (i == n || a[i] > b[j]) {
            return false;
        }
    }

    return true;
}

// 3. 计数比较

/*
 * @param {String} a 较长的字符串
 * @param {Number} b 较短的字符串
 * @example
 * var result = compare3('ABCDEFGHLMNOPQRS', 'DCGSRQPO');
 */
function compare3(a, b) {
    var occurrences = new Array(26), m = b.length, n = a.length, index;

    for (var i = 0; i < n; i++) {
        index = a[i].charCodeAt(0) - 'A'.charCodeAt(0);
        occurrences[index]++ || (occurrences[index] = 1);
    }

    for (var j = 0; j < m; j++) {
        index = b[j].charCodeAt(0) - 'A'.charCodeAt(0);
        if (!occurrences[index]) {
            return false;
        }
    }

    return true;
}

// 4. 巧用 hashtable

/*
 * @param {String} a 较长的字符串
 * @param {Number} b 较短的字符串
 * @example
 * var result = compare4('ABCDEFGHLMNOPQRS', 'DCGSRQPO');
 */
function compare4(a, b) {
    var obj = {}, k = 0, m = b.length, n = a.length, index;

    for (var i = 0; i < m; i++) {
        if (!obj[b[i]]) {
            obj[b[i]] = 1;
            k++;
        }
    }

    for (var j = 0; j < n; j++) {
        if (obj[a[j]]) {
            k--;
            obj[a[j]] = 0;
        }
    }

    return k === 0;
}

// 5. 素数相乘
// 此方法只有理论意义, 因为整数乘积很大, 会溢出

/*
 * @param {String} a 较长的字符串
 * @param {Number} b 较短的字符串
 * @example
 * var result = compare5('ABCDEFGHLMNOPQRS', 'DCGSRQPO');
 */
function compare5(a, b) {
    var primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101], m = b.length, n = a.length, p = 1, t, index;

    for (var i = 0; i < n; i++) {
        index = a[i].charCodeAt(0) - 'A'.charCodeAt(0);
        t = primes[index];

        if (p % t) {
            p *= t;
        }
    }

    for (var j = 0; j < m; j++) {
        index = b[j].charCodeAt(0) - 'A'.charCodeAt(0);
        t = primes[index];

        if (p % t) {
            return false;
        }
    }

    return true;
}

// 6. 位运算

/*
 * @param {String} a 较长的字符串
 * @param {Number} b 较短的字符串
 * @example
 * var result = compare6('ABCDEFGHLMNOPQRS', 'DCGSRQPO');
 */
function compare6(a, b) {
    var hash = 0, m = b.length, n = a.length, index;

    for (var i = 0; i < n; i++) {
        index = a[i].charCodeAt(0) - 'A'.charCodeAt(0);
        hash |= 1 << index;
    }

    for (var j = 0; j < m; j++) {
        index = b[j].charCodeAt(0) - 'A'.charCodeAt(0);
        if ((hash & (1 << index)) === 0) {
            return false;
        }
    }

    return true;
}
