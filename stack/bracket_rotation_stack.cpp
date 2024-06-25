#include <iostream>
#include <stack>

using namespace std;

string rotation(string s) {

    char tmp = s[0];
    s.erase();
    s.push_back(tmp);
    return s;
}

int solution(string s) {
    // erase() 맨 앞 요소 삭제하기
    // push_back() 으로 맨 뒤에 요소 추가하기
    // 짝 맞는지 안맞는지는 stack으로 구현

    // 1. 들어온 문자열 바로 stack에 넣어서 짝 맞는지 안맞는지 돌려본다.
    // stack 이용해서 짝 맞는지 안맞는지 알고리즘 만들기

    stack<char> bracket; // 알고리즘에 돌릴 스택 선언
    int count = s.length();
    char tmp;

    while (count < 0) {

        if (s[0] == ')' || s[0] == ']' || s[0] == '}') {
            s = rotation(s);
            count--;
            continue;
        }
        else {
            // 다음으로 '(', '{', '['중에 하나임.
            bracket.push(s[0]); // 첫번째 요소 스택에 넣는다.
            // 넣고 다음 요소랑 비교
            
        }




        count--;

    }

}



int main() {


    return 0;
}