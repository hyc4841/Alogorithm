#include <set>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> numbers) {
    set<int> sum;

    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            sum.insert(numbers[i] + numbers[j]);
        }
    }

    vector<int> answer(sum.begin(), sum.end());

    return answer;
}

int main() {

    vector<int> numbers = {5, 0, 2, 7};
    vector<int> answer = solution(numbers);

    for (int i : answer) {
        cout << i << " ";
    }

    return 0;
}