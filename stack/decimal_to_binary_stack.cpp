#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<int> solution(int decimal) {
    stack<int> result;

    int decimal2 = decimal;


    if (decimal2 == 0) { // 먼저 들어온 숫자가 0이면 거른다.
        result.push(0);
        return result;
    }
    else {
        while (decimal2 > 0) { // while문은 조건문이 true일때 도는 거다.
            result.push(decimal2 % 2); // 나머지 먼저 구해놓기
            decimal2 = decimal2 / 2;
        }
    }
    

    return result;
}


int main() {
    int decimal = 1;
    stack<int> answer = solution(decimal);

    while (!answer.empty()) {
        cout << answer.top();
        answer.pop();
    }

    return 0;
}