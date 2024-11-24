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
 //if we are given the binary tree we
 // we can use the level order traversal and we can keep track of the size for each level
 // at the end of the last node we can push that value in the result 
 

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
       //to store the result
       vector<int>result;

       // to perform level order traversal
       queue<TreeNode*>tracker;

        // root will always be the first element 
        if(root==NULL)
            return result;
        tracker.push(root);

        //int count = 1;

       while(!tracker.empty()) 
       {
            //get the first element
            int size = tracker.size();
            
            //now to traverse
            for(int i = 0;i<size;i++)
            {
                TreeNode* curr = tracker.front();
                tracker.pop();
                if(curr->left)
                {
                    tracker.push(curr->left);
                }
                if(curr->right)
                {
                    tracker.push(curr->right);
                }
                if(i == size-1)
                    result.push_back(curr->val);

            }    
       }

       return result;
    }
};
//Time complexity O(N)
//space complexity O(h)
