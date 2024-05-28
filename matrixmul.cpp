#include <iostream>
#include <vector>

using namespace std;

// 2차원 배열 이용해서 행렬의 곱셈 구현하기
vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {

    vector<vector<int>> result(arr1.size(), vector<int>(arr2[0].size())); // 결과 행렬의 크기는 arr1의 행의 개수  * arr2의 열의 개수 로 결정된다. 

    // 행과 열의 길이가 맞아야 한다.
    // 2차원 백터 arr이 있다고 가정한다면 그냥 arr.size()를 하게 되면 arr[]의 개수가 나오게 된다.
    for (int i = 0; i < ) {
        
    }



}

int main() {

    vector<vector<int>> arr = {{1, 2, 3, 5},
                               {4, 5, 6},
                               {7, 8, 9}};
    cout << arr[].size() << endl;
    // 

    return 0;
}