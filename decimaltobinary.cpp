#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<int> solution(int decimal) {
    stack<int> result;

    int decimal2 = decimal;

    // 처음부터 0 들어오면 0으로 처리해주는 부분 추가해 주는 것도 좋음
    while (decimal2 > 0) { // while문은 조건문이 true일때 도는 거다.
        result.push(decimal2 % 2); // 나머지 먼저 구해놓기
        decimal2 = decimal2 / 2;
    }
    
    return result;
}


int main() {
    int decimal = 0;
    stack<int> answer = solution(decimal);

    while (!answer.empty()) {
        cout << answer.top();
        answer.pop();
    }

    return 0;
}