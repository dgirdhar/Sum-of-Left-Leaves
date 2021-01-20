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
    int Sum(TreeNode *node, bool isLeft) {
        int sum = 0;
        
        if (node != nullptr) {
            if (node->left == nullptr && node->right == nullptr) {
                sum += isLeft ? node->val : 0;
            }
            else {
                sum += Sum(node->left, true);
                sum += Sum(node->right, false);            
            }
        }
        
        return sum;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        
        if (root != nullptr) {
            sum += Sum(root->left, true);
            sum += Sum(root->right, false);
        }
        
        return sum;
    }
};
