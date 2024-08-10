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
    bool solve(TreeNode* root1, TreeNode* root2)
    {
        if(!root1 && !root2) return true;
        if((root1 && !root2) || (!root1 && root2)) return false;

        bool left = solve(root1->left, root2->right);
        bool right = solve(root1->right, root2->left);

        if((root1->val == root2->val) && (left == true && right == true))
            return true;
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        if(root->left == NULL && root->right == NULL) return true;

        return (solve(root->left, root->right) ? true : false);
    }
};