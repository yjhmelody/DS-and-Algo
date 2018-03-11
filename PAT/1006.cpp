#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct Person {
    string id;
    string sign_in_time;
    string sign_out_time;
};

// t1更早就为true
bool time_cmp(string& t1, string& t2) {
    for(auto it1 = t1.cbegin(), it2 = t2.cbegin();it1 != t1.cend();it1++, it2++) {
        if(*it1 < *it2) {
            return true;
        }
        if(*it2 < *it1) {
            return false;
        }
    }
    return false;
}

int main() {
    int M, m;
    cin >> M;
    m = M;
    auto persons = new Person[M];


    while(M--) {
        cin >> persons[M].id;
        cin >> persons[M].sign_in_time;
        cin >> persons[M].sign_out_time;
    }

    int first = 0;
    int last = 0;
    for(int i = 1; i < m; i++) {
        first = time_cmp(persons[i].sign_in_time, persons[first].sign_in_time) ? i : first;
        last = time_cmp(persons[i].sign_out_time, persons[last].sign_out_time) ? last : i;
    }
    cout << persons[first].id << " " << persons[last].id << endl;
    return 0;
}
