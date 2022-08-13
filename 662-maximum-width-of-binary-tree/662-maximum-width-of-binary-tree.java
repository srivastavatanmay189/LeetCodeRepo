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
class Solution {
    public int widthOfBinaryTree(TreeNode root) {
        
        Queue<TreeNode> q=new LinkedList<>();
        Deque<Integer> i=new LinkedList<>();
        
        q.add(root);
        i.add(0);
        int max=1;
      while(!q.isEmpty())
      {
          int s=q.size();
          
          while(s-->0)
          {
              TreeNode p=q.poll();
              int index=i.removeFirst();
              if(p.left!=null)
              {
                  q.add(p.left);
                  i.add(index*2+1);
              }
              if(p.right!=null)
              {
                  q.add(p.right);
                  i.add(index*2+2);
              }
          }
          if(i.size()>=2)
          {
          int a=i.getFirst();
          int b=i.getLast();
          max=Math.max(max,b-a+1);
          }
          
      }
        return max;
    }
}