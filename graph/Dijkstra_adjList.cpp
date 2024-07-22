#include <vector>
#include <tuple>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first; // 거리가 작은 순서대로 정렬
    }
};

vector<int> solution(int start, int numNodes, vector<tuple<int, int, int>> edges) {

    // 간선 정보를 이용해서 인접 리스트 생성
    vector<vector<pair<int, int>>> adjList(numNodes);
    
    for (const auto& [from, to, w] : edges) {
        adjList[from].emplace_back(to, w); // emplace_back은 알아서 객체 생성해서 넣어준다. push_back은 직접 객체 생성해서 넣어야함.
    }

    // 시작노드를 제외한 모든 노드의 최소비용을 INF로 초기화
    vector<int> distance(numNodes, INF);
    distance[start] = 0;

    // 우서순위 큐에 시작 노드 추가
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq; // 가장 작은 값부터 출력되게 하려고 이렇게 선언함.
    pq.push({0, start});

    // 노드의 방문 여부를 저장하는 배열
    vector<bool> visited(numNodes, false);

    while (!pq.empty()) {
        int currentDistance = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        if (visited[currentDistance]) continue; // 이미 방문한 노드인 경우 무시

        visited[currentDistance] = true; // 현재 노드 방문 처리

        // 인접 노드에 대한 거리 업데이트
        for (const auto& [neighbor, weight] : adjList[currentNode]) {
            int newDistance = distance[currentNode] + weight;
            
            if (newDistance < distance[neighbor]) {
                distance[neighbor] = newDistance;
                pq.push({newDistance, neighbor});
            }
        }

    }

    return distance;

}




int main() {


    return 0;
}