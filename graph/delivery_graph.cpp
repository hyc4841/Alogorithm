#include <iostream>
#include <vector>
#include <limits>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> road, int k) {
    vector<pair<int, int>> graph[n+1];
    vector<int> distances(n+1, numeric_limits<int>::max());
    vector<bool> visited(n+1, false);
    distances[1] = 0;

    // 방향이 따로 없으므로 양방향 동일한 가중치
    for (const auto &r : road) {
        int from = r[0], to = r[1], w = r[2];
        graph[from].push_back({to, w});
        graph[to].push_back({from, w});
    }

    // 출발점을 heap에 추가
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    heap.push({0, 1});

    while (!heap.empty()) {
        int dist = heap.top().first;
        int node = heap.top().second;
        heap.pop();

        if (visited[node]) continue;

        visited[node] = true;

        for (const auto &next : graph[node]) {
            int next_node = next.first;
            int next_dist = next.second;
            int cost = dist + next_dist;
            // 거쳐가는 노드로 가는 경로의 비용이 더 짧으면 최소 비용 갱신
            if (cost < distances[next_node]) {
                distances[next_node] = cost;
                heap.push({cost, next_node});
            }
        }
    }

    int count = 0;

    // 거리가 k 이하인 장소를 카운트
    for (int i = 1; i <= n; i++) {
        if (distances[i] <= k) 
            count++;
    }

    return count;

}


int main() {

    int n = 5; // 노드 수
    vector<vector<int>> road = {{1, 2, 1}, {2, 3, 3}, {5, 2, 2}, {1, 4, 2}, {5, 3, 1}, {5, 4, 2}}; // 간선과 가중치 정보
    int k = 3; // 가중치 제한


    

    return 0;
}