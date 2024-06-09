#include <iostream>
#include <stack>
#include <vector>

using namespace std;


int solution(vector<vector<int>> board, vector<int> moves) {
    
    stack<int> bucket;
    int answer = 0;

    // 1. moves안에 있는 요소들을 차례로 읽는다.
    for (int i = 0; i < moves.size(); i++) {
        // 2. i 번째 들어있는 moves의 요소와 board[][i-1]에 요소가 들어있는지 확인.
        for(int j = 0; j < board.size(); j++) { // while문으로 바꿔야하나...
            // 만약 해당 자리에 숫자가 있으면 스택에 넣는다.
            if (board[j][moves[i]-1] != 0) { // 0이 아니면 인형이 있는 거임

                if (!bucket.empty() && (board[j][moves[i]-1] == bucket.top())) { // 바구니가 비어있지 않고, 안에 들어있는 요소가 지금 넣으려는 board 요소와 같으면 
                    bucket.pop(); // 안에 있는 요소 빼주고
                    answer += 2; // 인형 2개 빼는 거니까 2씩 올려준다.
                    board[j][moves[i]-1] = 0; // 인형 빠진 자린 0으로 채워준다.
                    break;
                }
                else {
                    bucket.push(board[j][moves[i]-1]); // 해당 요소 스택에 넣어주고
                    board[j][moves[i]-1] = 0; // 인형이 빠진 자리는 없다는 표시인 0으로 채워준다.
                    break;
                }

            }
        }

    }

    return answer;
}

int main() {

    vector<vector<int>> board = {{0, 0, 0, 0, 0}, {0, 0, 1, 0, 3}, {0, 2, 5, 0, 1}, {4, 2, 4, 4, 2}, {3, 5, 1, 3, 1}};
    vector<int> moves = {1, 5, 3, 5, 1, 2, 1, 4};

    int answer = solution(board, moves);

    cout << answer << endl;


    return 0;
}