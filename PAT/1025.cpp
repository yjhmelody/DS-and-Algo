#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct student {
    long long no;
    int score;
    int final_rank;
    int location_number;
    int local_rank;
};

int main() {
    int N;
    cin >> N;
    vector<int> num(N);
    vector<vector<student>> ranks(N);
    vector<student> results;

    for(int i = 0; i < num.size(); i++) {
        cin >> num[i];
        ranks[i].resize(num[i]);
        for(int j = 0; j < num[i]; j++) {
            cin >> ranks[i][j].no;
            cin >> ranks[i][j].score;
            // 处理地区编号
            ranks[i][j].location_number = i+1;
        }

        sort(ranks[i].begin(), ranks[i].end(), [](student& s1, student& s2) {
            return s1.score != s2.score ? s1.score > s2.score : s1.no < s2.no;
        });


        //处理地区排名
        ranks[i][0].local_rank = 1;
        results.push_back(ranks[i][0]);
        for(int j = 1; j < ranks[i].size(); j++) {
            ranks[i][j].local_rank = (ranks[i][j].score == ranks[i][j-1].score) ? ranks[i][j-1].local_rank : j+1;
            results.push_back(ranks[i][j]);
        }
    }

    sort(results.begin(), results.end(), [](student& s1, student& s2) {
            return s1.score != s2.score ? s1.score > s2.score : s1.no < s2.no;
    });


    // 处理总排名
    results[0].final_rank = 1;
    for(int i = 1; i < results.size(); i++) {
        results[i].final_rank = (results[i].score == results[i-1].score) ? results[i-1].final_rank : i+1;
    }
    cout << results.size() << endl;
    for(auto &x: results) {
        printf("%013lld %d %d %d\n", x.no, x.final_rank, x.location_number, x.local_rank);
        // 以下输出有一个例子无法通过
        // cout << x.no << " " << x.final_rank << " " << x.location_number << " " << x.local_rank << endl;
    }
    return 0;
}
