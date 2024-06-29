#include <vector>
#include <iostream>

using namespace std;

vector<int> parents;
vector<int> rankData;

int charToInt(char c) {// 이렇게 해주는 원리는 문자의 아스키 코드값을 이용한거임. 
    return c - '0';    // 문자 '0'의 아스키 코드값은 48, 만약 문자 '1'의 아스키 코드값을 알고 싶다면 '1' - '0' == 49 - 48 = 1임
}

int find(int x) { // 노드 x가 루트 노드인지?
    // parents[x]는 현재 x의 부모를 담아 놓은 것임.
    // 또 재귀의 원리를 이용함. 
    if (parents[x] == x) { // 이 노드가 부모 노드인가? 인덱스하고 값이 같은가를 비교
        return x;
    }
    // 아니면 그냥 넘어가

    // 파인드 연산 시, 경로 압축 사용. 경로 압축 이해됨... 모든 노드들의 부모를 루트 노드로 설정하는 함수. 재귀는 간단하지만 어렵다.... 이걸 머리속에서 꺼내기가 너무 힘듬...
    parents[x] = find(parents[x]); // 3의 부모의 부모를 찾으러 떠나라.
    // 시스템 스택으로 아직 이 코드에서 안넘어감. find(3의 부모)의 return 값이 나와야 밑에 코드로 진행할 수 있음.
    // 그러면 2로 또 떠난다. 2도 루트가 아니면 2의 부모의 부모를 찾으러 떠난다.
    // 이런식으로 재귀를 활용함...

    return parents[x];
}

void unionSet(int x, int y) { // 합치기 연산.
    int root1 = find(x); // x와
    int root2 = find(y); // y의 루트 노드를 찾는다. 동시에 경로 압축도 진행된다. 한마디로 경로압축과 루트 노드를 바로 찾아버림...

    
    if (root1 != root2) {
        // 랭크 기반 알고리즘으로 유니온 연산 수행
        if (rankData[root1] < rankData[root2]) { // root2의 랭크가 더 높으면 root1의 부모를 root2로 바꾼다
            parents[root1] = root2;
        }
        else if (rankData[root1] > rankData[root2]) { // root1의 랭크가 더 높으면 root2의 부모를 root1로 바꾼다.
            parents[root2] = root1;
        }
        else { // 위 둘다 아니면 나머지 경우는 root1과 root2가 같은 경우임.
            parents[root2] = root1; // 그냥 root2의 부모를 root1로 바꿔주고 root1의 랭크를 하나 더 높여준다.
            rankData[root1]++;
        }
        // 그럼 랭크를 어떻게 측정하나?
    }
}

vector<bool> solution(int k, vector<vector<char>> operations) {
    parents.resize(k); // k만큼 공간을 확보하고 모두 0으로 초기화
    rankData.resize(k); // k만큼 공간 확보하고 모두 0으로 초기화

    // 처음엔 각 노드들이 자기 자신을 루트 노드로 함.
    for (int i = 0; i < k; i++) {
        parents[i] = i; 
    }

    vector<bool> result;
    for (const auto& op : operations) {
        if (op[0] == 'u') { // u : 합치기 연산이면
            int x = charToInt(op[1]);
            int y = charToInt(op[2]);
            unionSet(x, y);
        }
        else if (op[0] == 'f') {
            int x = charToInt(op[1]);
            int y = charToInt(op[2]);
            result.push_back(find(x) == find(y));
        }
    }

    return result;
}


int main() {
    vector<vector<char>> operations = {{'u', '0', '1'}, {'u', '1', '2'}, {'f', '0', '2'}};
    int k = 3; // 노드의 개수 k = 3이면 0 ~ 2

    vector<bool> result = solution(k, operations);

    for (bool i : result) {
        cout << i << " ";
    }

    return 0;
}