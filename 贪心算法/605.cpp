//605 
假设有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花不能种植在相邻的地块上，它们会争夺水源，两者都会死去。

给你一个整数数组 flowerbed 表示花坛，由若干 0 和 1 组成，其中 0 表示没种植花，1 表示种植了花。另有一个数 n ，
能否在不打破种植规则的情况下种入 n 朵花？能则返回 true ，不能则返回 false 。


输入：flowerbed = [1,0,0,0,1], n = 2
输出：false


输入：flowerbed = [1,0,0,0,1], n = 1
输出：true



class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (int i = 0; i < flowerbed.size(); i++) {
            if (n == 0) {
                return true;
            }
            if (flowerbed[i] == 0) {
                // 检查左右是否为空
                bool leftEmpty = (i == 0 || flowerbed[i-1] == 0);
                bool rightEmpty = (i == flowerbed.size() - 1 || flowerbed[i+1] == 0);
                
                if (leftEmpty && rightEmpty) {
                    n--;
                    i++; // 种了花之后，下一个位置不能种，可以多跳一步
                }
            }
        }
        return n <= 0;
    }
};

// 该题目很简单 实际上只需要找到能够中花的条件即可 即该位置的左右都为 0 （一般情况） 如果左右都为空就能够种花