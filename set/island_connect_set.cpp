#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

// 그리디 + 상호배타적 집합. 사이클 감지로 푸는 문제

int solution(int n, vector<vector<int>> costs) {
    // 최소 비용이 되도록 하는 방법
    // 비용이 작은것 부터 큰 순서대로 나열한다.
    // 나열한 배열에서 다리를 하나씩 선택한다.
    // 한 다리를 선택할 때 마다 set에 노드들을 집어 넣는다.
    // 노드의 숫자와 set안에 있는 요소들의 숫자를 비교해서 똑같으면 끝.
    unordered_set<int> nodes;
    int cost = 0;

    // 1. cost를 제일 낮은 순서대로 정렬한다.
    sort(costs.begin(), costs.end(), compare);
    
    for (int i = 0; i < costs.size(); i++) {
        nodes.insert(costs[i][0]);
        nodes.insert(costs[i][1]);
        cost += costs[i][2];
        if (nodes.size() == n) {
            break;
        }
    }

    return cost;
}

int main() {

    vector<vector<int>> costs = {{0,1,1}, {0,2,2}, {1,2,5}, {1,3,1}, {0,1,8}};
    int n = 4;

    cout << solution(n, costs) << endl;

    return 0;
}