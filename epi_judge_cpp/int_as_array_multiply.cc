#include <vector>

#include "test_framework/generic_test.h"
using std::vector;
vector<int> Multiply(vector<int> num1, vector<int> num2) {
  // TODO - you fill in here.
  int n = num1.size();
  int m = num2.size();
  vector<int> result(n+m,0);
  for (int i = n-1; i >= 0; --i) {
    for (int j = m-1; j >=0; --j) {
      int mul = (num1[i] - '0') * (num2[j] - '0');
      int sum = mul + result[i + j + 1];

      result[i + j] += sum / 10;
      result[i + j + 1] = sum % 10; 

    }    
  }

  int i = 0;
  while (i < n +m -1 && result[i] == 0) {
    i++;
  }

  vector<int> finalResult(result.begin() + i, result.end()); 
  return finalResult;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"num1", "num2"};
  return GenericTestMain(args, "int_as_array_multiply.cc",
                         "int_as_array_multiply.tsv", &Multiply,
                         DefaultComparator{}, param_names);
}
