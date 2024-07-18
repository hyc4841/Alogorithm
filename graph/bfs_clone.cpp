#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map<int, vector<int>> adjList; // 맵으로 인접 리스트 구현
unordered_set<int> visited; // set으로 방문 기록 구현



// 큐로 너비우선탐색 구현하기
vector<int> solution(vector<pair<int, int>> graph, int start) {
    // graph는 부모 - 자식 정보를 담은 백터
    vector<int> answer; // 방문 경로 담을 백터 선언
    queue<int> q;

    for (auto &edge : graph) {
        int u = edge.first;
        int v = edge.second;
        adjList[u].push_back(v);
    }    

    // 시작노드(현재 노드) 큐에 넣고 방문처리
    // 시작노드(현재 노드)의 자식 노드 큐에 넣기
    // 시작노드(현재노드) 큐에서 pop시키기
    // 위 과정 반복
    // 큐가 비어 있으면 모든 노드를 순회한 것. 종료
    q.push(start);
    visited.insert(start); // 방문 처리
    answer.push_back(start); // 방문 경로 삽입
    
    // 방문 처리 시점이 이러한 이유는 자식이 두 개 이상의 부모를 가질 수 있기 때문에 자식이 중복해서 큐에 들어갈 수 있음. 방문 순서 큐에 넣는 시점에 방문처리를 미리 해버리는 것.
    while (!q.empty()) {
        int cur_node = q.front(); // 현재 노드
        q.pop();
        
        // 현재 노드의 자식노드 탐색
        for (auto &child : adjList[cur_node]) {
            if (visited.find(child) == visited.end()) {
                q.push(child);
                visited.insert(child); // 방문 처리
                answer.push_back(child); // 방문 경로 삽입
            }
        }
    }
    return answer;   
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