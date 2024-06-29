#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;


int solution(vector<int> nums) {
    unordered_set<int> poketmon(nums.begin(), nums.end());
    
    /* 이렇게 초기화 하지말고 위에 처럼 해라
    for (int i : nums) {
        poketmon.insert(i);
    }
    */
    // set에 넣으면 자동적으로 중복은 사라진다.

    // 포켓몬을 뽑을 수와 종류의 수를 비교한다.
    // ex) 6마리가 있음 3마리 뽑을 수 있다. 종류가 3이면 최대 종류의 개수는 3
    // 2마리면 최대 종류 개수는 2
    // 종류가 5면 최대 종류를 3
    int n = nums.size() / 2; // 뽑을 수 있는 포켓몬의 숫
    int v = poketmon.size(); // 포켓몬의 종류
    
    return min(n, v);

    /* 결국 종류와 뽑을 수 이는 수 중 둘중에 작은 걸 반환하면 그게 최대로 다양하게 뽑을 수 있는 수임.
    if (v > n) {
        return  n;
    }
    else if (v < n) {
        return v;
    }
    else {
        return n;
    }
    */
    
}

int main() {

    vector<int> nums = {3,3,3,2,2,2};

    cout << solution(nums) << endl;

    return 0;
}