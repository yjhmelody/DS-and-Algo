#include<iostream>
#include<string>
#include<vector>
#include<tuple>

using namespace std;

bool replace(string& str) {
    bool flag = false;
    for(auto &x: str) {
        switch (x) {
        case '1':
            x = '@';
            flag = true;
            break;
        case '0':
            x = '%';
            flag = true;
            break;
        case 'l':
            x = 'L';
            flag = true;
            break;
        case 'O':
            x = 'o';
            flag = true;
            break;
        }
    }

    return flag;
}

int main() {
    int M;
    cin >> M;
    int count = 0;
    vector<tuple<string, string, bool>> accounts(M);
    vector<bool> modified(M);
    for(auto &x: accounts) {
        cin >> get<0>(x) >> get<1>(x);
        if(replace(get<1>(x))) {
            count++;
            get<2>(x) = true;
        } else {
            get<2>(x) = false;
        }
    }
    if(count == 0 && M == 1) {
        cout << "There is " << M << " account and no account is modified" << endl;
        return 0;
    }
    else if(count == 0) {
        cout << "There are " << M << " accounts and no account is modified" << endl;
        return 0;
    }
    cout << count << endl;
    for(auto &x: accounts) {
        if(get<2>(x) == true) {
            cout << get<0>(x) << " " << get<1>(x) << endl;
        }
    }

    return 0;
}
