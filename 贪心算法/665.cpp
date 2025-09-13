// 665. 非递减数列
给你一个长度为 n 的整数数组 nums ，请你判断在 最多 改变 1 个元素的情况下，该数组能否变成一个非递减数列。
我们是这样定义一个非递减数列的： 对于数组中任意的 i (0 <= i <= n-2)，总满足 nums[i] <= nums[i + 1]。
/*******************************/
示例 1:

输入: nums = [4,2,3]
输出: true
解释: 你可以通过把第一个 4 变成 1 来使得它成为一个非递减数列。
示例 2:

输入: nums = [4,2,1]
输出: false
解释: 你不能在只改变一个元素的情况下将其变为非递减数列。


题解：
    可以看出，本题目给出了两个解法 但实际上是一种。首先看题目，要求罪过改变一个元素的情况下，使其满足题目的要求。
	我们的思路其实很清晰：遍历，如果没有违规那就是true 如果大于等于两次违规 那肯定为false。关键就在一次违规即
	如果在遍历过程中只出现一次nums[i]>nums[i+1] 可否通过修改一个元素使其合规 实际上是不确定的 这也是题目的关键之处：
	那么我们思考如果nums[i]>nums[i+1] 考虑的就只有两个方法 把nums[i]变小同时大于nums[i-1]
	把nums[i+1]变大 同时小于nums[i+2] 如果这两者都行不通 那就为false
	
	解法一就是在第一次出现违规的时候进行上面的修改 并继续判断是否违规 其值得关注的点在于 我们要把nums[i+1]变大 同时小于nums[i+2] 那就是找到nums[i+1]最小的
	最大值 就是nums[i] 但这里也要注意是否能够修改的条件
	
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        for(int i = 0;i<nums.size()-1;++i){
            if(nums[i]>nums[i+1]){
                count++;
            // 当count = 1 的时候进行修改 看是否再次出现违规 
            if(count==1)
            {
                if (i > 0 && nums[i-1] > nums[i+1])
                    nums[i+1]=nums[i];
                else
                    nums[i] = nums[i+1];
            }
            }
        }
     return count<=1;
    }
};


bool checkPossibility(vector<int>& nums) {
    int count = 0;
    for (int i = 0; i < nums.size() - 1; ++i) {
        if (nums[i] > nums[i+1]) {
            count++;
            if (count > 1) {
                return false;
            }

            // 在这里，我们来判断是否能修复
            // 方案一：修改 nums[i]，把它变小
            bool can_fix_i = false;
            if (i == 0 || nums[i-1] <= nums[i+1]) {
                can_fix_i = true;
            }

            // 方案二：修改 nums[i+1]，把它变大
            bool can_fix_i_plus_1 = false;
            if (i + 2 >= nums.size() || nums[i] <= nums[i+2]) {
                can_fix_i_plus_1 = true;
            }
            
            // 如果两种方案都行不通，那我们就无法修复
            if (!can_fix_i && !can_fix_i_plus_1) {
                return false;
            }
        }
    }
    return true;
}