#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <array>

using namespace std;

struct record {
    string name;
    array<int, 5> time; // month day hour min totalTime
    bool status;
};

double getBill(record& r1, array<int, 25>& toll) {
    // 从第一天到今天这一时间的费用，之后用差值来计算实际费用
    double total = toll[r1.time[2]] * r1.time[3] + toll[24] * 60 * r1.time[1];
    int count = 0;
    for(int i = 0; i < r1.time[2]; i++) {
        total += toll[i] * 60;
        count ++;
    }
    // cents
    return total / 100.0;
}

void print(record& r1, record& r2) {
    printf("%02d:%02d:%02d %02d:%02d:%02d", r1.time[1], r1.time[2], r1.time[3], r2.time[1], r2.time[2], r2.time[3]);
    int time = r2.time[4] - r1.time[4];
    printf(" %d ", time);
}


int main() {
    array<int, 25> toll;
    //! forget to init
    toll[24] = 0;
    for(auto it = toll.begin(); it != toll.end()-1; it++) {
        cin >> *it;
        toll[24] += *it;
    }
    int N;
    cin >> N;
    vector<record> records(N);
    for(auto &x: records) {
        cin >> x.name;
        scanf("%d:%d:%d:%d", &x.time[0], &x.time[1], &x.time[2], &x.time[3]);
        string temp;
        cin >> temp;
        x.status = temp == "on-line" ? true : false;
        x.time[4] = x.time[3] + x.time[2] * 60 + x.time[1] * 60 * 24;
    }

    sort(records.begin(), records.end(), [](record r1, record r2) {
         if(r1.name != r2.name) {
            return r1.name < r2.name;
         }
         return r1.time[4] < r2.time[4];
    });

    map<string, vector<record>> customs;
    for(int i = 1; i < N; i++) {
        if(records[i].name == records[i-1].name && records[i].status == false && records[i-1].status == true) {
            customs[records[i].name].push_back(records[i-1]);
            customs[records[i].name].push_back(records[i]);
        }
    }
    for(auto &custom: customs) {
        auto recs = custom.second;
        cout << custom.first;
        printf(" %02d\n", recs[0].time[0]);
        double total = 0.0;
        // i+=2
        for(int i = 1; i < recs.size(); i+=2) {
            print(recs[i-1], recs[i]);
            double t = getBill(recs[i], toll) - getBill(recs[i-1], toll);
            printf("$%.2f\n", t);
            total += t;
        }
        printf("Total amount: $%.2f\n", total);
    }
    return 0;
}

