#include <iostream>
#include <vector>

using namespace std;

// 해시 : 두개의 수로 특정 값 만들기 문제
bool solution(vector<int> arr, int target) {
    // x + k = target인 x, k가 arr에 있으면 true를, 없으면 false를 내보낸다.
    // target - x = k를 해서 k가 arr의 원소면 true를 반환한다.

    vector<int> hash_table(target, 0); // target의 크기만큼 생성.

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < target) { // 1. arr원소중 target보다 작은 원소만 넣는다.
            hash_table[arr[i]] = 1; // 단순히 1을 넣어서 arr의 원소가 있다는 것을 표시. 인덱스 = arr[i]의 값
        }
    }

    for (int j = 0; j < arr.size(); j++) {
        // 해시 테이블이 완성 되면 이제 arr을 순회하면서 target - x = k의 값이 hash_table안에 존재하는지 확인하면 된다.
        int tmp = target - arr[j];

        if (arr[j] == tmp) { //target - arr[j]와 arr[j]가 같은 경우는 뺀다. (중복 원소는 없으므로)
            continue;
        }
        if (tmp < 0) { // target - arr[j]가 음수인 경우는 뺀다.
            continue;
        }
        if (hash_table[target - arr[j]] == 1) {
            return true;
        }
    }


    // for문을 다 돌았는데도 없으면 false를 반환
    return false;
}

// 큐 부분 아직 안함.
// 주식 가격 그거 왜그런지 다시 생각해보기.


int main() {

    vector<int> arr = {2,3,5,9};
    int target = 10;

    bool answer = solution(arr, target);

    if (answer == 1) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

    return 0;
}