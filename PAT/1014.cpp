#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>

using namespace std;

struct window {
    int firstEnd;
    int lastEnd;
    queue<int> q;
};


int main() {
    int N;
    int M;
    int K;
    int Q;

    cin >> N >> M >> K >> Q;

    vector<window> windows(N);
    vector<int> mins(K);
    vector<int> results(K);
    vector<bool> done(K, true);
    vector<int> queries(Q);
    for(auto &x: mins) {
        cin >> x;
    }

    // �ȴ������ڵ����
    int k = 0;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N && k < K; j++, k++) {
            windows.at(j).q.push(mins.at(k));
            // �������һ���Ŷӵ���
            if(i == 0) {
                windows.at(j).firstEnd = windows.at(j).q.front();
                windows.at(j).lastEnd = windows.at(j).q.front();
            }
            else {
                if(windows.at(j).lastEnd >= 540) {
                    done[k] = false;
                }
                windows.at(j).lastEnd += windows.at(j).q.back();
            }
            results[k] = windows[j].lastEnd;
        }
    }

    // �ߺ�����
    for(; k < K; k++) {

        // �ҵ����ȳ��ӵĴ���
        int first_index = 0;
        int min_time = windows[0].firstEnd;
        for(int i = 1;i < N; i++) {
            if(windows.at(i).firstEnd < min_time) {
                first_index = i;
                min_time = windows.at(i).firstEnd;
            }
        }

        // ֮�����ģ�ⴰ�ڹ���
        windows[first_index].q.pop();
        windows[first_index].q.push(mins[k]);

        // ���µ�һ���˺����һ���˳���ʱ��
        windows[first_index].firstEnd += windows[first_index].q.front();
        if(windows[first_index].lastEnd >= 540) {
            done[k] = false;
        }
        windows[first_index].lastEnd += mins[k];
        results[k] = windows[first_index].lastEnd;
    }

    for(auto &x: queries) {
        cin >> x;
        if(done[x-1] == false) {
            cout << "Sorry" << endl;
        }
        else {
            printf("%02d:%02d\n", (results[x-1] + 480) / 60, results[x-1] % 60);
        }
    }
    return 0;
}
