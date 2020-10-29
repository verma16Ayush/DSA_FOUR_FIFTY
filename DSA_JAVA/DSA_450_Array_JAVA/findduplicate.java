class Solution {
    public int findDuplicate(int[] nums) {
        int n=nums.length;
        int k=0;
        boolean arr[]=new boolean[n];
        for(int i=0;i<n;++i)
        {
            
           if(!arr[nums[i]])
           {
               arr[nums[i]]=true;
           }
            else
                return nums[i];
            
        }
        return nums[n-1];
       
        
    }
}