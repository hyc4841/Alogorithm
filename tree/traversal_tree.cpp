#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 트리 - 전위, 중위, 후위 순회 구현

// 현재 노드를 부모 노드로 생각한다.
// 전위 순회 : 부모 - 왼쪽 - 오른쪽. 
string preorder(vector<int> nodes, int idx) {
    if (idx < nodes.size()) { // 인덱스가 백터 nodes의 크기보다 같거나 커지면 if문을 거치지 않는다.
        // 부모 - 왼쪽 - 오른쪽 순서로 재귀 함수를 구축해준다. 이렇게 되면 시스템 스택에 의해 재귀함수가 차례로 실행됨.
        string ret = to_string(nodes[idx]) + " "; // 부모 노드
        ret += preorder(nodes, idx * 2 + 1); // 왼쪽 노드
        ret += preorder(nodes, idx * 2 + 2); // 오른쪽 노드
        
        return ret;
    }

    return "";
}

// 중위 순회 : 왼쪽 - 부모 - 오른쪽.
string inorder(const vector<int>& nodes, int idx) { // 백터 nodes는 참조로 전달한다. 또한 중간에 변경되면 안되기 때문에 const로 선언.
    if (idx < nodes.size()) {
        string ret = inorder(nodes, idx * 2 + 1); // 왼쪽 노드
        ret += to_string(nodes[idx]) + " "; // 부모 노드
        ret += inorder(nodes, idx * 2 * 2); // 오른쪽 노드

        return ret;
    }

    return "";
}

// 후위 순회 : 왼쪽 - 오른쪽 - 부모
string postorder(const vector<int>& nodes, int idx) {

    if (idx < nodes.size()) {
        string ret = postorder(nodes, idx * 2 + 1); // 왼쪽 노드
        ret += postorder(nodes, idx * 2 + 2);
        ret += to_string(nodes[idx]) + " ";

        return ret;
    }

    return "";
}

vector<string> solution(vector<int> nodes) {



}

int main() {



    return 0;
}

// 순회는 기본적으로 스택 연산 또는 큐 연산의 원리를 이용하면 쉽다.