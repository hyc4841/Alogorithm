#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    
    int maxHealth = health; // 최대 체력
    
    int t = bandage[0]; // 붕대 시전시간
    int x = bandage[1]; // 초당 회복량
    int y = bandage[2]; // 추가 회복량
    
    int timeDiff = 0; // 시간차이 저장 변수

    cout << "attacks의 크기 : " << attacks.size() << endl;
    
    for (int i = 0; i < attacks.size(); i++) {
        

        cout << "i : " << i << endl;
        cout << "현재 체력 : " << health << endl;
        // 먼저 두 공격 사이의 시간 차이를 구한다. 최초 시간차이는 0초부터 첫번째 공격이니까 첫번째 공격 시간을 시간차로 한다.
        if (i == 0) {
            timeDiff = attacks[0][0] - 1;
            cout << "timeDiff : " << timeDiff << endl;
        }
        else {
            timeDiff = attacks[i][0] - attacks[i-1][0] - 1;
            cout << "timeDiff : " << timeDiff << endl;
        }
        
        // 구한 시간차로 체력 회복량 계산
        health = health + (x * timeDiff) + ((timeDiff / t) * y); // 추가 체력 회복은 나머지 연산으로 붕대 시전이 몇번 도는지
        
        cout << "체력회복 후 체력 : " << health << endl;
        if (health > maxHealth) { // 이때 현재 체력이 최대 체력보다 높아지면 최대 체력으로 맞춘다
            health = maxHealth;
        }
        
        // 이제 공격을 받을 차례
        health = health - attacks[i][1];

        cout << "공격받고 난 후 체력 : " << health << endl;
        
        if (health <= 0) { // 체력이 0과 같거나 작으면
            cout << "현재 체력 : " << health << " 0과 같거나 작으면 게임 종료" << endl;
            return -1; // -1을 반환한다.
        }   
    }
    
    answer = health;
    cout << "정답 : " << answer << endl;
    
    return answer;
}

int main() {

    vector<int> bandage = {4,2,7};
    int health = 20;
    vector<vector<int>> attacks = {{1, 15}, {5, 16}, {8, 6}};

    cout << solution(bandage, health, attacks) << endl;

    return 0;
}