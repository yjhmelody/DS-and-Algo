#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

struct rational {
    long long numerator;
    long long denomerator;
};

template<typename T>
T gcd(T a, T b) {
    if(a == 0 || b == 0) {
        return 0;
    }
    if(a < b) {
        swap(a, b);
    }
    while(a % b) {
        T temp = a % b;
        a = b;
        b = temp;
    }
    return b;
}

int main() {
    int N;
    cin >> N;
    char sep;
    vector<rational> nums(N);

    for(auto &x: nums) {
        cin >> x.numerator;
        cin >> sep;
        cin >> x.denomerator;
    }

    long long numerator = 0;
    long long denomerator = 1;
    for(auto &x: nums) {
        // reduce first
        long long temp = gcd(x.numerator, x.denomerator);
        if(temp == 0) {
            continue;
        }
        x.numerator /= temp;
        x.denomerator /= temp;
        numerator = x.numerator * denomerator + x.denomerator * numerator;
        denomerator *= x.denomerator;
        // reduce
        temp = gcd(numerator, denomerator);
        if(temp == 0) {
            continue;
        }
        numerator /= temp;
        denomerator /= temp;
    }

    rational ans;
    // reduce the rational
    long long temp = gcd(numerator, denomerator);
    if(temp == 0) {
        cout << 0 << endl;
        return 0;
    }
    ans.numerator = numerator / temp;
    ans.denomerator = denomerator / temp;

    if(ans.denomerator < 0) {
        ans.numerator = -ans.numerator;
        ans.denomerator = -ans.denomerator;
    }
    long long mod = ans.numerator % ans.denomerator;
    long long div = ans.numerator / ans.denomerator;
    if(ans.numerator < ans.denomerator) {
        cout << ans.numerator << "/" << ans.denomerator << endl;
    }
    else if(mod == 0) {
        cout << div << endl;
    }
    else {
        cout << div << " " << mod << "/" << ans.denomerator << endl;
    }
    return 0;
}
