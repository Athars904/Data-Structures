#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to print the tree nodes in pre-order traversal
void preorder(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// Function to print the tree nodes in post-order traversal
void postorder(TreeNode* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}
void inorder(TreeNode *root)
{
    inorder(root->left);
    cout << root->val<<" ";
    inorder(root->right);
}

int main() {
    // Creating the tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Printing the tree in pre-order
    cout << "Pre-order traversal: ";
    preorder(root);
    cout << endl;

    // Printing the tree in post-order
    cout << "Post-order traversal: ";
    postorder(root);
    cout << endl;
    cout << " in order : ";
    inorder(root);

    return 0;
}
