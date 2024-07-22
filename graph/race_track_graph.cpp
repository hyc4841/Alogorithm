#include <cstring>
#include <limits>
#include <queue>
#include <vector>

using namespace std;

// 상하좌우 오프셋
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
// 직선, 코너 비용 정의
const int STRAIGHT_COST = 100;
const int CORNER_COST = 600;   

const int MAX_SIZE = 26;
const int INF = numeric_limits<int>::max();

struct Path {
    int y, x, direction; // 이번엔 방향 조건까지 추가되었다.
};

bool isValid(int y, int x, int size) { // size는 맵의 크기
    return y >= 0 && y < size && x >= 0 && x < size;
}

int solution(vector<vector<int>> board) {

    int boardSize = static_cast<int>(board.size()); // 여기서 static_cast를 해주는 이유는?
    int dist[MAX_SIZE][MAX_SIZE][4];
    
    memset(dist, -1, sizeof(dist));
    queue<Path> q;

    // 시작 지점의 방향에 따라 비용이 달라질 수 있으므로 모든 경우의 수 고려
    q.push({0, 0, 1});
    q.push({0, 0, 3});

    dist[0][0][1] = 0;
    dist[0][0][3] = 0;

    while (!q.empty()) {
        auto [y, x, dir] = q.front();
        q.pop();

        int lastCost = dist[y][x][dir];

        // 현재 지점을 기준으로 이동 가능한 지점 확인
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            // 다음 이동할 후보 지점이 유효 한지 확인
            if (!isValid(ny, nx, boardSize) || board[ny][nx])
                continue;

            int newCost = lastCost + (i == dir ? STRAIGHT_COST : CORNER_COST);

            // 아직 후보 지점을 방문하지 않았거나, 앞서 구한 비용보다 더 적을 때
            if (dist[ny][nx][i] == -1 || dist[ny][nx][i] > newCost) {
                dist[ny][nx][i] = newCost;
                q.push({ny, nx, i});
            }
        }
    }


}


int main() {


    return 0;
}