#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();
const int MAX_NODE = 100;
int graph[MAX_NODE][MAX_NODE];
bool visited[MAX_NODE];

// 복습용 코드

vector<int> solution(int start, int num_nodes, vector<tuple<int, int, int>> edges) {
    for (int i = 0; i < MAX_NODE; ++i) {
        fill_n(graph[i], MAX_NODE, INF);
        visited[i] = false;
    }

    for (const auto &[from, to, weight] : edges) {
        graph[from][to] = weight;
    }

    vector<int> distances(num_nodes, INF);
    distances[start] = 0;

    for (int i = 0; i < num_nodes - 1; ++i) { // num_nodes - 1번 순회
        int minDistance = INF;
        int closestNode = -1; // 직전 노드

        for (int j = 0; j < num_nodes; ++j) { // 인접 노드 찾기
            
            if (!visited[j] && distances[j] < minDistance) { // 아직 방문하지 않았고, 현재 까지 구한 [start - j] 거리 중에서 최소 거리가 되는 노드 찾기 
                minDistance = distances[j];
                closestNode = j;
            }
        }

        visited[closestNode] = true;

        for (int j = 0; j < num_nodes; ++j) {
            int newDistance = distances[closestNode] + graph[closestNode][j];
            
            if (!visited[j] && graph[closestNode][j] != INF && newDistance < distances[j]) {
                distances[j] = newDistance;
            }
        }
    }

    return distances;

}

int main() {

    return 0;
}