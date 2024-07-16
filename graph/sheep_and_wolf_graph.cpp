#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> tree; // 이진 트리임.
vector<int> visited, comp; // comp는 info(양과 늑대 정보)의 복사본
int n, answer = 0;


void dfs(vector<int> cur) { // cur은 현재 방문한 경로를 저장한 백터
    int sheep = 0, wolf = 0;
    // 현재 방문한 경로를 기준으로 양과 늑대의 개수를 셈
    for (int c : cur) {
        if (comp[c] == 1) wolf++;
        else sheep++;
    }

    if (sheep <= wolf) return; // 늑대의 숫자가 양보다 같거나 크면 종료

    answer = max(answer, sheep);

    for (int i = 0; i < cur.size(); i++) {
        int node = cur[i];
        // 현재 노드와 인접한 노드를 순회
        for (int g : tree[node]) {
            if (visited[g]) continue; // 이미 방문한 노드는 건너뜀

            // 현재 노드를 방문한 경우, 하지 않은 경우 모두 확인
            visited[g] = true; // true는 1임 방문처리해줌.

            cur.push_back(g);
            dfs(cur);
            cur.pop_back(); // 한쪽 자식 볼때 다른 한쪽 자식이 방문 처리 되어있으면 이상하잖아.
            visited[g] = false;
        }
    }
}


int solution(vector<int> info, vector<vector<int>> edges) {

    n = info.size();
    tree.resize(n);
    visited.resize(n, false);
    comp = info;

    // 이진 트리 형성
    for (auto e : edges) {
        // edges[i][0] : 부모, edges[i][1] : 자식
        tree[e[0]].push_back(e[1]);
    }

    visited[0] = true;
    // 방문 여부를 체크하고, 시작 노드부터 탐색 시작
    dfs({0});

    return answer;
}


int main() {

    vector<int> info = {0,0,1,1,1,0,1,0,1,0,1,1};
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {1, 4}, {0, 8}, {8, 7}, 
                                {9, 10}, {9, 11}, {4, 3}, {6, 5}, {4, 6}, {8, 9}};


    return 0;
}