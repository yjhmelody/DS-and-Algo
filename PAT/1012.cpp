#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

struct grades {
    int id;
    // best course
    int best;
    int scores[4];
    int ranks[4];
};

int main() {
    int N;
    int M;

    cin >> N >> M;
    vector<grades> students(N);
    set<int> ids;
    vector<int> search_ids;

    char course[5] = {'C', 'M', 'E', 'A'};
    int order[4] = {2, 3, 1, 4};
    for(auto &x: students) {
        cin >> x.id;
        ids.insert(x.id);
        int sum = 0;
        for(int i = 0; i < 3; i++) {
            cin >> x.scores[i];
            sum += x.scores[i];
        }
        x.scores[3] = sum / 3;
    }
    for(int i = 0; i < M; i++) {
        int id;
        cin >> id;
        search_ids.push_back(id);
    }

    // the i-th score
    for(int i = 0; i < 4; i++) {
        sort(students.begin(), students.end(), [i](grades& x1, grades& x2) {
            return x1.scores[i] > x2.scores[i];
        });
        // the j-th rank
        students[0].ranks[i] = 1;
        for(int j = 1; j < N; j++) {
            students[j].ranks[i] = j + 1;
            // same score
            if(students[j-1].scores[i] == students[j].scores[i]) {
                students[j].ranks[i] = students[j-1].ranks[i];
            }
        }
    }

    for(auto &x: students) {
        x.best = 0;
        int best_rank = x.ranks[x.best];
        for(int i = 1; i < 4; i++) {
            // something hacked
            if(best_rank > x.ranks[i] || best_rank == x.ranks[i] && order[i] > order[x.best]) {
                best_rank = x.ranks[i];
                x.best = i;
            }

        }
    }

    for(int i = 0; i < M; i++) {
        if(ids.find(search_ids[i]) != ids.end()) {
            for(auto &x: students) {
                if(x.id == search_ids[i]) {
                    cout << x.ranks[x.best] << " " << course[x.best] << endl;
                }
            }
        }
        else {
            cout << "N/A" << endl;
        }
    }
    return 0;
}
