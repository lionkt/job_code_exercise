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

// 1.采用迭代器的方案
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
        vector<int>::iterator preLeftEndItr = preLeftItr + leftLength;
        vector<int>::iterator rootItr = vinLeftItr + leftLength;

        if (leftLength > 0)
        {
            new_node->left = constructCore(preLeftItr + 1, preLeftEndItr, vinLeftItr, rootItr - 1);
        }
        if (rightLength > 0)
            new_node->right = constructCore(preLeftEndItr + 1, preRightItr, rootItr + 1, vinRightItr);

        return new_node;
    }
};



// 2.采用指针的方案
class Solution
{
  public:
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin)
    {
        if (pre.size() > 0 && pre.size() == vin.size())
        {
            // 因为vector的存储是连续的
            int * PreLeftPtr = &pre[0];
            int * PreRightPtr = &pre[pre.size()-1];
            int * VinLeftPtr = &vin[0];
            int * VinRightPtr = &vin[vin.size()-1];
            return constructCore(PreLeftPtr, PreRightPtr, VinLeftPtr, VinRightPtr);
        }
        else
        {
            return nullptr;
        }
    }

    TreeNode *constructCore(int * preLeftPtr, int * preRightPtr,
                            int * vinLeftPtr, int * vinRightPtr)
    {
        // 边界处理
        // if (preLeftPtr > preRightPtr)
        // {
        //     return nullptr;
        // }

        // 正常处理
        TreeNode *new_node = new TreeNode(*preLeftPtr);
        new_node->left = nullptr;
        new_node->right = nullptr;

        if (new_node->val == *preRightPtr){
            return new_node;
        }

        //在中序中寻找改节点
        int locInVin = 0;
        while (*(vinLeftPtr + locInVin) != new_node->val){
            ++locInVin;
        }

        int leftLength = locInVin;
        int rightLength = vinRightPtr - vinLeftPtr - locInVin;
        int * preLeftEndPtr = preLeftPtr + leftLength;
        int * rootPtr = vinLeftPtr + locInVin;

        if (leftLength > 0)
        {
            new_node->left = constructCore(preLeftPtr + 1, preLeftEndPtr, vinLeftPtr, rootPtr - 1);
        }
        if (rightLength > 0)
            new_node->right = constructCore(preLeftEndPtr + 1, preRightPtr, rootPtr + 1, vinRightPtr);

        return new_node;
    }
};