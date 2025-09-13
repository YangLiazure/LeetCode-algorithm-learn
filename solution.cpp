class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int>candies(n,1);
        for(int i = 0;i<n-1;++i)
        {
            if(ratings[i]<ratings[i+1])
            {
                candies[i+1] = candies [i]+1;
            }
        }
        for(int i = n-1;i>0;--i)
        {
            if(ratings[i]<ratings[i-1])
            {
                candies[i-1] = max(candies[i]+1,candies[i-1]);
            }
        }
        return accumulate(candies.begin(),candies.end(),0);
    }
};

// 采用贪心算法 这里的贪心策略是分别比较一侧的糖果数量 每次遍历只更新相邻一侧的大小关系 
// 接下来会详细介绍其思想