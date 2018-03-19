#include<iostream>
#include<cstdio>
using namespace std;

int main() {
	int a[3];
   int b[3];
   int c[3] = {0};
   scanf("%d.%d.%d", a, a+1, a+2);
   scanf("%d.%d.%d", b, b+1, b+2);
   if(a[2] + b[2] >= 29) {
   		a[1]++;
      c[2] = a[2] + b[2] - 29; 	
   }
   else {
   		c[2] = a[2] + b[2];
   }
   if(a[1] + b[1] >= 17) {
   		a[0]++;
      c[1] = a[1] + b[1] - 17;
   }
   else {
   		c[1] = a[1] + b[1];
   }
   c[0] = a[0] + b[0];
   printf("%d.%d.%d", c[0], c[1], c[2]);
	return 0;
}