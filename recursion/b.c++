#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

Node* Bt(int val) {
    Node* node = new Node;
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void pre(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->val << " ";
    pre(root->left);
    pre(root->right);
}

void in(Node* root) {
    if (root == NULL) {
        return;
    }
    in(root->left);
    cout << root->val << " ";
    in(root->right);
}

void post(Node* root) {
    if (root == NULL) {
        return;
    }
    post(root->left);
    post(root->right);
    cout << root->val << " ";
}

int main() {
    Node* root = NULL;
    int val;
    cout << "Enter the root value: ";
    cin >> val;
    root = Bt(val);
    stack<Node*> s;
    s.push(root);
    while (!s.empty()) {
        Node* curr = s.top();
        s.pop();
        cout << "Enter the left child of " << curr->val << " (-1 if none): ";
        cin >> val;
        if (val != -1) {
            curr->left = Bt(val);
            s.push(curr->left);
        }
        cout << "Enter the right child of " << curr->val << " (-1 if none): ";
        cin >> val;
        if (val != -1) {
            curr->right = Bt(val);
            s.push(curr->right);
        }
    }
    cout << "Preorder traversal: ";
    pre(root);
    cout << endl;
    cout << "Inorder traversal: ";
    in(root);
    cout << endl;
    cout << "Postorder traversal: ";
    post(root);
    cout << endl;
    return 0;
}