#include<iostream>
#include<string>
#include<map>
#include<algorithm>

// 注意几点：
// 1. 一定都要用Long long int，不然会错很多case;

// 2. 注意计算radix的值时，有可能会发生溢出，得到的result结果为负数，此时应该减少radix的值;

// 3. 不能使用简单的顺序搜索算法，应该使用二分法搜索；

// 除了只有一位数时候可能出现多个解，其余情况均只有一个解。

// 二分法搜索能够保证得到的结果唯一并且正确。

using namespace std;

void init_map(map<char, long long>& alpha) {
    long long i = 0;
    for(char ch = '0'; ch <= '9'; ch++, i++) {
        alpha.insert(pair<char, long long>(ch, i));
    }
    for(char ch = 'a'; ch <= 'z'; ch++, i++) {
        alpha.insert(pair<char, long long>(ch, i));
    }
}

long long convert_to_decimal(string& num, long long radix, map<char, long long>& alpha) {
    long long ret = 0;
    for(auto &x: num) {
        ret = ret * radix + alpha[x];
    }
    return ret;
}

long long get_radix(string& num, map<char, long long>& alpha) {
    long long radix = -1;
    for(auto &x: num) {
        if(alpha[x] > radix) {
            radix = alpha[x];
        }
    }
    return radix + 1;
}

int cmp(string& num, long long radix, long long val, map<char, long long>& alpha) {
    long long val2 = 0;
    for(auto &x: num) {
        val2 = val2 * radix + alpha[x];
        if(val2 > val) {
            return 1;
        }
    }
    int ret = val2 == val ? 0 : -1;
    ret = val2 > val ? 1 : ret;
    return ret;
}

long long binary_search(string& num, long long left, long long right, long long val, map<char, long long>& alpha) {
    long long mid;
    while(left <= right) {
        mid = (left + right) / 2;
        int flag = cmp(num, mid, val, alpha);
        if(flag == 0) {
            return mid;
        }
        else if(flag == 1) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    string N1;
    string N2;
    int tag;
    long long radix;
    map<char, long long> alpha;
    init_map(alpha);
    cin >> N1 >> N2 >> tag >> radix;

    // Samplify computing
    if (tag == 2) {
        swap(N1, N2);
    }

    long long num = convert_to_decimal(N1, radix, alpha);
    long long num2 = convert_to_decimal(N2, radix, alpha);
    // may be overflow
    if(N1 == N2) {
        cout << radix << endl;
        return 0;
    }
    if(num == 1 && num2 == 1) {
        cout << "2" << endl;
        return 0;
    }
    long long min_radix = get_radix(N2, alpha);
    // trap
    long long max_radix = max(min_radix, num) + 1;
    long long ret = binary_search(N2, min_radix, max_radix, num, alpha);
    if(ret != -1) {
        cout << ret << endl;
    }
    else {
        cout << "Impossible" << endl;
    }
    return 0;
}
