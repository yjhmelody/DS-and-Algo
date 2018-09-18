#include<iostream>
#include<vector>
using namespace std;

struct student {
    string name;
    char gender;
    string ID;
    int grade;
};

bool bigger (student &s1, student &s2) {
        if (s1.grade > s2.grade) {
                return true;
             }
        return false;
}

void print(student &s) {
    cout << s.name << " " << s.ID << endl;
}

int main() {
    int N;
    vector<student> males;
    vector<student> females;
    cin >> N;
    for (int i = 0; i < N; i++) {
        student x;
        cin >> x.name >> x.gender >> x.ID >> x.grade;
        if (x.gender == 'F') {
            females.push_back(move(x));
        } else {
            males.push_back(move(x));
        }
    }

    student best;
    if(females.size() > 0) {
        best = females[0];
        for(auto &s: females) {
            if(bigger(s, best)) {
                best = s;
            }
        }
        print(best);
    }
    else {
        cout << "Absent" << endl;
    }

    student worst;
    if(males.size() > 0) {
        worst = males[0];
        for(auto &s: males) {
            if(bigger(worst, s)) {
                worst = s;
            }
        }
        print(worst);
    }
    else {
        cout << "Absent" << endl;
    }

    if(males.size() == 0 || females.size() == 0) {
        cout << "NA" << endl;
    }
    else {
        cout << best.grade - worst.grade << endl;
    }
}
