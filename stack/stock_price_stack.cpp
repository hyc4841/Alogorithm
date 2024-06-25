#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// 스택 - 주식 가격 문제(내 버전)
vector<int> solution(vector<int> prices) {
    stack<int> index;
    vector<int> answer(prices.size());

    // 첫번째 요소 미리 넣기
    index.push(0); // 0번째 인덱스 미리 넣는거임


    int i = 1; // 주식 가격의 인덱스
    while (i < prices.size()) {

        if (!index.empty()) {
            // 스택에 들어 있는 이전 주식 가격과 현재 주식 가격을 비교
            // 현재 주식 가격이 이전 주식 가격보다 높으면 주식가격 아직 안내려간거니까 그대로 스택에 해당 주식가격 인덱스 push
            if (index.top() < prices[i]) {
                index.push(i);
                i++;
            }
            else {
                // 이전 주식 가격이 현재 주식 가격보다 높으면 주식 가격이 떨어진것 이므로 유지 시간 확정하고 스택에서 해당 인덱스 pop연산
                // index.top() >= prices[i]
                answer[index.top()] = i - index.top(); // 가격 유지 시간 확정
                index.pop();  
            }
        }
        else {
            // 스택 비어 있으면 채우기
            index.push(i);
            i++;
        }
    }

    while (!index.empty()) {
        if (index.top() == prices.size() - 1) { // 마지막 인덱스면
            answer[index.top()] = 0;
            index.pop();
        }
        else {
            // 마지막 인덱스 아니고 끝까지 가격이 떨어지지 않았던 인덱스면
            answer[index.top()] = prices.size() - index.top() - 1;
            index.pop();
        }
    }

    return answer;
}

int main() {

    vector<int> price = {1, 2, 3, 2, 3};
    vector<int> answer = solution(price);

    for (int i : answer) {
        cout << i << " ";
    }

    return 0;
}