#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;


int cal() {

}

// 스스로 못풀었음

// 트리 - 다단계 칫솔 판매 문제
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    // 1. 판매원의 수익금 중 10%는 자신의 추천인에게 간다.
    // 부모 - 자식 관계를 이용해라.
    // 자식의 수익금 10%는 부모에게로 간다.

    unordered_map<string, string> parent;
    unordered_map<string, int> total;

    for (int i = 0; i < referral.size(); i++) { // 키 : 자식, 값 : 부모
        parent.insert({enroll[i], referral[i]});
    }
    // 자식의 수익금의 10%를 부모한테 보내라.
    for (const auto &name : enroll) {
        total[name] = 0;
    }

    for (size_t i = 0; i <seller.size(); i++) {
        int money = amount[i] * 100; // 현재 판매원의 수익금
        string cur_name = seller[i]; // 실제 물건을 판 사람

        while (money > 0 && cur_name != "-") {
            // 실제 물건을 판 사람을 기준으로 추천인을 계속 추적하며 남은 수익의 10%를 분배
            int to_distribute = money / 10; // 10% 떼기
            total[cur_name] += money - to_distribute; // 10%를 뗀 돈을 현재 이름에 들어간 사람의 수익금에 추가한다.

            // 현재 이름의 추천인이 있으면 현재 이름을 추천인으로 변경, 그렇지 않으면 종료
            if (parent.find(cur_name) != parent.end()) { // 맵에서 찾는 값이 없으면 parend.end()의 값이 나온다.
                cur_name = parent[cur_name];
            }
            else {
                break;
            }
            // 현재 판매원이 추천인으로 변경되었으므로 수익금도 이에 맞춰 업데이트. 위에서 10퍼 뗀 금맥 말하는 거임. 10퍼 뗀걸 부모에서 또 떼고 위에서 10또 떼고를 이렇게 구현함.
            money = to_distribute;
        }
    }

    // 수익금을 answer에 업데이트해서 반환
    vector<int> result;
    result.reserve(enroll.size()); // reserve를 써주는 이유는 해당 공간 미리 확보한다. 확보된 상태로 따로 값이 채워지진 않음. capacity는 enroll.size()인데 size는 0이라는 소리. resize는 공간 확보하고 값까지 채워넣음
    for (const auto &name : enroll) {
        result.push_back(total[name]);
    }

    return result;
}

int main() {

    vector<string> enroll = {"john", "mary", "edward", "sam",    "emily", "jaimie", "tod",    "young"};
    vector<string> referral = {"-",  "-",    "mary",   "edward", "mary", "mary",   "jaimie", "edward"}; // enroll과 referral은 사이즈가 같아야한다.
    vector<string> seller = {"young", "john", "tod", "emily", "mary"};
    vector<int> amount = {12, 4, 2, 5, 10};

    vector<int> answer = solution(enroll, referral, seller, amount);

    for (int i : answer) {
        cout << i << ", ";
    }

    return 0;
}