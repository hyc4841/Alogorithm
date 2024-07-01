#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

unordered_map<int, vector<int>> adjList; // 인접 리스트. 해당 노드의 인접 노드 기록
vector<int> route; // 이동 경로 기록

// 너비 우선 탐색은 큐를 이용할 뿐 재귀 원리를 이용하지 않는다. 흐르듯이 간다.
void bfs(int start) {
    unordered_set<int> visited; // 방문 노드 기록. 재귀하거나 그럴것이 아니고 이 함수 안에서 다 끝나기 때문에 지역 변수로 선언
    queue<int> q; // 인접 노드 탐색할 노드 기록용

    // 처음 시작 노드가 들어오면 큐에 넣어주고 방문처리 한다.
    q.push(start);
    visited.insert(start);  // 방문한 노드로 기록
    route.push_back(start); // 이동 경로도 넣어준다.
    
    while (!q.empty()) { // 큐가 비어 있으면 모두 순회 한것이므로 종료한다.
        int node = q.front(); // 현재 큐 맨 앞에 있는 노드 기록
        q.pop(); // 현재 노드를 큐에서 뺀다. 빼주는 이유는 방문 기록도 다 했고, 현재 노드 기록도 다 했으므로
        
        for (auto &neighbor : adjList[node]) { // 현재 노드의 인접 노드 확인.
            if (visited.find(neighbor) == visited.end()) { // 방문자 리스트에 없으면 큐에 넣고 방문 처리한다.
                q.push(neighbor);
                visited.insert(neighbor);
                route.push_back(neighbor);
            }
        }
    } // 이런건 역시 쉽게 떠올리기 쉽지 않으니까 학습을 통해 익혀놔야 한다.
        // 시작 노드를 큐에 넣고 방문 처리
        // 시작 노드를 현재 노드에 기록하고
        // 반복문 시작할 때 미리 빼줌.
        // 현재 노드의 인접 노드 탐색하고, 발견하면 큐에 넣고 방문처리 싹 함.
        // 이렇게 되면 시작 노드가 미리 빠졌으니까 큐 맨 앞에는 시작 노드의 인접 노드가 맨 앞쪽에 있게 됨. 자연스럽게 해당 노드의 인접 노드를 우선적으로 먼저 방문하고 다음 인접 노드로 넘어간다.
}

vector<int> solution(vector<pair<int, int>> graph, int start) {
    
    // 인접 리스트 구축
    for (auto &edge : graph) {
        int v = edge.first;
        int u = edge.second;
        adjList[v].push_back(u); // 인덱스 접근 방식으로 map에 접근해서 value가 vector니까 push_back 해줌
    }

    bfs(start);

    return route;
}


int main() {

    vector<pair<int, int>> graph = {{1, 2}, {1, 3}, {2, 4}, {2, 5}, {3, 6}, {3, 7}, {4, 8}, {5, 8}, {6, 9}, {7, 9}};
    int start = 1;

    vector<int> result = solution(graph, start);

    for (int i : result) {
        cout << i << " ";
    }

    return 0;
}