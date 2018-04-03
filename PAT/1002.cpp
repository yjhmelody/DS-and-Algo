#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int k1, k2;

    cin >> k1;
    vector<int> a;
    vector<double> coe1;
    for(int i = 0; i < k1; i++) {
        int temp_exp;
        double temp_coe;
        cin >> temp_exp;
        cin >> temp_coe;
        a.push_back(temp_exp);
        coe1.push_back(temp_coe);
    }

    cin >> k2;
    vector<int> b;
    vector<double> coe2;
    for(int i = 0; i < k2; i++) {
        int temp_exp;
        double temp_coe;
        cin >> temp_exp;
        cin >> temp_coe;
        b.push_back(temp_exp);
        coe2.push_back(temp_coe);
    }

    vector<int> sum;
    vector<double> coe3;

    auto it = a.begin();
    auto it2 = b.begin();
    auto it_coe1 = coe1.begin();
    auto it_coe2 = coe2.begin();
    while(it != a.end() && it2 != b.end()) {
        if(*it > *it2) {
            sum.push_back(*it);
            coe3.push_back(*it_coe1);
            it++;
            it_coe1++;
        } else if(*it < *it2) {
            sum.push_back(*it2);
            coe3.push_back(*it_coe2);
            it2++;
            it_coe2++;
        } else {
            if(*it_coe1 + *it_coe2 != 0.0) {
                sum.push_back(*it);
                coe3.push_back(*it_coe1 + *it_coe2);
            }
            it++;
            it_coe1++;
            it2++;
            it_coe2++;
        }
    }

    for(;it != a.end(); it++, it_coe1++) {
        sum.push_back(*it);
        coe3.push_back(*it_coe1);
    }

    for(;it2 != b.end(); it2++, it_coe2++) {
        sum.push_back(*it2);
        coe3.push_back(*it_coe2);
    }


//    cout << sum.size() << " ";
    int count = 0;
    for_each(coe3.begin(), coe3.end(), [&count](double num) {
        if(num == 0) {
            return;
        }
        count++;
    });
    cout << count << " ";
    auto it_coe3 = coe3.begin();
    for (auto it = sum.begin(); it != sum.end(); it++, it_coe3++) {
        if (it+1 == sum.end()) {
            printf("%d %.1f\n", *it, *it_coe3);
            break;
        }
        if (*it_coe3 == 0.0) {
            continue;
        }
        printf("%d %.1f ", *it, *it_coe3);
    }
    return 0;
}
