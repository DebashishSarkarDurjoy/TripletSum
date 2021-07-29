#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector <int>> tripletSum(vector<int> arr, int Sum) {
  vector<vector<int>> result = {};
  int currentSum = 0;
  int n = arr.size();

  for (int i = 0; i <= n-3; i++) {

    int j = i + 1;
    int k = n - 1;

    while (j < k) {
      currentSum = arr[i];
      currentSum = currentSum + arr[j] + arr[k];
      if (currentSum == Sum) {
        result.push_back({arr[i], arr[j], arr[k]});
        j++;
        k--;
      }
      else if (currentSum < Sum) {
        j++;
      }
      else {
        k--;
      }
    }
  }


  return result;
}

int main(void) {
  vector<int> arr = {1,2,3,4,5,6,7,8,9,15};
  int S = 18;

  auto result = tripletSum(arr, S);

  for (auto row: result) {
    for (auto n: row) {
      cout << n << ", ";
    }
    cout << endl;
  }

  return 0;
}
