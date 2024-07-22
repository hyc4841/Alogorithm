#include <vector>
#include <iostream>
#include <tuple>
#include <algorithm>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();
const int MAX_NODE = 100; // 최대 노드의 개수
int graph[MAX_NODE][MAX_NODE];
bool visited[MAX_NODE];

// 다익스트라 알고리즘
vector<int> solution(int start, int numNodes, vector<tuple<int, int, int>> edges) {
    for (int i = 0; i < MAX_NODE; i++) {
        fill_n(graph[i], MAX_NODE, INF); // (채울 컨테이너, 개수, 값)
        visited[i] = false;
    }
        
    // 그래프 초기화 graph[부모][자식] = 가중치 형식으로 저장함.
    for (auto &[from, to, w] : edges) {
        graph[from][to] = w;
    }

    // 각 노드들의 최소 거리를 담을 백터
    vector<int> distance(numNodes, INF);
    
    // 시작 노드 거리 초기화
    distance[start] = 0;

    for (int i = 0; i < numNodes - 1; i++) {
        int minDistance = INF;
        int closest = -1;

        // 현재 방문하지 않은 노드 중 최소거리를 갖고 있는 노드 찾기
        for (int j = 0; j < numNodes; j++) {
            if (!visited[j] && minDistance > distance[j]) {
                minDistance = distance[j]; // 현재 최소 거리
                closest = j; // 현재 최소 거리 노드
            }
        }

        visited[closest]; // 현재 최소거리 노드 방문처리

        // 최소 거리 노드를 찾았으니까 이 노드를 토대로 시작노드 - 각 노드 의 최소 거리를 갱신한다.
        for (int k = 0; k < numNodes; k++) {
            int newDistance = distance[closest] + graph[closest][k]; // 현재 최소 거리 노드를 지나쳐서 가는 루트
            if (!visited[k] && newDistance < distance[k]) { // 아직 방문하지 않았고 기존 루트의 가중치가 더 크면, 그리고 해당 부모 자식 사이에 간선이 존재하면
                distance[k] = newDistance;
            }
        }
    }
}


int main() {
    


    return 0;
}