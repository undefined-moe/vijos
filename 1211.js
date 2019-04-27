[y, m, d] = readline().split(' ')
data = [0, 31, 31, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
function spc(y) {
    return (y % 400 == 0) ? (true) :
        ((y % 100 == 0) ? false : ((y % 4 == 0) ? true : false))
}
for (var i = 1; i <= 10000; i++) {
    d++;
    if (d > data[m]) {
        d = 1;
        m++;
    }
    if (m == 2 && d > (spc(y) ? 29 : 28)) {
        d = 1;
        m++;
    }
    if (m > 12) {
        m = 1;
        y++;
    }
}
print(y + '-' + m + '-' + d);