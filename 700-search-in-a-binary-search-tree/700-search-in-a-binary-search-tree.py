# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def searchBST(self, root, val):
        """
        :type root: TreeNode
        :type val: int
        :rtype: TreeNode
        """
        # Base case
        if not root:
            return None
        # Normal cases
        if (root.val == val):
            return root
        elif (root.val > val):
            return self.searchBST(root.left, val)
        else:
            return self.searchBST(root.right, val)