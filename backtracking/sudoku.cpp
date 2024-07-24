#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board;

bool isValid(int row, int col, int num) {
    // 조건 1. 해당 열에 같은 숫자가 있는지 확인
    // 조건 2. 해당 행에 같은 숫자가 있는지 확인
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }

    // 조건 3. 해당 구역 (3 * 3)에 같은 숫자가 있는지 확인
    int row_re = row - (row % 3);
    int col_re = col - (col % 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[row_re + i][col_re + j] == num) {
                return false;
            }
        }
    }

    return true;
}

vector<int> find_blank() {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == 0) {
                return {row, col};
            }
        }
    }

    return {-1, -1};
}

void solve() {
    // 1. 먼저 빈칸을 찾는다.
    vector<int> blank = find_blank();
    int row = blank[0];
    int col = blank[1];
    if (row == -1) return; // 빈칸이 없으면 종료

    for (int i = 1; i <= 9; i++) {
        if (isValid(row, col, i)) {
            board[row][col] == i; // 빈칸 채우기
            solve(); // 다음 빈칸 채우러 출발
            // 위에 solve()함수 돌고 나왔는데 다 채워진 상태면 아래 코드 실행시키면 안되니까
            vector<int> aa = find_blank();
            if (aa[0] == -1) return;

            board[row][col] == 0; // 되돌리기
        }
    }
}

vector<vector<int>> solution(vector<vector<int>> input_board) {
    board = input_board;
    solve();
    return board;
}

int main() {

    vector<vector<int>> input_board = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
        };

    vector<vector<int>> answer = solution(input_board);

    for (int i = 0; i < answer.size(); i++) {
        for (int j = 0; j < answer.size(); j++) {
            cout << answer[i][j] << ", ";
        }
        cout << endl;
    }



    
}