#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


class Node {
    public:
    int val;
    Node *left, *right;

    Node(int key) : val(key), left(nullptr), right(nullptr) {}
};

class BST {
    private:
    Node* root;

    Node* insertNode(Node* node, int key) {
        if (!node) {
            return new Node(key);
        }

        if (key < node->val) {
            node->left = insertNode(node->left, key);
        }
        else {
            node->right = insertNode(node->right, key);
        }
        return node;
    }

    public:
    BST() : root(nullptr) {}

    void insert(int key) {
        root = insertNode(root, key);
    }
};

bool compare(vector<int> a, vector<int> b) {
    // vector[1]이 y 좌표임
    if (a[1] == b[1]) { // y좌표가 큰 순서대로
        return a[0] < b[0]; // x 좌표가 작은 순서대로.
    }    
    return a[1] > b[1];
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<int> tree;
    

    // 1. 트리 형성하기 전에 y좌표 값이 높은 기준으로 정렬한다.
    sort(nodeinfo.begin(), nodeinfo.end(), compare);

    for (int i = 0; i < nodeinfo.size(); i++) { // y좌표를 기준으로 정렬된 2차원 벡터를 순회 할거임.
        
    }

}


int main() {

    vector<vector<int>> nodeinfo = {{5, 3}, {11, 5}, {13, 3}, {3, 5}, {6, 1}, {1, 3}, {8, 6}, {7, 2}, {2, 2}};

    return 0;
}