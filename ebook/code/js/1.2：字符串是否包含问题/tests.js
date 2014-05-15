// 1. 暴力轮询
test('暴力轮询', function () {
    ok(compare1('ABCDEFGHLMNOPQRS', 'DCGSRQPO') == true, 'ABCDEFGHLMNOPQRS 包含 DCGSRQPO');
    ok(compare1('ABCDEFGHLMNOPQRS', 'DCGSRQPZ') == false, 'ABCDEFGHLMNOPQRS 不包含 DCGSRQPZ');
    ok(compare1('QWERTY', 'QRY') == true, 'QWERTY 包含 QRY');
    ok(compare1('QWERTY', 'QERATY') == false, 'QWERTY 不包含 QERATY');
});

// 2. 普通排序
test('普通排序', function () {
    ok(compare2('ABCDEFGHLMNOPQRS', 'DCGSRQPO') == true, 'ABCDEFGHLMNOPQRS 包含 DCGSRQPO');
    ok(compare2('ABCDEFGHLMNOPQRS', 'DCGSRQPZ') == false, 'ABCDEFGHLMNOPQRS 不包含 DCGSRQPZ');
    ok(compare2('QWERTY', 'QRY') == true, 'QWERTY 包含 QRY');
    ok(compare2('QWERTY', 'QERATY') == false, 'QWERTY 不包含 QERATY');
});

// 3. 计数比较
test('计数比较', function () {
    ok(compare3('ABCDEFGHLMNOPQRS', 'DCGSRQPO') == true, 'ABCDEFGHLMNOPQRS 包含 DCGSRQPO');
    ok(compare3('ABCDEFGHLMNOPQRS', 'DCGSRQPZ') == false, 'ABCDEFGHLMNOPQRS 不包含 DCGSRQPZ');
    ok(compare3('QWERTY', 'QRY') == true, 'QWERTY 包含 QRY');
    ok(compare3('QWERTY', 'QERATY') == false, 'QWERTY 不包含 QERATY');
});

// 4. 巧用 hashtable
test('巧用 hashtable', function () {
    ok(compare4('ABCDEFGHLMNOPQRS', 'DCGSRQPO') == true, 'ABCDEFGHLMNOPQRS 包含 DCGSRQPO');
    ok(compare4('ABCDEFGHLMNOPQRS', 'DCGSRQPZ') == false, 'ABCDEFGHLMNOPQRS 不包含 DCGSRQPZ');
    ok(compare4('QWERTY', 'QRY') == true, 'QWERTY 包含 QRY');
    ok(compare4('QWERTY', 'QERATY') == false, 'QWERTY 不包含 QERATY');
});

// 5. 素数相乘 (仅限理论验证)
test('素数相乘 (仅限理论验证)', function () {
    ok(compare5('ABCDEFG', 'DCG') == true, 'ABCDEFG 包含 DCG');
    ok(compare5('ABCDEFG', 'DCGZ') == false, 'ABCDEFG 不包含 DCGZ');
    ok(compare5('QWERTY', 'QRY') == true, 'QWERTY 包含 QRY');
    ok(compare5('QWERTY', 'QERATY') == false, 'QWERTY 不包含 QERATY');
});

// 6. 位运算
test('位运算', function () {
    ok(compare6('ABCDEFGHLMNOPQRS', 'DCGSRQPO') == true, 'ABCDEFGHLMNOPQRS 包含 DCGSRQPO');
    ok(compare6('ABCDEFGHLMNOPQRS', 'DCGSRQPZ') == false, 'ABCDEFGHLMNOPQRS 不包含 DCGSRQPZ');
    ok(compare6('QWERTY', 'QRY') == true, 'QWERTY 包含 QRY');
    ok(compare6('QWERTY', 'QERATY') == false, 'QWERTY 不包含 QERATY');
});
