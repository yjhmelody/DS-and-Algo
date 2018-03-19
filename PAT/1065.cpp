#include<iostream>
#include<vector>

using namespace std;

int main(){
	int T;
   cin >> T;
   vector<long long> A(T), B(T), C(T);
   for(int i = 0; i < T; i++) {
   		cin >> A[i] >> B[i] >> C[i];
      cout << "Case #" << i+1 << ": ";
      long long sum = A[i] + B[i];
      if(A[i] > 0 && B[i] > 0 && sum < 0) {
      		cout << "true" << endl;
      }
      else if(A[i] < 0 && B[i] < 0 && sum >= 0) {
      		cout << "false" << endl;
      }
      else if(sum > C[i]) {
      		cout << "true" << endl;
      }
      else {
      		cout << "false" << endl;	
      }
   }
	return 0;
}