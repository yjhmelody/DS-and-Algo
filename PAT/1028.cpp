#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

// 这道题卡C++的时间，得用C
struct Student {
    int id;
    char name[10];
    int grade;
};

int main() {

    int N;
    int C;
    cin >> N >> C;
    vector<Student> students(N);
    for(auto &s: students) {
        scanf("%d %s %d", &s.id, &s.name, &s.grade);
    }

    switch(C) {
    case 1:
        sort(students.begin(), students.end(), [](Student& s1, Student& s2) {
             return s1.id < s2.id;
        });
        break;
    case 2:
        sort(students.begin(), students.end(), [](Student& s1, Student& s2) {
             int res = strcmp(s1.name, s2.name);
             if(res < 0) {
                return true;
             } else if(res == 0) {
                 return s1.id < s2.id;
             }
             return false;
        });
        break;
    case 3:
        sort(students.begin(), students.end(), [](Student& s1, Student& s2) {
             if(s1.grade < s2.grade) {
                return true;
             } else if(s1.grade == s2.grade) {
                 return s1.id < s2.id;
             }
             return false;
        });
    }
    for(auto &s: students) {
        printf("%06d %s %d\n", s.id, s.name, s.grade);
    }
    return 0;
}
