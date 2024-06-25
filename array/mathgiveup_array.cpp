#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

// 배열 - 모의고사 문제 (수포자의 찍기 문제)
// 내가 구현한건 문제가 10000개 있다고 가정하고 문제 패턴을 넣고 돌린것.
vector<int> solution(vector<int> answers) {
    int MAX_NUM = 10000; // 문제의 개수. 상수 정의하는거 알아두기
    // answers는 정답 패턴이 담긴 배열임
    // 수포자들의 찍기 패턴도 넣어놔야함.
    vector<int> g1 = {1, 2, 3, 4, 5}; // 인덱스가 4까지가 끝
    vector<int> g2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> g3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    vector<int> result = {0, 0, 0};

    set<int> tmp; // set은 내부에서 자동으로 오름차순 정렬을 해준다.
    


    // 정답 비교하기
    for (int i = 0; i < MAX_NUM; i++) {
        // 어쨋든 정답 패턴도 만 까지 계속 반복해야함.
        // 어쨋든 찍기 패턴도 만 깢기 계속 반족해야함.
        if (answers[i % answers.size()] == g1[i % g1.size()]) result[0]++;
        if (answers[i % answers.size()] == g2[i % g2.size()]) result[1]++;
        if (answers[i % answers.size()] == g3[i % g3.size()]) result[2]++;

        // 여기서 문제는 10000까지 반복 되어야 한다는 것. 해결함
        // i인수 % 배열 크기 => 나머지 연산자로 인덱스 반복되도록함. 각자 알아서 반복됨.

        // 이제 점수 가장 많이 받은 사람 순위 매기기. 동점자는 오름차순으로 정렬.
    }

    auto max_num = max_element(result.begin(), result.end());

    for (int i = 0; i < result.size(); i++) {
        cout << "result "<< i + 1 << " : " << result[i] << endl;
        if (result[i] == *max_num) { // 아마도 여기에 문제 있나?
            tmp.insert(i+1);
        }
    }

    vector<int> fin(tmp.begin(), tmp.end());

    return fin;
}

int main() {
    vector<int> answers = {1, 3, 2, 4, 2};

    vector<int> result = solution(answers);

    for (int i : result) {
        cout << i << " ";
    }

    return 0;
}