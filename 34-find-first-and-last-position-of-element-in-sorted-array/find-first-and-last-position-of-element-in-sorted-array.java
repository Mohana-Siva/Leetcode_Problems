class Solution {
    public int binaryFirst(int[]nums, int target){
        int idx = -1;
        int left = 0;
        int right = nums.length - 1;
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[mid]>=target){
                right = mid-1;
            }else{
                left = mid+1;
            }
            if(nums[mid]==target) idx = mid;
        }
        return idx;
    }
        public int binarySecond(int[]nums, int target){
        int idx = -1;
        int left = 0;
        int right = nums.length - 1;
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[mid]<=target){
                left = mid+1;
            }else{
                right = mid-1;
            }
            if(nums[mid]==target) idx = mid;
        }
        return idx;
    }
    public int[] searchRange(int[] nums, int target) {
        int [] result = new int[2];
        result[0] = binaryFirst(nums,target);
        result[1] = binarySecond(nums,target);
        return result;
        

    }
}