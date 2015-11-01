/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // 0 1 2 3 4
    //     2
    //   0   3
    TreeNode* constBinary(vector<int> nums, int lb, int rb){
        if(lb > rb) return NULL;
        int mid = (rb - lb) % 2 == 0 ? lb + (rb - lb) / 2 : lb + (rb - lb) / 2 + 1;
        TreeNode* root = new TreeNode(nums[mid]);
        if(lb < rb){
            root->left = constBinary(nums, lb, mid - 1);
            root->right = constBinary(nums, mid + 1, rb);
        }
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return constBinary(nums, 0, nums.size() - 1);
    }
};
