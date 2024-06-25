#include <iostream>
#include <stack>

using namespace std;

// 스택 - 짝지어 제거하기 문제
int solution(string s) {    
    stack<char> tmp;
    // 스택에 먼저 집어넣기
    tmp.push(s[0]);

    // 문자열 홀수로 들어오면 무조건 짝 안맞는거니까 0으로 리턴
    if (s.length() == 0) return 0;


    for (int i = 1; i < s.length(); i++) {
        // 스택이 비어 있지 않다면
        if (!tmp.empty()) {
                // 기존에 들어있던 요소와 같다면
            if (tmp.top() == s[i]) {
                tmp.pop();
            }
            // 기존 요소와 같지 않으면 현재 요소 스택에 넣기
            else {
                tmp.push(s[i]);
            }
        }
        else {
            // 스택이 비어 있는 경우
            tmp.push(s[i]);
        }
    }


    // for문을 다 돌고 나서 스택 확인
    if (tmp.empty()) {
        // 스택 비어 있으면 짝 맞음
        return 1;
    }
    else {
        return 0;
    }


}

int main() {
    string s = "cdcdk";
    int answer = solution(s);

    if (answer == 1) {
        cout << "짝 맞음" << endl;
    }
    else {
        cout << "짝 안맞음" << endl;
    }


    return 0;
}