class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int g_size = g.size(), s_size = s.size();
        int g_i = 0 , s_i = 0;
        while(g_i<g_size && s_i<s_size)
        {
            if(g[g_i]<=s[s_i])  //遍历饼干 如果饼干能满足孩子 ++g_i  并换下一个孩子 否则看下一个饼干
            {
                ++g_i;
            }
            ++s_i;// 相当于遍历饼干
        }
        return g_i;    //返回的是被满足孩子的数目
    }
};