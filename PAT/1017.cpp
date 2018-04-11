#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>

using namespace std;

struct custom {
    int hour;
    int min;
    int second;
    // min
    int wait_time;
};

int get_time(custom &c1) {
    return ((c1.hour * 60) + c1.min) * 60 + c1.second;
}

int main() {
    int N;
    int K;
    cin >> N >> K;
    vector<custom> customs;

    for(int i = 0; i < N; i++) {
        custom x;
        scanf("%d:%d:%d%d", &x.hour, &x.min, &x.second, &x.wait_time);
        if(x.wait_time > 60) {
            x.wait_time = 60;
        }
        else if(x.hour >= 17) {
            continue;
        }
        customs.push_back(x);
    }
    sort(customs.begin(), customs.end(), [](custom &c1, custom &c2) {
        int t1 = ((c1.hour * 60) + c1.min) * 60 + c1.second;
        int t2 = ((c2.hour * 60) + c2.min) * 60 + c2.second;
        if(t1 < t2) {
            return true;
        }
        return false;
    });

    vector<int> windows(K, 8 * 60 * 60);
    int total = 0;
    for(int i = 0; i < customs.size(); i++) {
        // 最先空出位置的窗口
        int first_index = 0;
        int min_time = windows[0];
        for(int j = 1; j < K; j++) {
            if(min_time > windows[j]) {
                first_index = j;
                min_time = windows[j];
            }
        }

        // 来迟了
        int time = get_time(customs[i]);
        if(windows[first_index] <= time) {
            windows[first_index] = time + customs[i].wait_time * 60;
        }
        // 来早了
        else {
            total += windows[first_index] - time;
            windows[first_index] += customs[i].wait_time * 60;
        }
    }

    if(customs.size() == 0) {
        cout << "0.0" << endl;
    }
    else {
        printf("%.1f\n", total / 60.0 / customs.size());
    }
    return 0;
}
