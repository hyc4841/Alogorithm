#include <vector>
#include <iostream>

using namespace std;

vector<int> parents; // 각 노드들의 부모를 담을 백터
vector<int> rankd; // 노드의 랭크 데이터를 담을 백터

int charToInt(char x) {
    return x - '0'; // 아스키 코드값을 이용한 변환 방법. '0'은 48임
}

int find(int x) { // 루트 찾는 함수
    // x의 부모를 찾아서
    if (parents[x] == x) { // 만약 x의 부모가 자기 자신이면 루트 노드다.
        return x;
    }
    // 루트 노드 아니면 부모 노드 타고 올라가서 루트 노드 찾아 와야지
    // 재귀의 원리를 이용하면 된다.
    parents[x] = find(parents[x]); // 루트까지 올라가면 나머지 노드들도 루트 값으로 맞춰짐.

    return  parents[x];
}

void unionSet(int x, int y) {
    // x와 y의 루트 노드를 찾아라
    int root1 = find(x);
    int root2 = find(y);

    // 두 노드의 루트 노드의 랭크를 비교해라
    if (rankd[root1] > rankd[root2]) { // root1의 랭크가 더 높은 경우
        parents[root2] = root1; // root2의 부모를 root1로 바꾼다. root1의 랭크가 더 깊기 때문에. 결과적으로 랍쳐지고 랭크 변화는 없음
    }
    else if (rankd[root1] < rankd[root2]) { // root2의 랭크가 더 높은 경우
        parents[root1] = root2;
    }
    else { // 나머지 경우는 두 root 노드의 랭크가 같은 경우다.
        // 아무거나 루트가 되어라
        parents[root2] = root1;
        rankd[root1]++; // root1의 랭크가 더 높아졌으므로 랭크를 하나 올려준다.
    }
}

vector<bool> solution(int k, vector<vector<char>> operations) {
    // k는 노드의 수임.
    // 먼저 parents를 초기화 한다.
    rankd.resize(k); // 랭크도 초기화 해준다.
    parents.resize(k); // 노드의 수 만큼 초기화. 값에는 0이 할당됨.
    for (int i = 0; i < k; i++) { // 처음엔 모두 자기 자신을 루트로 한다.
        parents[i] = i;
    }
    
    vector<bool> result;
    // 알고리즘은 간단함. operations 배열 안에 있는 요소들 하나씩 읽어 오면서 f인지 u인지 구별하고 그에 맞는 알고리즘을 적용시켜주면 된다.
    for (const auto& c : operations) {
        if (c[0] == 'f') {
            // find 연산
            int x = charToInt(c[1]);// 문자를 숫자로 바꿔줄 함수 필요
            int y = charToInt(c[2]);
            // 두 노드의 부모 노드가 같은지 find연산을 통해서 찾는다.
            result.push_back(find(x) == find(y)); // 두 노드의 루트 노드가 같다면 true, 틀리면 false
        }
        else if (c[0] == 'u') {
            // union 연산. 랭크를 기반으로 한 합치기 연산이 되어야 한다. 처음 모든 노드들의 랭크는 0이다. 왜냐? 자기 자신이 루트이기 때문
            int x = charToInt(c[1]);
            int y = charToInt(c[2]);
            unionSet(x, y);
        }
    }

    return result;
}

int main() {
    // vector<vector<char>> operations = {{'u', '0', '1'}, {'u', '1', '2'}, {'f', '0', '2'}};
    // int k = 3; // 노드의 개수 k = 3이면 0 ~ 2

    vector<vector<char>> operations = {{'u', '0', '1'}, {'u', '2', '3'}, {'f', '0', '1'}, {'f', '0', '2'}};
    int k = 4;

    vector<bool> result = solution(k, operations);

    for (bool i : result) {
        cout << i << " ";
    }

    return 0;
}