class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right)
        {
            int mid = (left + right) / 2;
            int mv = nums[mid];

            if(mv == target)
                return mid;
            
            if(mv < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return -1;
    }
};