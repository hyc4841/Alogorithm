#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 큐 - 기능 개발
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    // 이 방식은 각 작업의 배포 가능일을 먼저 계산하고 앞 작업의 배포 가능일에 같이 배포 가능한 애들을 계산해내는 것.
    // 먼저 배포 가능날짜를 계산해서 큐에 넣어야하나? 큐에 넣어야함.
    // 1. 배포 가능 날짜 계산하기
    int rest_p = 0; // 남은 진행도 계산할 때 사용할 변수
    int tmp = 0; // 해당 작업의 남은 진행도와 작업속도 나눈 값 임시 저장 변수.
    queue<int> left_days; // 계산한 배포 가능일을 저장할 큐.
    queue<int> answer_queue;

    // 배포 가능일 계산
    for (int i = 0; i < progresses.size(); i++) { 
        rest_p = 100 - progresses[i]; // 남은 진행도 계산
        tmp = rest_p / speeds[i]; // 며칠 남았는지 남은 진행도를 작업속도로 나눈다.
        if (rest_p % speeds[i] != 0) {         // 이때 나머지가 발생하면 하루 더 소요하게 되므로 +1을 해준다.
            ++tmp;
        }
        left_days.push(tmp);
    }
    
    int front_job = 0;
    while (left_days.size() > 0) { // 큐가 빌때까지 진행
        int count = 0;
        front_job = left_days.front(); // 현재 맨 앞 작업 저장
        left_days.pop();
        count++;
        while (front_job > left_days.front()) { // 앞 
            left_days.pop();
            count++;
        }

        answer_queue.push(count);
    }
    
    vector<int> answer(answer_queue.size());
    int s = answer_queue.size();
    for (int i = 0; i < s; i++) {
        answer[i] = answer_queue.front();
        answer_queue.pop();
    }

    return answer;
}


int main() {

    vector<int> progresses = {95,90,99,99,80,99};
    vector<int> speeds = {1,1,1,1,1,1,};

    vector<int> answer = solution(progresses, speeds);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }



    return 0;
}