#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
    if (digits.empty()) return vector<int>();
    vector<int> result(digits.begin(), digits.end());
    int up = 0;
    for (vector<int>::reverse_iterator it = result.rbegin(); it != result.rend(); it++) {
        if (it == result.rbegin()) (*it) ++;
        else (*it) += up;
        up = (*it) / 10;
        *it = (*it) % 10;
    }
    if (up == 1) result.insert(result.begin(), 1);
    return result;
}

int main() {
    vector<int> input {};
    vector<int> result = plusOne(input);
    for(auto x : result) {
        cout << x << ' ';
    }
    cout << endl;
    return 0;    
}