#include<vector>


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
  public:
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin)
    {
        if (pre.size() > 0 && pre.size() == vin.size())
        {
            auto preLeftItr = pre.begin();
            auto preRightItr = pre.end() - 1;
            auto vinLeftItr = vin.begin();
            auto vinRightItr = vin.end() - 1;
            return constructCore(preLeftItr, preRightItr, vinLeftItr, vinRightItr);
        }
        else
        {
            return nullptr;
        }
    }

    TreeNode *constructCore(vector<int>::iterator preLeftItr, vector<int>::iterator preRightItr,
                            vector<int>::iterator vinLeftItr, vector<int>::iterator vinRightItr)
    {
        // 边界处理
        if (preLeftItr > preRightItr)
        {
            return nullptr;
        }

        // 正常处理
        TreeNode *new_node = new TreeNode(-1);
        new_node->val = *preLeftItr;
        new_node->left = nullptr;
        new_node->right = nullptr;

        if (new_node->val == *preRightItr)
        {
            return new_node;
        }

        //在中序中寻找改节点
        int locInVin = 0;
        while (*(vinLeftItr + locInVin) != new_node->val)
        {
            ++locInVin;
        }

        int leftLength = locInVin;
        int rightLength = vinRightItr - vinLeftItr - locInVin;
        vector<int>::iterator preLeftEndItr = vinLeftItr + locInVin;
        vector<int>::iterator rootItr = vinLeftItr + locInVin;

        if (leftLength > 0)
        {
            new_node->left = constructCore(preLeftItr + 1, preLeftEndItr, vinLeftItr, rootItr - 1);
        }
        if (rightLength > 0)
            new_node->right = constructCore(preLeftEndItr + 1, preRightItr, rootItr + 1, vinRightItr);

        return new_node;
    }
};
