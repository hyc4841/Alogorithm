#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <limits>

using namespace std;

int INF = numeric_limits<int>::max(); // 초기값 세팅용 INF
const int MAX_NODE = 100;             // 최대 노드의 개수
int graph[MAX_NODE][MAX_NODE];        // 그래프를 인접 행렬로 구축
bool visited[MAX_NODE];               // 방문 노드 기록 배열

vector<int> solution(int start, int numNodes, vector<tuple<int, int, int>> edges) {
    for (int i = 0; i < MAX_NODE; ++i) {
        fill_n(graph[i], MAX_NODE, INF);    // 그래프 안에 값 모두 INF로 초기화
        visited[i] = false;                 // 방문 노드 모두 false로 초기화
    }

    for (const auto &[from, to, weight] : edges) { // edges에 들어있는 값들은 (시작 노드, 도착 노드, 가중치)로 되어있는 tuple값임.
        graph[from][to] = weight;                  // 인접 행렬로 그래프 구축
    }

    vector<int> distances(numNodes, INF);  // 최소 거리 기록 백터
    distances[start] = 0;                  // 시작 노드는 최소 거리 0으로 초기화         
    
    for (int i = 0; i < numNodes - 1; ++i) { // 노드 수 - 1 만큼 순회. 시작 노드 부터 다른 노드 까지의 최소 거리가 총 (노드 수 - 1)개 이기 때문. 
        int closestNode = -1;   // 직전 노드 정의
        int minDistance = INF;  // 최소 거리

        for (int j = 0; j < numNodes; ++j) { // 인접 노드 중 최소거리인 노드 찾기
             
            if (!visited[j] && distances[j] < minDistance) { // 아직 방문하지 않고, (시작 노드에서 j번 노드까지의 최소거리) 가 (시작 노드에서 다른 노드까지의 거리)보다 작으면
                minDistance = distances[j];  // 시작 노드 부터 j까지의 거리를 최소 거리로 갱신한다.
                closestNode = j;             // 직전 노드를 j로 바꾼다.
            }
        }

        // 위 for문을 최소 거리인 노드를 방문 처리한다.
        visited[closestNode] = true;

        for (int j = 0; j < numNodes; ++j) {
            int newDistance = distances[closestNode] + graph[closestNode][j];
            if (!visited[j] && graph[closestNode][j] != INF && newDistance < distances[j]) {
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