#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map<char, vector<char>> adjList; // 맵으로 인접 리스트 구현
unordered_set<char> visited; // set으로 방문 기록 구현
vector<char> result;

void dfs(char node) {
    // 노드를 인수로 받는다
    // 노드가 들어오면 방문처리한다.
    // 현재 노드의 자식 노드를 탐색하고 dfs 함수를 호출한다.
    visited.insert(node);
    result.push_back(node);

    // 현재 노드의 자식 노드 탐색.
    for (auto &child : adjList[node]) {
        // 해당 자식 노드가 아직 방문처리가 되어 있지 않으면
        if (visited.find(child) == visited.end()) {
            dfs(child);
        }
    }
}

// 재귀로 깊이 우선탐색 구현하기
vector<char> solution(vector<vector<char>> graph, char start) { // 그래프에는 a, b와 같이 부모 - 자식 관계가 들어 있음.
    // 시작노드(현재노드) 스택에 넣기 -> 스택에서 빼면서 방문처리하기 -> 시작노드(현재노드)의 자식노드 스택에 넣기 -> 자식노드가 현재 노드가 되고 앞 과정 반복하기
    for (auto &edge : graph) {
        // edge[0] : 부모, edge[1] : 자식
        adjList[edge[0]].push_back(edge[1]);
    }

    dfs(start);

    return result;
}


int main() {
    vector<vector<char>> graph = {{'A', 'B'}, {'A', 'C'}, {'B', 'D'}, {'B', 'E'}, {'C', 'F'}, {'E', 'F'}, };
    char start = 'A';
    
    vector<char> answer = solution(graph, start);

    for (auto i : answer) {

        cout << i << " ";
    }


    return 0;
}