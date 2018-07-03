#include <iostream>
#include <vector>


using namespace std;

template <typename T> void insertSort(vector<T> &a) {
  int len = a.size();
  for (int i = 1; i < len; i++) {
    T x = a[i];
    int j = i - 1;
    for (; j >= 0 && x < a[j]; j--) {
      a[j + 1] = a[j];
    }
    a[j + 1] = x;
  }
}

template <typename T> int bin_search(const vector<T> &a, T x, int i, int j) {
  int left = i;
  int right = j - 1;
  int mid;
  while (left <= right) {
    mid = (left + right) / 2;
    if (a[mid] < x) {
      left = mid + 1;
    } else if (a[mid] > x) {
      right = mid - 1;
    } else {
      break;
    }
  }
  return mid;
}

template <typename T> void insertSort2(vector<T> &a) {
  int len = a.size();
  for (int i = 1; i < len; i++) {
    T x = a[i];
    int pos = bin_search(a, x, 0, i);
    for (int j = i - 1; pos <= j; j--) {
      a[j + 1] = a[j];
    }
    a[pos] = x;
  }
}

int main() {
  vector<int> a = {7, 3, 2, 1, 4};
  vector<int> a2 = {5, 3, 2, 1, 4};
  insertSort(a);
  insertSort2(a2);

  for (auto x : a) {
    cout << x << endl;
  }
  cout << endl;
  for (auto x : a2) {
    cout << x << endl;
  }
  return 0;
}
