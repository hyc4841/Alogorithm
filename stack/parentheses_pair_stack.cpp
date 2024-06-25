#include <iostream>
#include <stack>
#include <string>

using namespace std;


// 스택 - 괄호 짝 맞추기 문제. 내가 만든 버전
bool solution(string s) {

    stack<char> st;

    // 내가 짜놓은 코드는 )(이런식으로 되어 있는 애들도 짝으로 인식함. 이러면 안됨. ( 부터 시작해야함. )로 시작하면 시작부터 짝이 맞지 않음을 판별할 수 있으므로 false를 내보내야함.
    for (int i = 1; i < s.size(); i++) {
        // 먼저 스택안에 뭐가 있는지 확인한다.
        if (!st.empty()) {
            // 스택 안에 뭐가 있으면 비교 시작
            if (st.top() != s[i]) { // 스택에 맨 위의 요소와 같지 않으면 짝이 맞는거니까 
                st.pop(); // 그 요소 뺴낸다.
            }
            else { 
                // 만약에 맨 위에 있는 요소하고 같으면 짝이 맞지 않는거니까 스택에 넣는다
                st.push(s[i]);
            }
        }
        // 스택에 아무것도 없으면 현재 요소 스택에 넣는다.
        else {
            st.push(s[i]);
        }
    }

    // for문 다돌고 나서 스택 안 확인.
    if (st.empty()) {
        // 스택안에 뭐가 있으면 최종적으로 짝이 맞지 않으므로
        return false;
    }
    else {
        // 스택 안이 비어 있으면 최종적으로 짝이 맞는거임
        return true;
    }

}

int main() {

    string s = "((((((((()))))))))((((((())))))";
    bool answer = solution(s);

    if (answer == false) {
        cout << "짝이 맞지 않음" << endl;
    }
    else {
        cout << "짝이 맞음" << endl;
    }
    
    return 0;
}