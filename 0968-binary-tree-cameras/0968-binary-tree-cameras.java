/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

/*
Approach 1: Dynamic Programming
Intuition

Let's try to cover every node, starting from the top of the tree and working down. Every node considered must be covered by a camera at that node or some neighbor.

Because cameras only care about local state, we can hope to leverage this fact for an efficient solution. Specifically, when deciding to place a camera at a node, we might have placed cameras to cover some subset of this node, its left child, and its right child already.

Algorithm

Let solve(node) be some information about how many cameras it takes to cover the subtree at this node in various states. There are essentially 3 states:

[State 0] Strict subtree: All the nodes below this node are covered, but not this node.
[State 1] Normal subtree: All the nodes below and including this node are covered, but there is no camera here.
[State 2] Placed camera: All the nodes below and including this node are covered, and there is a camera here (which may cover nodes above this node).
Once we frame the problem in this way, the answer falls out:

To cover a strict subtree, the children of this node must be in state 1.
To cover a normal subtree without placing a camera here, the children of this node must be in states 1 or 2, and at least one of those children must be in state 2.
To cover the subtree when placing a camera here, the children can be in any state.

*/
class Solution {
    public int minCameraCover(TreeNode root) {
        int[] ans = solve(root);
        return Math.min(ans[1], ans[2]);
    }

    // 0: Strict ST; All nodes below this are covered, but not this one
    // 1: Normal ST; All nodes below and incl this are covered - no camera
    // 2: Placed camera; All nodes below this are covered, plus camera here
    public int[] solve(TreeNode node) {
        if (node == null)
            return new int[]{0, 0, 99999};

        int[] L = solve(node.left);
        int[] R = solve(node.right);
        int mL12 = Math.min(L[1], L[2]);
        int mR12 = Math.min(R[1], R[2]);

        int d0 = L[1] + R[1];
        int d1 = Math.min(L[2] + mR12, R[2] + mL12);
        int d2 = 1 + Math.min(L[0], mL12) + Math.min(R[0], mR12);
        return new int[]{d0, d1, d2};
    }
}
