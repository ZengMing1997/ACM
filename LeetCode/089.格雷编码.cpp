/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */
class Solution {
public:
    vector<int>ans;
    void dfs(string te,int n,int flag) {
        if(te.size() == n) {
            //cout<<te <<endl;
            int tmp = 0;
            for(int i = 0; i < n; i++) {
                if(te[i] == '1') {
                    tmp += (1<<i);
                }
            }
            ans.push_back(tmp);
            return;
        }
        if(flag == -1) {
            dfs(te+'0',n,0);
            dfs(te+'1',n,1);
        }
        else if(!flag) {
            dfs(te+'0',n,flag);
            dfs(te+'1',n,flag^1);
        }
        else {
            dfs(te+'1',n,flag^1);
            dfs(te+'0',n,flag);
        }
        
    }
    vector<int> grayCode(int n) {
        dfs("",n,-1);
        return ans;
    }
};

