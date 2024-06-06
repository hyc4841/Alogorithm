#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>

using namespace std;


// sort함수에 사용할 사용자정의 compare함수. sort함수는 비교 기준을 직접 정의한 함수를 사용할 수 있음.
bool compare(pair<int, float>& a, pair<int, float> & b) {
    if (a.second == b.second) { // a 스테이지와 b 스테이지의 실패율이 같으면 오름차순으로 정렬 해준다.
        return a.first < b.first;
    }
    return a.second > b.second; // 
}

vector<int> solution(int n, vector<int> stages) {
    /*
    실패율의 정의 
    스테이지에 도달했으나 아직 클리어하지 못한 플레이어 수 / 스테이지에 도달한 플레이어의 수
    */
    vector<int> answer; // 결과
    vector<float> challenger(n + 2, 0.0); // 각 스테이지에 도달한 적이 이 있는 도전자의 수
    vector<float> fail(n + 2, 0.0);

    for(int i = 0; i < stages.size(); i++) {
        for(int j = 1; j <= stages[i]; j++) { // j를 1부터 시작하는건 인덱스하고 스테이지 맞춰줄라고. 스테이지는 1부터 있으니까 이렇게 해줌.
            challenger[j]++; // 예를 들면 이런거다. 현재 3스테이지에 도달한 사람은 1의 실패율, 2의 실패율, 3의 실패율을 계산할 때 포함되어 계산된다.
                             // 그럼 1스테이지의 실패율을 계산할 때 스테이지에 도달한적 있거나 클리어한 도전자에 카운트 됨. 2스테이지 실패율 계산할 떄도 마찬가지
        }
        fail[stages[i]]++; // 스테이지에 도달했으나 아직 클리어 하지 못함. 간편하게 인덱스로 해결함...
    }

    // 실패율 저장
    vector<pair<int, float>> failRatio(n);
    
    for (int i = 0; i < n; i++) {
        failRatio[i].first = i + 1; // 인덱스는 0번 부터 시작하니까 이쁘게 1부터 시작할려고.

        if (challenger[i + 1] == 0) { // 위에서 인덱스하고 스테이지하고 맞춰줘서 1부터 시작해 줘야함.
            failRatio[i].second = 0; // 해당 스테이지에 도달하거나 클리어한 플레이어가 없으면 실패율 0으로 정의함.
        }
        else {
            failRatio[i].second = fail[i + 1] / challenger[i + 1]; // 정의에 맞게 실패율 저장.
        }
    }

    sort(failRatio.begin(), failRatio.end(), compare);

    for (int i = 0; i < n; i++) {
        answer.push_back(failRatio[i].first);
    }

    return answer;
}





int main() {
    vector<int> stages = {2, 1, 2, 6, 2, 4, 3, 3}; // 총 8명의 플레이어
    int n = 5;

    vector<int> answer = solution(n, stages);

    for (int i : answer) {
        cout << i << " ";
    }
    /*
    위 벡터가 의미하는 것은 사용자가 현재 도전 중인 스테이지 번호를 나타냄. 예를 들어 스테이지 1의 실패율은
    1/8 임. 1스테이지를 아직 깨지못한 플레이어의 수 / 스테이지 1에 도달하거나 클리어한 플레이어 수
    */

    

    return 0;
}