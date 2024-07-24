#include <iostream>
#include <vector>


using namespace std;

int max_depth;
vector<bool> visited;
vector<vector<int>> dungeon_copy;

bool isValid(int k, vector<int> dungeon) {
    // 조건 : 현재 피로도가 던전 입장 최소 피로도 보다 크거나 같아야함.
    if (k < dungeon[0]) return false;

    return true;
}

void solve(int cur_k, int depth) {
    max_depth = max(max_depth, depth);
    
    for (int i = 0; i < visited.size(); i++) {

        if (!visited[i] && isValid(cur_k, dungeon_copy[i])) { // 아직 던전을 방문하지 않았고, 유효성 검사 통과하면
            visited[i] = true;
            solve(cur_k - dungeon_copy[i][1], depth + 1);
            visited[i] = false; // 백트레킹을 위해서 다시 방문처리 풀기
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    // 던전 최대 방문 횟수 구하기
    visited.resize(dungeons.size(), false); // 방문 초기화
    dungeon_copy = dungeons;
    solve(k, 0);
    return max_depth;
}

int main() {
    vector<vector<int>> dungeons = {{80, 20}, {50, 40}, {30, 10}};
    int k = 80;
    cout << solution(k, dungeons) << endl;
    
    return 0;
}