#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

template<typename T>
T gcd(T a, T b) {
   if(b == 0) return a;
   return gcd(b, a%b);
}

struct rational {
    long long numerator;
    long long denomerator;
};

void transform(rational& rat);

rational cal(rational& a, rational& b, char flag) {
    long long denomerator = 1;
    long long numerator = 0;
    denomerator = a.denomerator * b.denomerator;

    if(flag == '+') {
        numerator = a.denomerator * b.numerator + a.numerator * b.denomerator;
    }
    else if(flag == '-') {
        numerator = a.numerator * b.denomerator - a.denomerator * b.numerator;
    }
    else if(flag == '*') {
        numerator = a.numerator * b.numerator;
    }
    else if(flag == '/') {
        denomerator = a.denomerator * b.numerator;
        numerator = a.numerator * b.denomerator;
    }
    rational rat = {numerator, denomerator};
    transform(rat);
    return rat;
}

void transform(rational& rat) {
    if (rat.numerator == 0) {
        rat.denomerator = 1;
    }
    else if(rat.denomerator < 0) {
        rat.denomerator = -rat.denomerator;
        rat.numerator = -rat.numerator;
    }
    else {
        auto temp = gcd(abs(rat.numerator), rat.denomerator);
        rat.numerator /= temp;
        rat.denomerator /= temp;
    }
}

void print(rational& rat){
    transform(rat);

    if(rat.numerator < 0) {
        cout << "(";
    }

    if(rat.denomerator == 1) {
        cout << rat.numerator;
    }
    else if(abs(rat.numerator) > rat.denomerator) {
        cout << rat.numerator / rat.denomerator << " " << abs(rat.numerator) % rat.denomerator << "/" << rat.denomerator;
    }
    else {
        cout << rat.numerator << "/" << rat.denomerator;
    }

    if(rat.numerator < 0)
        cout << ")";
}

int main() {
    vector<rational> rats(2);
    vector<char> ops{'+', '-', '*', '/'};
    char ch;
    for(auto &x: rats) {
        cin >> x.numerator >> ch >> x.denomerator;
        transform(x);
        long long temp = gcd(x.numerator, x.denomerator);
        if(temp == 0) {
            continue;
        }
        x.numerator /= temp;
        x.denomerator /= temp;
    }

    for(auto op: ops) {
        print(rats[0]);
        cout << " " << op << " ";
        print(rats[1]);
        cout << " = ";
        auto ans = cal(rats[0], rats[1], op);
        if(op == '/' && rats[1].numerator == 0) {
            cout << "Inf" << endl;
            continue;
        }
        print(ans);
        cout << endl;
    }
    return 0;
}
