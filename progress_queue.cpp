#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    // progresses에는 순서대로 작업 진행도를 나타냄.
    // speeds에는 순서대로 작업 속도를 나타냄.
    // 뒤 작업이 앞 작업보다 먼저 완성될 수 있음. 작업의 완성은 100임
    // 단, 배포는 앞 작업부터 되어야함.
    // 배포는 하루에 한 번 진행 되고 한 번 배포될 때마다 완성된 작업이 한꺼번에 같이 나갈 수 있음.
    // 배포는 하루 진행도를 모두 더하고 난 후에 이루어짐
    // 배포가 이루어질 때 한꺼번에 몇개의 작업이 나가는지 기록해 놓은 벡터가 리턴 값임.

    // 배포가 차레로 이루어져야 한다는 것이 핵심.
    // 큐 내부 원소에 연산을 가할 수 있는가?
    
    queue<int> p; // progresses를 차례로 담을 큐
    queue<int> s; // speeds를 차례로 담을 큐
    queue<int> tmp;
    queue<int> tmp2;

    for (int i = 0; i < progresses.size(); i++) {
        p.push(progresses[i]);
        s.push(speeds[i]);
    }
    
    while (!p.empty()) { // p에 담긴 원소가 모두 나가면 끝

        int count = 0; // 배포 루프가 돌면 기록하기 위함
        // 작업 속도를 작업 진행도에 더해준다.

        for (int i = 0; i < p.size(); i++) { // p의 크기 만큼 진행한다.
            p.push(p.front() + s.front());
            s.push(s.front());
            p.pop();
            s.pop();
        }

        // 하루 진행도를 다 더해준 후 맨 위 요소를 확인한다.
        while (!p.empty() && p.front() > 99) { // 맨 위 요소가 100을 넘어가면 계속 될것이고 아니면 그냥 건너 뛰게 될것임.
            // 배포 진행. 여기선 큐를 pop해주면 됨.
            p.pop();
            s.pop();
            count++; // count가 올라갔다는 것은 배포 루프가 돌았다는 의미임

            cout << "2번쨰 while" << endl;

        }    
        
        if (count != 0) { // count가 0이 아니면 배포 루프가 돌았다는 의미임.
            tmp2.push(count);
            cout << "count의 값 : " << count << endl;
        }
    }

    vector<int> answer(tmp2.size());
    cout << "tmp2의 크기 : " << tmp2.size() << endl;

    int answer_size = tmp2.size();
    for (int i = 0; i < answer_size; i++) {
            answer[i] = tmp2.front();
            tmp2.pop();
            
        }

    return answer;
}

int main() {

    vector<int> progresses = {93, 30, 55};
    vector<int> speeds = {1, 30, 5};

    vector<int> answer = solution(progresses, speeds);

    
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    

    return 0;
}