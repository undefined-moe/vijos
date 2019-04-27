#include <cmath>
#include <cstring>
#include <iostream>
#include <memory.h>
#include <vector>
using namespace std;

int n, s;
int a[5100], c[5100];
vector<int> vec;

void times(int data) {
    memset(c, 0, sizeof(c));
    int t = data, cnt = 0;
    vec.clear();
    vec.push_back(0);
    while (t) {
        vec.push_back(t % 10);
        t /= 10;
        cnt++;
    }
    for (int i = 1; i <= 5000; i++)
        for (int j = 1; j <= cnt; j++)
            c[i + j - 1] += a[i] * vec[j];
    for (int i = 1; i <= 5000; i++) {
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }
    memcpy(a, c, sizeof(c));
    return;
}
bool prime(int op) {
    if (op < 2) return false;
    if (op == 2) return true;
    for (int i = 2; i < floor(sqrt(op)); i++)
        if (op % i == 0) return false;
    return true;
}
int main() {
    cin >> n;
    memset(a, 0, sizeof(a));
    a[1] = 1;
    for (int i = 2; i <= n; i++) times(i);
    int i = 5010;
    while (c[i] == 0) i--;
    for (; i >= 1; i--) s += c[i];
    cout << s;
    if (prime(s))
        cout << 'T' << endl;
    else
        cout << 'F' << endl;
    return 0;
}