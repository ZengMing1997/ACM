#include <bits/stdc++.h>
using namespace std;
vector<int>G[10];
map<pair<int,int> , int > NUM;
map<int,int>M;
int vis[10][100000];
int nowTime[10][300][300];
int cur;
void getMapdetil()
{
    ifstream in;
    in.open("/home/zengming/桌面/2.txt");
    string te ;
    int TT = 1;
    while(getline(in,te))
    {
        int pos = te.find("End PathToAnsTrace");
        if(pos != -1)
        {
            for(int i = 0 ; i < 10 ; i ++) G[i].clear();cur = -1;
            printf("Running test %d\n",TT++);
            int l = te.find("robot_index"); 
            int r = te.find("requestId");
            string now(te.substr(l,r-l));
            int flag = 0;
            for(int i = 0; i < now.size() ; i++)
            {
                if(now[i] == 'r')  now[i] = ' ',flag = 1;
                else
                {
                    if(now[i] < '0' || now[i] > '9') now[i] = ' ';
                    else if(flag) {flag = 0;now[i] = '1';now[i-1] = '-';}
                }
            }
            istringstream is(now);
            int pos = 0;
            int num[3] , a , edge_num = 0;
            //cout<<now<<endl;
            int MAX = 0;
            flag = 0;
            while(is>>a)
            {
                if(a == -1) {MAX = max(MAX,int(G[cur].size()));cur++; continue;}
                if(G[cur].size() == 0) {G[cur].push_back(a);continue;}
                if(a == G[cur][G[cur].size() - 1]) continue;
                G[cur].push_back(a);
            }
            printf("RobotNUM %d\n",cur+1);
            for(int i = 1 ; i < MAX ; i++)
            {
                for(int j = 1 ; j <= cur ; j++)
                {
                    if(G[j].size() >= i) continue;
                    if(G[j][i] == G[j-1][i])
                    {
                        flag = 1;
                        printf("ERROR!!!! Robot1index = %d  Robot2index = %d \n",j,j-1);
                    }
                    if(G[j-1][i-1] == G[j][i] && G[j][i-1] == G[j-1][i])
                    {
                        flag = 1;
                        printf("ERROR!!!! Robot1index = %d  Robot2index = %d \n",j,j-1);
                    }
                }
            }
            if(!flag) puts("OK");
        }
    }
}
int main()
{
    freopen("1.txt","w",stdout);
    getMapdetil();
}