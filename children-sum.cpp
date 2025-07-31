#include "bits/stdc++.h"
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int childSum(TreeNode *root) {
  if (!root)
    return 0;

  int leftChild = 0;
  int rightChild = 0;

  if (root->left)
    leftChild += root->left->val;
  if (root->right)
    rightChild += root->right->val;

  if (leftChild + rightChild < root->val) {
    if (root->left)
      root->left->val = root->val;
    if (root->right)
      root->right->val = root->val;
  }

  int left = childSum(root->left);
  int right = childSum(root->right);

  root->val = max(root->val, left + right);

  return root->val;
}

void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main() {
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(5);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(2);
  root->right->left = new TreeNode(0);
  root->right->right = new TreeNode(8);
  root->left->right->left = new TreeNode(7);
  root->left->right->right = new TreeNode(4);

  cout << "Binary Tree before modification: ";
  inorderTraversal(root);
  cout << endl;

  // Call the changeTree function
  // to modify the binary tree
  childSum(root);

  // Print the inorder traversal
  // after modification
  cout << "Binary Tree after Children Sum Property: ";
  inorderTraversal(root);
  cout << endl;
}
