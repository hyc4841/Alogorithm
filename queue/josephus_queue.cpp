#include <queue>
#include <iostream>

using namespace std;

int solution(int n, int k) { // n은 인원수, k는 점프할 단위
    // 원소를 담을 큐 선언
    queue<int> q;

    for (int i = 1; i <= n; i++) { // 1부터 n까지 차례로 넣어준다.
        q.push(i);
    }

    // 이제 큐에서 1을 기준으로 k번째의 원소를 제거해나갈 것임. 기준은 제거된 원소 바로 다음 원소가 기준이 된다.
    // 큐에 원소 하나 남을 때까지 계속 제거해 나감
    while (q.size() > 1) { 
        // 맨 처음 1이 기준. k-1번째 까지 pop했다가 다시 넣어준다.
        for (int i = 0; i < k-1; i++) {
            q.push(q.front()); // 앞에 있는걸 뒤에 넣고 
            q.pop(); // 빼준다.
            // 이 짓을 k-1번 반복
        }
        // k-1번 원소까지 뺏다가 다시 뒤로 넣어주고 나면 이제 진짜로 제거해야할 원소가 front에 잡히게 됨.
        q.pop(); // 그래서 빼준다.

        // 원소를 제거하고 나면 자연스럽게 기준 숫자가 front에 잡히게 되고 다시 위 과정을 수행.
    }

    // while문을 다 돌고 나면 큐에는 원소가 하나만 남는다.
    return q.front();
}

int main() {

    int n = 5, k = 3;

    int answer = solution(n, k);

    cout << "마지막 원소 : " << answer << endl;

    return 0;
}