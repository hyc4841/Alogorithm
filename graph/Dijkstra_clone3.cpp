#include <iostream>
#include <vector>
#include <tuple>
#include <limits>
#include <algorithm>

using namespace std;

const int INF = numeric_limits<int>::max();
const int MAX_NODE = 100;
int graph[MAX_NODE][MAX_NODE]; // 그래프를 인접 행렬로 구현
bool visited[MAX_NODE];

// 복습용 코드

vector<int> solution(int start, int num_nodes, vector<tuple<int, int, int>> edges) {
    // 초기화 단계
    for (int i = 0; i < MAX_NODE; ++i) {
        fill_n(graph[i], MAX_NODE, INF);
        visited[i] = false;
    }

    for (const auto &[from, to, weight] : edges) {
        graph[from][to] = weight;
    }

    vector<int> distances(num_nodes, INF); // 최종적으로 리턴할 최소거리를 담을 백터 선언
    distances[start] = 0; // 시작 노드의 최소 거리는 0으로 초기화

    // 실제 최소 거리 구하는 알고리즘
    for (int i = 0; i < num_nodes-1; ++i) {
        int minDistance = INF;  // 최소 거리 임시 저장 변수
        int closest_node = -1; // 직전 노드 저장 변수

        // 최소 거리 노드 찾기
        for (int j = 0; j < num_nodes; ++j) {
            if (!visited[j] && distances[j] < minDistance) { // 아직 방문하지 않았고 전 노드 보다 최소 거리가 작으면 선정
                minDistance = distances[j]; // 최소 거리로 설정
                closest_node = j;           // 직전 노드로 설정
            }
        }

        visited[closest_node] = true; // 선정된 최소거리 노드 방문 처리

        for (int j = 0; j < num_nodes; ++j) { // 최소 거리 갱신
            int newDistance = distances[closest_node] + graph[closest_node][j]; // 시작 노드에서 j 노드까지 가는데 직전 노드를 거쳐서 가는게 빠른지 바로 가는게 빠른지 재보기 위해
            if (!visited[j] && graph[closest_node][j] != INF && newDistance < distances[j]) {
                distances[j] = newDistance;
            }
        }
    }

    return distances;

}

int main() {

    int start = 0;
    int numNodes = 3;
    vector<tuple<int, int, int>> edges;
    edges.push_back(make_tuple(0, 1, 9));
    edges.push_back(make_tuple(0, 2, 3));
    edges.push_back(make_tuple(1, 0, 5));
    edges.push_back(make_tuple(2, 1, 1));

    vector<int> result = solution(start, numNodes, edges);

    for (int i : result) {
        cout << i << " ";
    }

    return 0;
}