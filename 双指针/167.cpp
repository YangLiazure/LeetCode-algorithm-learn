// 167.两数之和 

根据题目，我们需要找到和等于target的两个数字，并且题目已经排好序，此时用双指针法就是最简单并且易于理解的方法：
  两个指针分别位于数组开头和数组末尾，根据一定的条件移动两个指针：
  如果指针之和大于target 就向左移动指针2；如果指针之和小于target 就右移指针1 （本题和水桶盛水问题很接近）
  如果等于就直接返回 
  因为在找到目标数组之前，无论如何我们都会移动其中一个指针 所以我们一定可以找到目标答案

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int index1 = 0;
        int index2 = numbers.size()-1;
        vector<int>result;
        while(index1<index2)
        {
            if(numbers[index1]+numbers[index2]<target)
                ++index1;
            else if(numbers[index1]+numbers[index2]>target)
                --index2;
            else{ 
                result.push_back(index1+1);
                result.push_back(index2+1);
                break;
            }   
        }
        return result;
    }
};

