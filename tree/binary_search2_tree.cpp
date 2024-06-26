#include <iostream>
#include <vector>

using namespace std;

// 트리 - 이진 탐색 트리의 삽입, 검색 구현

// 먼저 클래스로 노드를 정의한다. 예전에는 구조체로 노드를 정의 했던거 같은데, 객체 생성하고 그런건 비슷하니까.
class Node {
    public: // 외부에서 값에 접근해야 하기 떄문에 public으로 열어뒀다
    int val; // 이 노드의 값
    Node *left, *right; // 이 노드의 왼쪽, 오른쪽 자식의 주소값

    // 생성자로 초기화 한다.
    Node(int key) : val(key), left(nullptr), right(nullptr) {}
}; // 이러면 노드의 구조는 만들어진것.

// 이진 탐색 트리 구축
class BST {
    private:
    Node* root; // 이진 탐색 트리의 루트 노드.

    Node* insertNode(Node* node, int key) { // 이 함수의 구조가 처음 Node객체가 생성되고 나면 다음 부턴 그 객체가 계속 root에 담기도록 되어 있음.
                                            // 그 밑에 있는 자식 노드들은 재귀함수 원리로 인해서 타고 타고 들어가서 자식 밑에 생기도록 함.
        if (!node) { // 만약 노드가 없다면?
            return new Node(key); // 새 노드를 만들어 주고 빠져나간다.
        }

        if (key < node->val) { // 현재 노드보다 값이 작으면
            node->left = insertNode(node->left, key); // 왼쪽 노드로 이동
        } else { // 현재 노드보다 값이 크면 
            node->right = insertNode(node->right, key); // 오른쪽 노드로 이동
        }

        return node;
    }

    bool searchNode(Node* node, int key) {
        if (!node) { // 찾는 키값이 없는 경우
            return false;
        }

        if (key == node->val) { // 찾은 경우
            return true;
        }

        // 3항 연산자로 return 처리
        // 조건문 ? true : false;
        return key < node->val ? searchNode(node->left, key) : searchNode(node->right, key);
        // 재귀함수 원리로 계속 자식 노드로 타고 타고 갈 수 있도록 만듬. 끝까지 타고 들어갔는데도 없으면 false를 반환하도록 함. 마지막 노드면 node가 null일 것이므로 끝난것을 의미.
    }

    public:
    BST() : root(nullptr) {}

    void insert(int key) {
        root = insertNode(root, key);
    }

    bool search(int key) {
        return searchNode(root, key);
    }
};

vector<bool> solution(vector<int> lst, vector<int> search_lst) {
    BST bst;

    // 노드 삽입
    for (int i : lst) {
        bst.insert(i);
    }
    

    vector<bool> result;
    // 값 검색
    for (int i : search_lst) {
        result.push_back(bst.search(i));
    }

    return result;
}


int main() {
    
    // vector<int> lst = {5,3,8,4,2,1,7,10};
    // vector<int> search_lst = {1,2,5,6};

    vector<int> lst = {1,3,5,7,9};
    vector<int> search_lst = {2,4,6,8,10};

    vector<bool> answer = solution(lst, search_lst);

    for (bool i : answer) {
        cout << i << " ";
    }


    return 0;
}

// Node에서의 Node *left와 여기 Node* root의 차이점은 무엇인가?
/*
    기능에는 차이점이 없지만 포인터를 여러개 선언할때 주의 해야한다.
    예를 들어,
    Node* root1, root2; 일때 root1은 Node에 대한 포인터로 선언 되지만 root2는 포인터가 아닌 Node객체로 선언된다.
    포인터를 여러개 선언할 때는 각각 해주는게 좋다고함.
    Node *left, *right; 처럼
*/