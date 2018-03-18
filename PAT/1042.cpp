#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<array>

using namespace std;

const int n = 54;
void init_cards(array<string, n>& cards) {
    for(int i = 0; i < 4; i++) {
        char ch;
        switch(i) {
        case 0:
            ch = 'S';
            break;
        case 1:
            ch = 'H';
            break;
        case 2:
            ch = 'C';
            break;
        case 3:
            ch = 'D';
            break;
        }
        for(int j = i * 13, k = 1; j < (i+1) * 13; j++, k++) {
            cards.at(j).push_back(ch);
            cards.at(j).append(to_string(k));
        }
    }
    cards.at(52).append("J1");
    cards.at(53).append("J2");
}

int main() {
    int K;
    array<string, n> cards;
    init_cards(cards);
    array<int, n> positions;
    cin >> K;
    for(auto &x: positions) {
        cin >> x;
    }
    while(K--) {
        array<string, n> temp;
        for(int i = 0; i < n; i++) {
            temp.at(positions.at(i)-1) = cards.at(i);
        }
        swap(temp, cards);
    }

    for(int i = 0; i < cards.size()-1; i++) {
        cout << cards.at(i) << " ";
    }
    cout << cards.at(cards.size()-1) << endl;
    return 0;
}
