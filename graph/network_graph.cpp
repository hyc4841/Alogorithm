#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map<int, vector<int>> adjList; // 인접 리스트로 그래프 구현
unordered_set<int> visited; // 방문 기록
int cnt; // 네트워크 개수 기록

void dfs(int start) {
    cnt++; // 네트워크 개수 올려주기
    stack<int> s;

    s.push(start); // 시작 노드 먼저 스택에 넣어주고 시작

    // 스택이 비게 되면 탐색 끝임
    while (!s.empty()) {
        int cur_node = s.top(); // 현재 탐색할 노드
        s.pop(); // 맨위 노드 빼주면서 방문처리 한다.
        visited.insert(cur_node);

        for (auto &neighbor : adjList[cur_node]) {
            if (visited.find(neighbor) == visited.end()) { // 아직 방문하지 않은 노드면 스택에 넣는다.
                s.push(neighbor);
            }
        }
    } 
}

int solution(int n, vector<vector<int>> computers) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (computers[i][j] == 1 && i != j) { // 자기 자신은 자식 노드로 넣지 않는다.
                adjList[i].push_back(j);
            }
        }
    }

    // 깊이우선탐색 실시. 시작은 0부터.
    dfs(0);

    // visited에 없는 노드 찾아내서 다시 깊이우선탐색 실시. 작은 숫자부터 다시 돌린다.
    for (int i = 0; i < n; i++) {
        if (visited.find(i) == visited.end()) { // 만약에 방문 기록에 없으면 그 노드를 시작으로 깊이우선탐색 다시 실시
            dfs(i);
        }
    }

    return cnt;    
}


int main() {

    int n; // 컴퓨터 개수
    vector<vector<int>> computers = {{1,1,0}, {1,1,0}, {0,0,1}};
    
    cout << solution(n, computers) << endl;;

    return 0;
}