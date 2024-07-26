#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int>> queenPos;

int queenNum;
long long successCount = 0;
int queenCount = 0;

bool isValid(int row, int col) {
    // 조건1 : 같은 열에 있으면 안됨
    // 조건2 : 같은 행에 있으면 안됨
    // 조건3 : 대각선에 있으면 안됨
    for (int i = 0; i < queenNum; i++) {
        if (queenPos[row][i] == true || queenPos[i][col] == true) {
            return false;
        }
    }

    
    // 하단 대각 검증
    if (row - col < 0) {
        for (int i = 0; i < queenNum - (col - row); i++) {
            if (queenPos[i][(col-row) + i] == true)  
                return false;
        }
    }
    else if (row - col > 0) {
        for (int i = 0; i < queenNum - (row - col); i++) {
            if (queenPos[(row-col) + i][i] == true)
                return false;
        }
    }
    else if (row == col) {
        for (int i = 0; i < queenNum; i++) {
            if (queenPos[i][i] == true)
                return false;
        }
    }

    int tmp = row + col;
    if (row + col > queenNum - 1) {
        for (int i = 0; i < queenNum - ((row + col) - (queenNum - 1)); i++) {
            if (queenPos[queenNum - 1 - i][(row + col) + 1 - queenNum + i] == true)
                return false;
        }
    }
    else if (row + col < queenNum - 1) {
        for (int i = 0; i < row + col + 1; i++) {
            if (queenPos[(row + col) - i][i] == true)
                return false;
        }
    }
    else if (row + col == queenNum - 1) {
        for (int i = 0; i < queenNum; i++) {
            if(queenPos[queenNum - 1 - i][i] == true)
                return false;
        }
    }

    return true;
}

void solve() {
    // 1. (0, 0)부터 시작. 해당 위치에 퀸을 놓을 수 있는지 검증
    // 2-1. 놓는 것이 가능하면 해당 위치에 퀸이 있다는 표시를 하고, 체스판 위에 퀸의 숫자를 표시할 count를 +1 시킴
    // 2-2. 불가능하면 해당 위치는 아무것도 하지 않고 (0, 1)로 넘어감.
    // 3. 체스판 위에 n개의 퀸이 문제 없이 모두 올라가면 성공 카운트를 +1 시키고 다음 위치로 이동한다.

    // 0, 0 부터 시작
    for (int row = 0; row < queenNum; row++) {
        for (int col = 0; col < queenNum; col++) {


            if (isValid(row, col)) { 
                queenPos[row][col] = true; // 해당 위치에 퀸이 있다는 것을 표시
                queenCount++; // 체스판 위에 퀸이 하나 올라갔다는 것을 표시
                if (queenCount == queenNum) { // 퀸이 모두 체스판 위에 올라가면 성공 카운터를 하나 올리고 다음 위치로 이동한다.
                    successCount++;
                    queenPos[row][col] = false; // 다시 원상 복구
                    queenCount--; // 체스판 위 퀸의 개수도 다시 복구해준다.
                    continue;
                }
                solve(); // 다음 퀸 놓으러 감
                queenPos[row][col] = false;
                queenCount--;
            }
        }
    }


}

long long solution(int n) { // 퀸들이 서로의 경로에 겹치지 않게 세울 수 있는 경우의 수

    vector<int> v(n, false);
    vector<vector<int>> queenPosTmp(n, v); // n * n 체스판 초기화
    queenPos = queenPosTmp;
    queenNum = n;

    solve();

    return successCount;
}


int main() {
    int n = 4;

    cout << solution(n) << endl;

    return 0;
}