#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int val;
    struct TreeNode*left;
    struct TreeNode*right;
    TreeNode(int x):left{NULL},right{NULL},val(x){};
};
class Solution{
public:
vector<vector<int>>main(TreeNode*root ){
vector<int>result;
vector<int>postorder;
stack<TreeNode*>st;
st.push(root);
while (!st.empty()) {
        auto it = st.top();
        st.pop();
        if (it == NULL) continue;
        result.push_back(it->val);
        st.push(it->right);
        st.push(it->left);
    }
   vector<vector<int>>res;
   res.push_back(result);
   return res;
}
int maximumdepth(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int lh = maximumdepth(root->left);
    int rh = maximumdepth(root->right);
    return 1 + max(lh, rh);
}
bool isbalanced(TreeNode*root){
  return dfsheight(root)!=-1;
}
int dfsheight(TreeNode*root){
    if(root==NULL)return -1;
    int leftheight=dfsheight(root->left);
    int rightheight=dfsheight(root->right);
    if(leftheight==-1||rightheight==-1)return -1;
    if(abs(leftheight-rightheight>-1))return -1;
    return 1+max(leftheight,rightheight);
}
TreeNode* find_node(TreeNode* root, int val) {
    if (root == NULL) {
        return NULL;
    }
    if (root->val == val) {
        return root;
    }
    TreeNode* left_node = find_node(root->left, val);
    if (left_node != NULL) {
        return left_node;
    }
    TreeNode* right_node = find_node(root->right, val);
    if (right_node != NULL) {
        return right_node;
    }
    return NULL;
}

void display(TreeNode*root){
    vector<vector<int>>res=main(root);
    for(auto it :res){
        for(auto val :it ){
          cout<< val <<" ";
        }
    }
}


};
int main(){
TreeNode* root = new TreeNode(10);
 Solution s;
    int val;
    while (true) {
        cout << "Enter the operation you want to perform:" << endl;
        cout << "1. Insert a node" << endl;
        cout << "2. Insert a node on the left" << endl;
        cout << "3. Insert a node on the right" << endl;
        cout << "4. Display the tree" << endl;
        cout << "5. Exit" << endl;
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> val;
                if (root == NULL) {
                    root = new TreeNode(val);
                } else {
                    TreeNode* curr = root;
                    while (true) {
                        cout << "Insert " << val << " to the left or right of " << curr->val << "? (l/r): ";
                        char dir;
                        cin >> dir;
                        if (dir == 'l') {
                            if (curr->left == NULL) {
                                curr->left = new TreeNode(val);
                                break;
                            } else {
                                curr = curr->left;
                            }
                        } else if (dir == 'r') {
                            if (curr->right == NULL) {
                                curr->right = new TreeNode(val);
                                break;
                            } else {
                                curr = curr->right;
                            }
                        } else {
                            cout << "Invalid direction. Please enter 'l' or 'r'." << endl;
                        }
                    }
                }
                break;
            case 2:
           
                cout << "Enter the value to insert on the left: ";
                cin >> val;
                if (root == NULL) {
                    root = new TreeNode(val);
                } else {
                    cout << "Enter the value of the node to insert on the left: ";
                    int node_val;
                    cin >> node_val;
                    TreeNode* curr = s.find_node(root, node_val);
                    if (curr == NULL) {
                        cout << "Node not found." << endl;
                    } else {
                        if (curr->left == NULL) {
                            curr->left = new TreeNode(val);
                        } else {
                            cout << "Node already has a left child." << endl;
                        }
                    }
                }
                break;
            case 3:
            
                cout << "Enter the value to insert on the right: ";
                cin >> val;
                if (root == NULL) {
                    root = new TreeNode(val);
                } else {
                    cout << "Enter the value of the node to insert on the right: ";
                    int node_val;
                    cin >> node_val;
                    TreeNode* curr = s.find_node(root, node_val);
                    if (curr == NULL) {
                        cout << "Node not found." << endl;
                    } else {
                        if (curr->right == NULL) {
                            curr->right = new TreeNode(val);
                        } else {
                            cout << "Node already has a right child." << endl;
                        }
                    }
                }
                break;
            case 4:
                
                s.display(root);
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid operation. Please enter a valid operation." << endl;
                break;
        }
    }
}
