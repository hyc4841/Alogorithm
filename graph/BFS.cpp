#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// 트리 - 너비 우선 탐색 구현
// 큐를 이용해 구현
unordered_map<int, vector<int>> adjList; // 인접 리스트
vector<int> result; // 방문 경로

void bfs(int start) {
    unordered_set<int> visited;
    queue<int> q;

    // 시작 노드 방문
    q.push(start);
    
    visited.insert(start);
    result.push_back(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        // 현재 노드의 인접 노드 중 아직 방문하지 않은 노드 방문
        for (int neighbor : adjList[node]) {
            if (visited.find(neighbor) == visited.end()) {
                q.push(neighbor);
                visited.insert(neighbor);
                result.push_back(neighbor);
            }
        }
    }
}

vector<int> solution(vector<pair<int, int>> graph, int start) {
    // 인접 리스트 생성
    for (auto &edge : graph) {
        int u = edge.first;
        int v = edge.second;
        adjList[u].push_back(v);
    }

    // 시작 노드부터 너비 우선 탐색 시작

    return result;
}

int main() {

    return 0;
}
