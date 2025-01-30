#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* Bt(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return(newNode);
}

struct Node* pre(struct Node* temp) {
    if (temp != NULL) {
        cout << temp->val << " ";
        pre(temp->left);
        pre(temp->right);
    }
    return temp;
}

struct Node* in(struct Node* temp) {
    if (temp != NULL) {
        in(temp->left);
        cout << temp->val << " ";
        in(temp->right);
    }
    return temp;
}

struct Node* post(struct Node* temp) {
    if (temp != NULL) {
        post(temp->left);
        post(temp->right);
        cout << temp->val << " ";
    }
    return temp;
}

int maximumdepth(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    int lh = maximumdepth(root->left);
    int rh = maximumdepth(root->right);
    return 1 + max(lh, rh);
}

struct Node* bst(struct Node* root, int val) {
    if (root == NULL || root->val == val) {
        return root;
    }
    if (val < root->val) {
        return bst(root->left, val);
    } else {
        return bst(root->right, val);
    }
    return NULL;
}

struct Node*findlastright(struct Node*root){
    if(root->right== NULL){
     return root;
    }
    return findlastright(root->right);
}
struct Node* helper(struct Node* root) {
    if (root->left == NULL) {
        return root->right;
    } else if (root->right == NULL) {
        return root->left;
    }
    struct Node* rightchild=root->right;
    struct Node* lastRight = findlastright(root->left);
    lastRight->right = rightchild;
    return root->left;
}
struct  Node*Delete(struct Node*root,int key){
struct Node*curr=root;
 if(root==NULL){
    return NULL;
 }if(root->val==key){
    return helper(root);
 }
 while(root!=NULL){
    if(root->val > key){
    if(root->left!=NULL&& root->left->val==key){//if it is the root to be deleted than call the helper function
        root->left=helper(root->left);
        break;
    }else{
        root=root->left;
    }
 }else{
    if(root->right!=NULL&& root->right->val==key){
        root->right=helper(root->right);
        break;
    }else{
        root=root->right;
    }
 }
}
return curr;
}
int main() {
    int val, choice;
    struct Node* root = NULL;
    struct Node* result = NULL;
    stack<Node*> st; // move the declaration of the stack variable outside of the switch statement
    while (true) {
        cout << "1. Create binary tree" << endl;
        cout << "2. Find maximum depth" << endl;
        cout << "3. Search for element in binary search tree" << endl;
        cout << "4. Preorder traversal" << endl;
        cout << "5. Inorder traversal" << endl;
        cout << "6. Postorder traversal" << endl;
        cout << "7. Delete an element from the binary search tree" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter the value of the root: ";
                cin >> val;
                root = Bt(val);
                st.push(root);
                while (!st.empty()) {
                    struct Node* temp = st.top();
                    st.pop();
                    cout << "Enter the left child of the node " << temp->val << " or (-1) for NULL: ";
                    cin >> val;
                    if (val != -1) {
                        temp->left = Bt(val);
                        st.push(temp->left);
                    }
                    cout << "Enter the right child of the node " << temp->val << " or (-1) for NULL: ";
                    cin >> val;
                    if (val != -1) {
                        temp->right = Bt(val);
                        st.push(temp->right);
                    }
                }
                break;
            case 2:
                cout << "Height of the tree is: " << maximumdepth(root) << endl;
                break;
            case 3:
                cout << "Enter the element to be searched in the binary search tree: ";
                cin >> val;
                result = bst(root, val);
                if (result == NULL) {
                    cout << "Element not in the tree" << endl;
                } else {
                    cout << "Element found in the binary search tree" << endl;
                }
                break;
            case 4:
                cout << "Preorder traversal: ";
                pre(root);
                cout << endl;
                break;
            case 5:
                cout << "Inorder traversal: ";
                in(root);
                cout << endl;
                break;
            case 6:
                cout << "Postorder traversal: ";
                post(root);
                cout << endl;
                break;
            case 7:
                cout << "Enter the element to be deleted from the binary search tree: ";
                cin >> val;
                root = Delete(root, val);
                break;
            case 8:
                exit(0);
            default:
                cout << "Invalid choice" << endl;
        }
    }
}