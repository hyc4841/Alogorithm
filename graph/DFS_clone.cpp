#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map<char, vector<char>> adjList; // map으로 인접 리스트를 구현함. value로 vector가 들어가는 이유는 해당 노드의 인접 노드가 두 개 이상일 수도 있기 때문에
vector<char> route; // 방문 경로. result 대시 더 직관적인 이름으로 route를 사용함.
unordered_set<char> visited; // 방문한 노드

// 깊이 우선 탐색 재귀 함수
void dfs(char node) {
    // 해당 노드를 방문처리와 방문 기록을 한다.
    route.push_back(node);
    visited.insert(node);

    // 인접 노드를 찾는다.
    for (char n : adjList[node]) {
        if (visited.find(n) == visited.end()) { // 해당 인접 노드가 아직 방문하지 않았다면
            dfs(n); // 재귀로 함수 돌린다. 이러한 구조는 시스템 스택을 이용한 것이므로 인접 노드의 인접 노드를 우선적으로 타고 들어가서 방문하는 구조를 만든다.
        }
    }
}

// 깊이 우선 탐색. 인접 리스트와 재귀 함수를 이용하여 구현.
// 깊이 우선 탐색은 해당 인접 노드의 인접 노드를 우선적으로 탐색하는 방식.
vector<char> solution(vector<pair<char, char>> graph, char start) {
    // 인접 리스트를 구죽해준다.
    for (auto &edge : graph) {
        char u = edge.first; // pair 자료 구조는 first와 second로 이루어져 있음.
        char v = edge.second;
        adjList[u].push_back(v); // adjList는 맵으로 key는 char고 value는 vector임 그래서 인덱스 접근 방식으로 접근하고 벡터 삽입 함수인 push_back을 사용.
    }

    dfs(start); // 시작 노드를 넣고 돌린다.

    return route;

}


int main() {

    vector<pair<char, char>> graph = {{'A', 'B'}, {'A', 'C'}, {'B', 'D'}, {'B', 'E'}, {'C', 'F'}, {'E', 'F'}};
    char start = 'A';
    
    vector<char> result = solution(graph, start);
    

    for (char i : result) {
        cout << i << " ";
    }

    return 0;
}