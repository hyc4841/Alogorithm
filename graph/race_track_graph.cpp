#include <cstring>
#include <limits>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;


// 직선과 코너의 비용 정의
const int STRAIGHT = 100;
const int CORNER = 600;

// 방향 오프셋 정의
const int dx[4] = {0, 0, -1, 1}; // 0부터 상하좌우 순서
const int dy[4] = {-1, 1, 0, 0};

const int INF = numeric_limits<int>::max();

struct Point {
    int x, y, dir;
};

bool isValid(int x, int y, int mapSize) {
    return x >= 0 && x < mapSize && y >= 0 && y < mapSize; // x, y는 맵 크기보다 작아야 하고, 0과 같거나 커야 한다.
}

int solution(vector<vector<int>> board) {
    // board에는 0과 1로 된 맵이 들어있음. 0은 건설 가능, 1은 벽으로 건설 불가능임. 2차원 배열
    // board는 N * N임
    int mapSize = board.size(); // 맵 크기

    int map[mapSize][mapSize][4]; // 2차원까지의 인덱스는 해당 좌표, 3차원 인덱스는 방향, 값은 해당 좌표까지의 비용
    memset(map, -1, sizeof(map)); // 이렇게 하면 map 배열 안에 모두 -1로 채워진다?
    // -1은 방문하지 않은 상태.

    queue<Point> q;

    // 너비우선탐색 실시. 시작 좌표는 넣고 시작. 시작은 시작 지점에서 오른쪽(우), 아래쪽(하) 방향 넣어준다.
    q.push({0, 0, 1});
    q.push({0, 0, 3});

    map[0][0][1] = 0; // 비용 정의
    map[0][0][3] = 0;

    while (!q.empty()) {
        Point cur = q.front(); // 현재 좌표 일단 저장.
        q.pop();

        int cur_Cost = map[cur.y][cur.x][cur.dir];

        // 현재 좌표에서 상하좌우로 갈만한 좌표 있는지 탐색.
        for (int i = 0; i < 4; i++) {
            int next_x = cur.x + dx[i]; // 다음 x, y 좌표 정의
            int next_y = cur.y + dy[i];

            // 다음 좌표가 1이면 벽이니까 못감. 그래서 건너뛴다.
            if (!isValid(next_x, next_y, mapSize) || board[next_y][next_x] == 1) continue;

            int cost = (i == cur.dir ? STRAIGHT : CORNER); // 이전 진행 방향과 같으면 100원, 다르면 600원
            int newCost = cur_Cost + cost;
            // map[next_y][next_x][i]는 기존 비용이라고 생각하면 됨 


            if (map[next_y][next_x][i] == -1 || map[next_y][next_x][i] > newCost) { // 아직 방문을 안했거, 기존에 구한 비용보다 적으면 비용 갱신하고 큐에 넣는다.
                q.push({next_x, next_y, i});
                map[next_y][next_x][i] = newCost;
            }

        }
    }


    // 루프문 다 돌면 비용 계산 끝 이제 도착 지점 비용
    int answer = INF;
    for (int i = 0; i < 4; i++) {
        if (map[mapSize - 1][mapSize -1][i] != -1) {
            answer = min(answer, map[mapSize - 1][mapSize -1][i]);
        }
    }

    return answer;

    

}


int main() {

    vector<vector<int>> board = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    cout << solution(board) << endl;

    return 0;
}