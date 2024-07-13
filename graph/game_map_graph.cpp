#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool visited[101][101] = {false}; // 방문 여부 기록 행렬

// 상하좌우 오프셋
int dy[4] =  {-1, 1, 0, 0};
int dx[4] =  {0, 0, -1, 1};

struct Point {
    int x, y, cnt;
};

bool isright(int x, int y, int n, int m) { // 해당 좌표가 유효한지 검증.
    return y >= 0 && y < n && x >= 0 && x < m;
}


int solution(vector<vector<int>> maps) {
    // 시작 위치는 1, 1이고 도착 지점은 n, m이다.
    // 여기서는 편의상 0, 0부터 시작한다고 생각하고, 도착도 n-1, m-1로 생각한다.

    int n = maps.size(); // 맵의 세로 길이
    int m = maps[0].size(); // 가로 길이

    // 너비우선 탐색으로 최단 거리를 측정한다.
    queue<Point> q;
    q.push({0, 0, 1}); // 시작 지점을 먼저 넣어둔다
    visited[0][0] = true; // 시작 지점을 방문 처리한다.

    while (!q.empty()) {
        Point cur_node = q.front(); // 현재 노드 저장해주고
        q.pop();

        if (cur_node.y == n-1 && cur_node.x == m-1) { // 만약 현재 노드가 도착 지점이면 끝낸다
            return cur_node.cnt;
        }

        for (int i = 0; i < 4; i++) {
            int x = cur_node.x + dx[i];
            int y = cur_node.y + dy[i];
            if (isright(x, y, n, m) && maps[y][x] == 1) { // 해당 좌표가 유효하고 지나갈 수 있는 길이면.
                q.push({x, y, cur_node.cnt + 1});
                visited[y][x] = true;
            }
        }
    }

    return -1; // while문 다 돌았는데도 도착지점에 도달 못하면 -1 반환
}


int main() {

    // 맵의 크기는 n * m으로 n과 m은 서로 다를 수 있다.
    vector<vector<int>> maps = {
        {1,0,1,1,1}, 
        {1,0,1,0,1}, 
        {1,0,1,1,1}, 
        {1,1,1,0,1},
        {0,0,0,0,1}};

    int answer = solution(maps);

    cout << answer << endl;

    return 0;
}