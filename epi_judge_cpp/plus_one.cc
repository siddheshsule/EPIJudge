#include <vector>
#include <iostream>

using namespace std;

vector<int> PlusOne(vector<int> A) {  
    ++A.back();
    
    for (int i = A.size() - 1; i > 0 && A[i] == 10; --i) {
        A[i] = 0, ++A[i - 1];        
    }
    if (A[0] == 10) {
        A[0] = 0;
        A.insert(A.begin(), 1);
    }
    return A;
}

int main(int argc, const char** argv) {

    vector<int> v {1,4,9};

    vector<int> result = PlusOne(v);

    for (auto i: result) {
        cout << i << " ";
    }
    return 0;
}