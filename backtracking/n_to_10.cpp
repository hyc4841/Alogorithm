#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> results;
vector<int> selected_nums;

void backtrack(int N, int sum, int start) {
    // 합이 10이면 끝남
    if (sum == 10) {
        results.push_back(selected_nums);
        return;
    }

    // 아직 합이 10이 아니면 다음 숫자 넣기
    for (int i = start; i <= N; i++) {
        // 만약 기존 sum 하고 i하고 합했는데 10 넘어가면 건너뜀.
        if (sum + i <=10) {
            selected_nums.push_back(i);
            backtrack(N, sum + i, i + 1); // sum에 i를 더해주고 다음 숫자로 진행하기 위해 i + 1 해줌
            selected_nums.pop_back(); // 넣었던 숫자 다시 빼주기. 이러면 백터 재활용 가능
            // 순서는 i = 1일때 가능한 조합 모두 넣고, 다음 i = 2일때 가능한 조합 넣고, 다음 3으로 넘어감.
        }
    }

}


vector<vector<int>> solution(int N) {

    backtrack(N, 0, 1);

    return results;

}

int main() {


    return 0;
}