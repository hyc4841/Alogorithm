#include <vector>
#include <iostream>
#include <unordered_set>
#include <queue>
#include <unordered_map>
#include <limits>
#include <math.h>

using namespace std;

const int INF = 500;
unordered_map<int, vector<int>> node_rel;

// 해당 노드와 연결된 노드 개수 반환
int nodeNum(int node, int no_node) { // node : 이 노드와 연결된 노드 확인하고 싶음. no_node : 이 노드는 node와 연결을 끊은 노드임.
    queue<int> q; 
    unordered_set<int> visited;

    q.push(node); // 시작 노드 먼저 넣기
    visited.insert(node);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto &neighbor : node_rel[cur]) {
            if (neighbor == no_node || visited.find(neighbor) != visited.end()) 
                continue; // 연결 끊은 노드가 나오면 건너뛴다.

            q.push(neighbor);
            visited.insert(neighbor);
        }
    }
    return visited.size();
}


int solution(int n, vector<vector<int>> wires) {
    int answer = INF;

    for (auto &wire : wires) {
        node_rel[wire[0]].push_back(wire[1]); // 양방향이기 때문에 양쪽 다 넣어줌
        node_rel[wire[1]].push_back(wire[0]);
    }

    for (int i = 0; i < wires.size(); i++) {
        int a = wires[i][0]; // 끊을 두 노드
        int b = wires[i][1];

        int num_a = nodeNum(a, b);
        int num_b = n - num_a;

        int diff = abs(num_a - num_b);

        if (diff == 0) return 0;

        answer = min(answer, diff);
    }
    return answer;    
}

int main() {
    int n = 9;
    // vector<vector<int>> wires = {{1,3}, {2,3}, {3,4}, {4,5}, {4,6}, {4,7}, {7,8}, {7,9}};
    vector<vector<int>> wires = {{1,2}, {2,7}, {3,7}, {3,4}, {4,5}, {6,7}};


    int answer = solution(n, wires);
    cout << answer << endl;

    return 0;
}