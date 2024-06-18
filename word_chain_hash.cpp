#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;


/* 내가 unordered_map으로 구현한거. 잘 작동함.
vector<int> solution(int n, vector<string> words){
    unordered_map<string, int> map; // 각 번호들이 말한 단어를 저장할 맵 선언. 키는 단어, 값은 단어를 말한 횟수.
    vector<int> answer(2, 0); // 최종 정답 벡터

    // 중복 단어를 말한 사람의 번호와 순서를 반환
    for (int i = 0; i < words.size(); i++) {
        if (map[words[i]] == 1) { // 단어가 이미 들어 있으면?
            answer[0] = (i % n) + 1; // 말한 사람의 번호
            answer[i] = i / n + 1; // 0부터 시작하는 인덱스에서 나머지 연산에 +1을 그냥 해주면 쉽게 몇번째 순회인지 알 수 있다...

            return answer;
        }
        map[words[i]]++;
    }
    return answer;
}
*/

vector<int> solution(int n, vector<string> words) {

    vector<int> answer(2, 0); // 정답 담으로 벡터

    unordered_set<string> usedWords; // 사용한 단어 저장할 set.
    // set은 중복을 허용하지 않는다.

    usedWords.insert(words[0]);

    for (int i = 1; i < words.size(); i++) {
        if (!usedWords.insert(words[i]).second || words[i].front() != words[i-1].back()) { 
            // set에 단어 삽입을 시도하고 second에 담기는 true나 false값을 보고 단어가 있는지 없는지 판단한다. 뒤에건 끝말잇기의
            // 기본 규칙을 지키고 있는지 확인
            answer[0] = i % n + 1; // 현재 순서인 사람의 번호
            answer[1] = i / n + 1; // 이 사람의 순서가 몇번째로 돌아온건지. 0부터 시작하는 인덱스를 그냥 나누고 +1을 해주면 쉽다.
            return answer;
        }
    }

    return answer;
}

int main() {
    vector<string> words = {"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"};
    int n = 3; // 플레이어의 수

    vector<int> answer = solution(n, words);

    for (int i : answer) {
        cout << i << " ";
    }
    
    return 0;
}