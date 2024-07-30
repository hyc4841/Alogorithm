#include <iostream>
#include <vector>

using namespace std;

vector<int> answer;
vector<int> ryan(11, 0);
int maxScore = -1;

int calcScoreDiff(const vector<int> &apeach) {
    int scoreApeach = 0;
    int scoreLion = 0;

    for (int i = 0; i < 11; ++i) {
        if (apeach[i] == 0 && ryan[i] == 0) {
            continue;
        }
        if (apeach[i] >= ryan[i]) {
            scoreApeach += 10 - i;
        }
        else {
            scoreLion += 10 - i;
        }
    }

    return scoreLion - scoreApeach;
}

void dfs(const vector<int> apeach, int score, int arrow) { // 어피치가 쏜 과녁과 화살 개수 정보, 현재 과녁 점수, 남은 화살의 개수

    if (score == -1 || arrow == 0) { // score는 -1 씩 숫자가 낮아지므로 마지막 0점 까지 돌고 -1이 되면 최종 점수차이를 계산한다.
        ryan[10] = arrow;  // 남은 화살의 개수를 0점에 모두 쏜다.
        int socreDiff = calcScoreDiff(apeach); // 라이언과 어피치의 점수 차이 계산

        // 현재 구한 점수 차가 기존 최대 점수 차보다 크고, 라이언의 점수가 더 높으면 갱신
        if (socreDiff > 0 && maxScore < socreDiff) { // 점수차이가 0보다 크고 이전에 구했던 점수 차이보다 크면
            maxScore = socreDiff; // 최대 점수차이 갱신한다.
            answer = ryan; // 정답은 현재 라이언이 쏜 과녁으로 한다.
        }

        ryan[10] = 0;
        return;
    }

    // 현재 점수에서 라이언이 쏠 수 있는 화살의 개수가 현재 점수에 꽂혀 있는 어피치의 화살의 개수보다 많으면 해당 과녁에 화살을 사용하고 점수를 획득한다.
    if (arrow > apeach[score]) { 
        ryan[score] = apeach[score] + 1;
        dfs(apeach, score - 1, arrow - apeach[score] - 1);
        ryan[score] = 0;
    }

    // 현재 점수를 건너뛰는 경우.
    dfs(apeach, score - 1, arrow);
}

vector<int> solution(int n, vector<int> info) { 
    // 10점 과녁부터 모든 조합을 확인
    dfs(info, 10, n);

    if (maxScore == -1) {
        answer.push_back(-1);
    }

    return answer;
}


int main() {


    return 0;
}
