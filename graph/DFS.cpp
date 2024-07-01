#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map<char, vector<char>> adjList; // 인접 리스트
vector<char> result; // 방문 경로
unordered_set<char> visited; // 방문한 노드 기록용

// 트리 - 깊이 우선 탐색 구현
// 인접 리스트를 이용한 깊이 우선 탐색 알고리즘. 재귀 함수로 구현. 

void dfs(char node) {
    // 현재 노드를 방문한 목록과 방문한 경로에 추가
    visited.insert(node);
    result.push_back(node);

    // 현재 노드와 인접한 노드 중, 방문하지 않은 노드에 깊이 우선 탐색을 계속 진행
    for (char neighbor : adjList[node]) {
        if (visited.find(neighbor) == visited.end()) { // 인접 리스트에서 꺼내온 노드가 방문자 기록 집합에 없으면
            dfs(neighbor); // 재귀 함수로 돌려버림
        }
    }
}

vector<char> solution(vector<pair<char, char>> graph, char start) {
    // 인접 리스트 생성
    for (auto &edge : graph) {
        char u = edge.first;
        char v = edge.second;
        adjList[u].push_back(v);
    }

    // 시작 노드부터 깊이 우선 탐색 시작
    dfs(start);
    return result;
}


int main() {




    return 0;
}

// 깊이 우선 탑색은 기본적으로 스택으로 구현된다고 생각하면 된다.
// 스택을 직접 이용하지 않고, 재귀함수로 구현해도 시스템 스택을 이용하는 것이므로 결국엔 스택의 원리를 이용하는 것.
