#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    queue<string> q_cards1;
    queue<string> q_cards2;
    for (int i = 0; i < cards1.size(); i++) {
        q_cards1.push(cards1[i]);
    }
    for (int i = 0; i < cards2.size(); i++) {
        q_cards2.push(cards2[i]);
    }

    // for 문으로 goal순회 하면서 있는지 없는지 비교
    for (string i : goal) {
        if (q_cards1.front() == i) { // 현재 cards1 맨 앞에 있는 요소와 비교
            q_cards1.pop();
            continue; // 만약 있으면 통과
        }
        else if (q_cards2.front() == i) {
            q_cards2.pop();
            continue;
        }
        else {
            return "No"; // 위 두 개 다 없으면 false 반환
        }

    }

    return "Yes";
}


int main() {
    vector<string> cards1 = {"i",  "water", "drink"};
    vector<string> cards2 = {"want", "to"};
    vector<string> goal = {"i", "want", "to", "drink", "water"};

    cout << solution(cards1, cards2, goal) << endl;
    

    return 0;
}