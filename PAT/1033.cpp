#include<iostream>
#include<vector>
#include<cstdio>
#include<climits>
#include<algorithm>

using namespace std;

// 贪心算法，在 n 位置时，找出它可以走到的最便宜的站点 m，
// 如果 m 比 n 便宜此时到 m 时刚好用完gas。
// 如果 n 比 m 便宜此时 n 装满，再到 m。

int cap;
int dis;
int avg_dis;
int N;

using Station = pair<double,double>;

/// 下一个最佳站点、补给前油量、补给后油量
pair<Station, pair<double, double>> get_best_station(vector<Station> &s, double price, int pos, int max_dis) {
    int i = 0;
    for(; i < s.size(); i++) {
        if(s[i].second > pos) {
            break;
        }
    }
    int j = i;
    for(; j < s.size(); j++) {
        if(s[j].second > max_dis) {
            break;
        }
    }

    // 最便宜的站点
    double min_price = s[i].first;
    int station_id = i;
    for(int k = i+1; k < j; k++) {
        if(s[k].first < min_price) {
            min_price = s[k].first;
            station_id = k;
        }
    }

    // n 这里存储 gas
    double gas;
    if(min_price > price) {
        gas = (max_dis - pos) / double(avg_dis);
    }
    // 装满
    else {
        gas = (double)cap;
    }
    return pair<Station, pair<double, double>>(s[station_id], {, gas});
}

int main() {

    cin >> cap >> dis >> avg_dis >> N;

    vector<Station> nums(N);
    for(auto &x: nums) {
        cin >> x.first >> x.second;
    }

    sort(nums.begin(), nums.end(), [](Station &s1, Station &s2) {
         return s1.second < s2.second;
    });

    double stop = nums[N-1].second + avg_dis * cap;
    if(stop < dis) {
        printf("The maximum travel distance = %.2f\n", stop);
        return 0;
    }

    nums.push_back(Station{0, dis});

    double money = 0;
    auto station = nums[0];
    // 一开始没有油
    double gas = 0;
    for(int pos = 0; pos < dis;) {
        int max_dis = pos + avg_dis * cap;
        double price = station.first;

        auto ret = get_best_station(nums, price, pos, max_dis);
        auto new_station = ret.first;
        double new_gas = ret.second;
        double new_pos = new_station.second;


        money += (new_gas - gas) * price;
        pos = new_pos;
        gas = new_gas;
        station = new_station;

        cout << money << endl;
    }
    return 0;
}
