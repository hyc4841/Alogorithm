#include <iostream>
#include <vector>

using namespace std;

vector<int> answer;
vector<bool> earnedPoint; // 획득한 점수
vector<int> apeach;



bool canShoot(int arrowNum, int point) { // 쏠 수 있는 화살의 개수를 넘겨 받는다.
    return arrowNum > apeach[point]; // 남은 화살의 개수가 어피치가 i번째 과녁을 맞춘 화살의 개수보다 많으면 쏠 수 있음
}

void shoot(int remainArrow) { // 남은 화살의 개수를 매개변수로 받는다.

    // 넘겨받은 남은 화살의 개수로 과녁 맞추기를 실행한다.
    for (int i = 0; i < earnedPoint.size(); i++) {
        if (earnedPoint[i] == false && canShoot(remainArrow, i)) { // 아직 i 번째 과녁의 점수를 획득하지 않은 상태고, 해당 과녁에 쏠 수 있으면
            earnedPoint[i] = true; // 점수 획득 표시
            
            if (remainArrow - apeach[i] == 0) { // 쏠 수 있는 화살을 다 쓰면 이전 점수와 비교하여 정답을 갱신한다.

                
            }

        }
    }

}

vector<int> solution(int n, vector<int> info) { // n : 쏠 수 있는 화살의 개수, info : 맞춘 과녁의 정보
    // 큰 점수를 먼저 선점하는 방식으로 진행
    // shot() 함수를 만들어서 쏠 수 있는 화살의 개수를 넘겨준다.
    // shot() 함수에선 쏠 수 있는 화살의 개수를 가지고 현재 가장 높은 점수를 획득할 수 있는 없는지 판단하는 isValid() 함수로 판단하고 맞출 수 있다면 맞추고 다음 shot() 함수로 넘어간다.
    apeach = info;

    shoot(n);

    return answer;
}


int main() {


    return 0;
}