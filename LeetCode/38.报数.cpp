/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 报数
 */
class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string ans = countAndSay(n-1);
        int te = 1;
        string A;
        if(ans.size() <= 1) return ans+ans;
        ans += 'A';
        for(int i = 1 ; i < ans.size();i++)
        {
            if(ans[i-1] == ans[i]) te++;
            else A += to_string(te) + ans[i-1],te = 1;
        }
        return A;
    }
};
/*int main()
{
    cout<<A.countAndSay(5)<<endl;
}*/

