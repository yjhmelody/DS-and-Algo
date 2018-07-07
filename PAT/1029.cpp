#include <iostream>
#include <climits>
#include <queue>

using namespace std;

// 卡内存，需要用到队列
int main() {
    queue<int> a, b;
    int n, m, count = 0;

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        long long v;
        scanf("%lld", &v);
        a.push(v);
    }
    a.push(INT_MAX);

    scanf("%d", &m);
    // 边读边处理
    for(int i = 0; i < m; i++) {
        long long v;
        scanf("%lld", &v);
        b.push(v);
        if(count == (n + m - 1) / 2) {
            printf("%d\n", min(a.front(), b.front()));
            return 0;
        }
        if(a.front() < b.front()) {
            a.pop();
        }
        else {
            b.pop();
        }
        count++;
    }
    b.push(INT_MAX);

    for(; count < (n + m - 1) / 2; count++) {
        if(a.front() < b.front()) {
            a.pop();
        }
        else {
            b.pop();
        };
    }
    printf("%d\n", min(a.front(), b.front()));
    return 0;
}
