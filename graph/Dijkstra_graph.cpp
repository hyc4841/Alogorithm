#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max(); // numeric_limits 이용해서 int에서 사용할 수 있는 최대 숫자 넣는듯
const int MAX_NODES = 100;      // 최대 노드의 개수는 100개로 제한함.
int graph[MAX_NODES][MAX_NODES]; // 인접 행렬로 가중치 있는 그래프 표현
bool visited[MAX_NODES];        // 방문 기록 행렬

vector<int> solution(int start, int numNodes, vector<tuple<int, int, int>> edges) { // 시작 노드, 노드의 개수, 노드간 간선의 정보
    // 그래프 방문 여부 초기화
    for (int i = 0; i < MAX_NODES; ++i) {
        cout << "i의 값 : " << i << endl;
        fill_n(graph[i], MAX_NODES, INF); // fill_n은 행렬을 채울 때 사용하는 함수. (시작 위치, 끝 위치, 채울 값) 인수에 맞게 넣어서 행렬을 일제히 채운다.
        visited[i] = false; // 초기화니까 모든 방문은 false로 함.
    }

    // 입력받은 간선 정보를 그래프로 표현
    for (const auto& [from, to, weight] : edges) {
        graph[from][to] = weight; // 인접 행렬로 가중치 있는 그래프 구현한 거임.
    }

    // 시작 노드를 제외한 모든 노드의 최소 비용을 INF로 초기화
    vector<int> distances(numNodes, INF); // distances에는 시작 노드에서 부터 해당 노드까지의 거리를 저장함. 
    distances[start] = 0; // 시작 노드의 최소 비용은 0으로 초기화

    ////////////////////////////////////여기 까지는 초기화 단계////////////////////////////////////

    for (int i = 0; i < numNodes - 1; ++i) { // 반복 횟수를 노드 수 - 1 번 반복한다. i가 노드를 의미하는 것이 아니다.
        int minDistance = INF; // 현재 최소 거리를 표현
        int closestNode = -1;
        // 왜 반복 횟수를 노드 수에서 하나를 뺏을까?
        for (int j = 0; j < numNodes; ++j) {

            if (!visited[j] && distances[j] < minDistance) {
                minDistance = distances[j];             // 0 - 0 최소 거리 0
                closestNode = j;                        // 직전 노드 0
            }
        }

        visited[closestNode] = true; // 0번 노드 방문 처리

        // 인접 노드에 대한 거리 업데이트
        for (int j = 0; j < numNodes; ++j) {
            int newDistance = distances[closestNode] + graph[closestNode][j]; // 직전 노드인 0번 노드까지의 거리 + 직전 노드인 0번 노드에서 j번 노드 까지의 거리.
            if (!visited[j] && graph[closestNode][j] != INF && newDistance < distances[j]) { // 아직 방문 안한 노드 중에서, 간선이 존재하고(graph에서 INF값이 들어가 있으면 간선이 존재하지 않다는 의미
                                                                                             // 직전 노드를 거쳐서 가는게 비용이 더 적게 들면
                distances[j] = newDistance; // 최소 거리를 새로운 최소 거리로 바꿔준다.
            }
        }
    }
    /*
    결국 중요한건 시작 노드부터 각 노드까지의 최소 거리를 구하는 것이 중요한 것.
    방문 찍는게 중요한게 아님.
    (노드 수 - 1) 만큼 순회하는 이유는 구해야할 최소 거리의 개수가 노드 수 - 1 이기 때문
    마지막 노드는 방문을 찍지 않아도 되기 때문.
    */
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