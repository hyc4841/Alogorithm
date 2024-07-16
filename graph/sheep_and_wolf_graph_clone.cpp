#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<int, vector<int>> tree;
vector<int> visited, info2;
int answer = 0;

void dfs(vector<int> cur_route) { // 현재 순회 루트를 인수로 받음.
    int wolf = 0, sheep = 0;
    // 현재 순회한 루트에서 양과 늑대의 수를 계산
    for (auto i : cur_route) {
        if (info2[i] == 1) wolf++;
        else sheep++;
    }

    if (wolf >= sheep) return; // 늑대가 양의 수보다 같거나 크면 그만둔다.

    answer = max(answer, sheep); // 최대 양의 수 갱신

    for (auto node : cur_route) {
        for (auto child : tree[node]) {
            if (visited[child] == false) { // 현재 노드의 자식 노드 아직 방문 안했으면 방문하러 간다.
                visited[child] = true;
                cur_route.push_back(child);
                dfs(cur_route);
                cur_route.pop_back();
                visited[child] = false;
            }
        }
    }


}

int solution(vector<int> info, vector<vector<int>> edges) { // info는 양:0/늑대:1 정보, edges는 부모-자식 간선 정보
    // 간선 정보를 이진 트리로 만들어준다.
    for (auto i : edges) { // i에는 부모-자식 관계의 벡터가 담김
        tree[i[0]].push_back(i[0]);
    }

    // 시작 노드는 무조건 0번이고 양이다.
    info2 = info;
    
    visited[0] = true;
    dfs({0});

    return answer;
}


int main() {

    vector<int> info = {0,0,1,1,1,0,1,0,1,0,1,1};
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {1, 4}, {0, 8}, {8, 7}, {9, 10}, {9, 11}, {4, 3}, {6, 5}, {4, 6}, {8, 9}};
    

    return 0;
}