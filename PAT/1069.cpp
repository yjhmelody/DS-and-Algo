#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

int reorder(int num, bool is_inc = true, int n = 4) {
	vector<int> vec(n);
   for(int i = 0; i < n; i++) {
   		vec.push_back(num % 10);
      num /= 10;
   }
   if(is_inc) {
   		sort(vec.begin(), vec.end());
   	}
   else {
   		sort(vec.begin(),vec.end(), greater<int>());
   }
   
   int sum = 0;
   for(auto &x: vec) {
   		sum = sum * 10 + x;
   }
   return sum;
}

int main() {
	int num;
   cin >> num;
   int a = reorder(num, false);
   int b = reorder(num, true);
   if(a == b) {
   		cout << a << " - " << b << " = 0";		return 0;
   }
   int c = num;
   do {
   		a = reorder(c, false);
      b = reorder(c, true);
   		cout << a << " - " << b << " = " << c << endl;
   } while(c != 6174);
	return 0;
}