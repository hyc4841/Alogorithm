#include <vector>
#include <iostream>

using namespace std;

// 트리 - 이진 탐색 트리의 삽입, 검색 구현

// 1. 검색하려는 값이 현재 노드 값과 같으면 반환하고 종료
// 2. 검색하려는 값이 현재 노드 값보다 작으면, 왼쪽으로 
// 3. 검색하려는 값이 현재 노드 값보다 크면, 오른쪽으로

// 노드 정의
class Node {
    public :
    int val; // 이 노드의 값
    Node *left, *right; // 이 노트의 왼쪽, 오른쪽 자식 노드의 주소값

    // 생성자. key값은 필수로 들어와야함. nullptr은 포인터 변수에 null을 넣는 대신 포인터 변수에 값이 없다는 뜻으로 넣는 것임.
    // 해당 매개변수로 값이 들어오면
    Node(int key) : val(key), left(nullptr), right(nullptr) {}
};

// 이진 탐색트리 정의
class BST {
    private:
    Node* root;

    // 노드 삽입 함수 정의
    Node* insertNode(Node* node, int key) { // 이진 탐색 트리의 정의에 따라 부모 노드 보다 작으면 왼쪽, 크면 오른쪽
        if (!node) { // 노드가 없으면 새로 만든다.
            return new Node(key);
        }

        if (key < node->val) {
            node->left = insertNode(node->left, key);
        } else {
            node->right = insertNode(node->right, key);
        }
        return node;
    }

    // 노드 검색 함수 정의
    bool searchNode(Node* node, int key) {
        if (!node) {
            return false;
        }
        if (key == node->val) {
            return true;
        }

        return key < node->val ?
                searchNode(node->left, key) :
                searchNode(node->right, key);
    }
    public:
    BST() : root(nullptr) {} // 생성자

    void insert(int key) {
        root = insertNode(root, key);
    }

    bool search(int key) {
        return searchNode(root, key);
    }
};

vector<bool> solution(vector<int> lst, vector<int> search_lst){
    BST bst;

    // 이진 탐색 트리에 노드 삽입
    for (int key : lst) {
        bst.insert(key);
    }

    vector<bool> result;

    for (int search_val : search_lst) {
        result.push_back(bst.search(search_val));
    }

    return result;
}

int main() {


    return 0;
}