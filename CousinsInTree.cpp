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
    bool isCousins(TreeNode* root, int x, int y) {
        //define queues
        queue<TreeNode*>child;

        child.push(root);

        TreeNode* x_parent = root;
        int x_level = 0;
        TreeNode* y_parent = root;
        int y_level = 0;
        int level = 0;
        while(!child.empty())
        {
            int size = child.size();
            for(int i =0; i < size;i++)
            {
                TreeNode* curr = child.front();
                child.pop();

                // child of this level will be parent for the next
                // add the child 
                if(curr->left)
                {
                    if(curr->left->val == x )
                    {
                        x_parent = curr;
                        x_level = level;
                    }
                    if(curr->left->val == y)
                    {
                        y_parent = curr;
                        y_level = level;
                    }
                    
                    child.push(curr->left);
                }
                if(curr->right)
                {
                    if(curr->right->val == x )
                    {
                        x_parent = curr;
                        x_level = level;
                    }
                    if(curr->right->val == y)
                    {
                        y_parent = curr;
                        y_level = level;
                    }
                    child.push(curr->right);
                }

            }
            level++;
        }

        if(x_parent != y_parent && x_level == y_level) return true;
        return false;
    }
};

//Time complexity O(N)
//Space complexity O(h)