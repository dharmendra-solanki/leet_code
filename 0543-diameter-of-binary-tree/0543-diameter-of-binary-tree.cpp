/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int diameter = 0;
    int calculateDia(TreeNode* root){
        if(root == NULL) return 0;

        int ll = calculateDia(root->left);
        int rl = calculateDia(root->right);

        diameter = max(diameter , ll+rl);
        return 1 + max(ll , rl);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        calculateDia(root);
        return diameter;
    }
};