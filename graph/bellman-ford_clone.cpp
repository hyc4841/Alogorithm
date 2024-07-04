#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <tuple>

using namespace std;

const int INF = numeric_limits<int>::max();

vector<int> solution(int num_vertices, vector<tuple<int, int, int>> edges, int source) {
    // 초기화 단계
    vector<vector<tuple<int, int>>> graph(num_vertices);

    for (auto &edge : edges) {
        int from, to, weight;
        tie(from, to, weight) = edge;
        graph[from].emplace_back(to, weight);
    }

    vector<int> distance(num_vertices, INF); // 시작 노드에서 각 노드까지의 최단거리 저장 백터 선언 및 초기화
    distance[source] = 0; // 시작 노드의 거리는 0으로 만들어준다.

    for (int i = 0; i < num_vertices - 1; ++i) { // 반복 횟수는 노드 수 - 1. 이유는 시작 노드에서 각 노드까지의 최단 거리의 개수가 총 노드 수 -1 이기 때문.
        for (int u = 0; u < num_vertices; ++u) { // 노드 하나씩 순회한다.
            for (auto &[v, weight] : graph[u]) {
                if (distance[v] > distance[u] + weight) { // 기존 최단 거리보다 직전 노드를 거쳐서 가는게 더 빠르다면 바꿔준다.
                    distance[v] = distance[u] + weight;
                }
            }
        }
    }
    
    // 음의 순환이 있는지 확인
    for (int u = 0; u < num_vertices; ++u) {
        for (auto &[v, weight] : graph[u]) {
            if (distance[v] > distance[u] + weight) {
                return vector<int>(1, -1);
            }
        }
    }

    return distance;

}

int main() {

int num_vertices = 5;
    vector<tuple<int, int, int>> edges;
    edges.push_back(make_tuple(0, 1, 4));
    edges.push_back(make_tuple(0, 2, 3));
    edges.push_back(make_tuple(0, 4, -6));
    edges.push_back(make_tuple(1, 3, 5));
    edges.push_back(make_tuple(2, 1, 2));
    edges.push_back(make_tuple(3, 0, 7));
    edges.push_back(make_tuple(3, 2, 4));
    edges.push_back(make_tuple(4, 2, 2));
    int source = 0;

    vector<int> result = solution(num_vertices, edges, source);
    for (int i : result) {
        cout << i << " ";
    }
    
    return 0;
}