#include <iostream>
#include <vector>

using namespace std;

// 2차원 배열 이용해서 행렬의 곱셈 구현하기
vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {

    if (arr1[0].size() == arr2.size()) {
        vector<vector<int>> result(arr1.size(), vector<int>(arr2[0].size())); // 결과 행렬의 크기는 arr1의 행의 개수  * arr2의 열의 개수 로 결정된다. 

    // 행과 열의 길이가 맞아야 한다.
    // 2차원 백터 arr이 있다고 가정한다면 그냥 arr.size()를 하게 되면 arr[]의 개수가 나오게 된다.
    for (int i = 0; i < arr1.size(); i++) { // i는 arr1의 열의 개수
        for (int j = 0; j < arr2.size(); j++) { // j는 arr2의 열의 개수
            for (int k = 0; k < arr1[0].size(); k++) { // k는 arr1의 행의 개수
                // 실제로 곱셈 연산이 일어나는 곳
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    return result;
    }
    else {
        cout << "arr1의 행의 길이와 arr2의 열 길이가 맞지 않습니다." << endl;
    }

    
}

int main() {
    vector<vector<int>> arr1 = {
        {1, 4},
        {3, 2},
        {4, 1}};

    vector<vector<int>> arr2 = {
        {3, 3},
        {3, 3}};

    vector<vector<int>> answer =  solution(arr1, arr2);

    for (int i = 0; i < answer.size(); i++){
        cout << endl;
        for(int j = 0; j < answer[0].size(); j++) {
            cout << answer[i][j] << " ";
        }
    }

    return 0;
}