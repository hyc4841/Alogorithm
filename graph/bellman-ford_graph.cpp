#include <limits>
#include <tuple>
#include <vector>
#include <iostream>

using namespace std;

const int INF = numeric_limits<int>::max();

vector<int> solution(int num_vertices, vector<tuple<int, int, int>> edges, int source) {

    vector<vector<pair<int, int>>> graph(num_vertices);

    // 간선 정보를 활용해서 인접 리스트를 생성
    for (auto &edge : edges) {
        int from, to, weight;
        tie(from, to, weight) = edge; // tie()는 다수의 변수에 한 번에 값을 할당하기 위해 사용한다. 순서에 맞춰서 할당됨.
        graph[from].emplace_back(to, weight); // emplace_back : 객체 생성 없이 백터에 push_back 할 수 있음. push_back은 객체를 만들어주고 널어야함.
    }

    // 현재까지 구한 최소 비용을 INF로 설정(시작 노드는 제외)
    vector<int> distance(num_vertices, INF);
    distance[source] = 0;

    //////////////////////

    // 정점의 개수 -1 만큼 최소 비용 갱신
    for (int i = 0; i < num_vertices - 1; ++i) {
        for (int u = 0; u < num_vertices; ++u) { // u -> v
            for (const auto &[v, weight] : graph[u]) { // graph에서 u에서 접근할 수 있는 노드들을 차례로 꺼낸다.
                if (distance[u] + weight < distance[v]) { // 만약에 기존에 (시작노드 - v) 까지의 거리가 새로운 (시작노드 - u) + (u - v) => weight 보다 크다면 갱신해준다.
                    distance[v] = distance[u] + weight; // 노드 u를 거쳐서 가는게 더 빠르니까 갱신해준다. 그럼 dis[v]에 담기게 되는 값은 (시작 - u - v)의 거리가 된다.
                }
            }
        }
        /*
            모든 노드들을 차례로 순회한다.
            0번 노드에서 접근할 수 있는 노드들 끄집어 낸다.
            0번 - v 
            기존에 (시작 - v)거리와 (시작 - 0번 - v) 거리 둘 중 작은 값을 고른다. 거쳐 가는게 빠르면 그 거리를 distance[v]에 넣으면 된다.
        */
    }

    // 위 알고리즘 끝났으면 원래는 시작노드에서 각 노드까지의 최소 거리가 결정 된것이다. 그런데 음의 순환이 있는 경우는 그 최소 거리가 되는 값이 계속 갱신된다.
    // 최소 거리가 갱신 되는 경우는 기존 거리가 아닌, 새롭게 노드를 경유해서 가는 경우임.
    // 음의 순환이 있는지 확인
    for (int u = 0; u < num_vertices; ++u) {
        for (const auto &[v, weight] : graph[u]) {
            if (distance[u] + weight < distance[v]) { // 새롭게 갱신된다? 그럼 음의 순환임
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