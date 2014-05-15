// 1. 暴力移位法
test('暴力移位法', function () {
    ok(leftShift1('abcdef', 0) == 'abcdef', 'abcdef 左旋转 0 位变成 abcdef');
    ok(leftShift1('abcdef', 2) == 'cdefab', 'abcdef 左旋转 2 位变成 cdefab');
    ok(leftShift1('abcdef', 6) == 'abcdef', 'abcdef 左旋转 6 位变成 abcdef');
    ok(leftShift1('abcdef', 8) == 'cdefab', 'abcdef 左旋转 8 位变成 cdefab');
    ok(leftShift1('abcdef', 15) == 'defabc', 'abcdef 左旋转 15 位变成 defabc');
});

// 2. 三步翻转法
test('三步翻转法', function () {
    ok(leftShift2('abcdef', 0) == 'abcdef', 'abcdef 左旋转 0 位变成 abcdef');
    ok(leftShift2('abcdef', 2) == 'cdefab', 'abcdef 左旋转 2 位变成 cdefab');
    ok(leftShift2('abcdef', 6) == 'abcdef', 'abcdef 左旋转 6 位变成 abcdef');
    ok(leftShift2('abcdef', 8) == 'cdefab', 'abcdef 左旋转 8 位变成 cdefab');
    ok(leftShift2('abcdef', 15) == 'defabc', 'abcdef 左旋转 15 位变成 defabc');
});
