#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>  // C++의 맵이 해시의 역할을 해줄 수 있다.

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> ph; // 참여자 맵

    // 맵에 참가자 넣기
    for (int i = 0; i < participant.size(); i++) {
        ph[participant[i]]++; // 맵에 없는 키에 접근하려고 하면 키가 새로 만들어지는 것을 이용.
        // 또한 value의 타입이 int인에 키에 값이 없는 경우 자동으로 0으로 초기화 됨.
    }

    // 완주자 배열의 원소의 개수는 참여자 보다 하나 적다.
    // 참여자에서 완주자 빼주기
    for (int i = 0; i < completion.size(); i++) {
        ph[completion[i]]--;
        // 만약 해시 테이블 안에 있는 이름의 값이 0이면 삭제해 주기.
        if (ph[completion[i]] == 0) {
            ph.erase(ph.find(completion[i]));
        }
    }

    return ph.begin() -> first; // 값이 0인 애들은 모두 삭제 됐으므로 남은 사람이 완주하지 못한 사람.
    // 처음부터 시작해서 첫번째로 나오는 값 반환하는 듯?
}

int main() {

    vector<string> participant = {"leo", "kiki", "eden"};
    vector<string> completion = {"eden", "kiki"};

    cout << solution(participant, completion) << endl;


    return 0;
}