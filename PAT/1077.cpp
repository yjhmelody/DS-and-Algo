#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int N;
    scanf("%d\n", &N);
    vector<string> words(N);
    for(auto &x: words) {
        getline(cin, x);
        reverse(x.begin(), x.end());
    }
    string suffix;
    for(int i = 0; i < words.size(); i++) {
        auto len = words[i].size();
        if(i == 0) {
            suffix = words[i];
            continue;
        }
        int min_len = min(len, words[i].size());
        for(int j = 0; j < min_len; j++) {
            if(suffix[j] != words[i][j]) {
                suffix = suffix.substr(0, j);
                break;
            }
        }
    }

    reverse(suffix.begin(), suffix.end());
    if(suffix.size() == 0) {
        suffix = "nai";
    }
    cout << suffix << endl;
    return 0;
}
