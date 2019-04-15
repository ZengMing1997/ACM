#include <bits/stdc++.h>
using namespace std;
const int maxn = 305;
const int dx[] = {0,0,-1,1}; // 东 西 北 南
const int dy[] = {1,-1,0,0};
struct Edge{int head , tail; 
           Edge(int _head, int _tail):head(_head),tail(_tail){}};
struct Point{int x , y , id ; 
            Point(int _x, int _y, int _id):x(_x),y(_y),id(_id){}};
vector<Edge>Edg_info; // 边的信息
vector<Point>Point_info; // 点的信息
vector<pair<int,int> >Grid; // 网格图上的点
set<pair<int,int> >Robot_start_pos;
set<pair<int,int> >Robot_learned_edge;
vector<int>Robot_id;
//int visp[1000][1000];
map<int,int>visp[89000];
int n , m;
int ID(int x,int y) {return x * m + y; }
bool vis[maxn][maxn];
bool G[maxn][maxn][4];
bool setP[maxn*maxn];
void dfs(int x,int y)
{
    vis[x][y] = true;
    Grid.emplace_back(x,y);
    int cnt = rand() % 4 + 2; // 往几个方向走
    while (cnt--)
    {
        int dr = rand() % 4;
        int xx = x + dx[dr], yy = y + dy[dr];
        if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
        G[x][y][dr] = true;
        if (!vis[xx][yy]) dfs(xx, yy);
    }
}
void initMap()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            for(int k = 0 ; k < 4 ; k++)
            {
                int X = i + dx[k] , Y = j + dy[k];
                if(X < 0 || Y < 0 || X >= n || Y >= m) continue;
                if(G[i][j][k])
                {
                    if(!visp[ID(i,j)][ID(X,Y)])
                    {
                        Edg_info.emplace_back(Edge(ID(i,j),ID(X,Y))) , Edg_info.emplace_back(Edge(ID(X,Y),ID(i,j)));
                        //cout<<ID(i,j)<<"  " <<ID(X,Y)<<endl;
                        visp[ID(i,j)][ID(X,Y)] = visp[ID(X,Y)][ID(i,j)] = 1;
                    }
                    if(!setP[ID(i,j)])          
                    Point_info.emplace_back(Point(i,j,ID(i,j))) , setP[ID(i,j)] = 1;
                    if(!setP[ID(X,Y)])
                    Point_info.emplace_back(Point(X,Y,ID(X,Y))) , setP[ID(X,Y)] = 1;
                }
            }
        }
    }
}
void GetMapdetail()
{
    memset(G,0,sizeof(G));
    memset(vis,0,sizeof(vis));
    int sx = rand() % n , sy = rand() % m;
    dfs(sx,sy);
    initMap();
    cout << "{\"returnCode\":0,\"returnMsg\":\"succ\",\"returnUserMsg\":\"成功\",\"data\":{\"map_edge_list\":[";
    for(int i = 0; i < Edg_info.size(); i++)
    {
        cout<<"{\"head\":\""<<Edg_info[i].head<<"\",\"tail\":\""<<Edg_info[i].tail<<"\"}";
        if(i != Edg_info.size() - 1) printf(",");
    }
    printf("],");
    printf("\"map_node_list\":[");
    for(int i = 0 ; i < Point_info.size() ; i++)
    {
        printf("{\"nodeID\": \"%d\",\"x\":%d,\"y\":%d}",Point_info[i].id,Point_info[i].x,Point_info[i].y);
        if(i != Point_info.size()-1) printf(",");
    }
    printf("]}}\n");

}
void GetLearnRobotUrl()
{
    Robot_start_pos.clear();
    int cnt = 2;
    while(cnt--)
    {
        int temp = rand() % Grid.size();
        Robot_start_pos.insert(Grid[temp]);
    }
    cout << "{\"returnCode\":0,\"returnMsg\":\"succ\",\"returnUserMsg\":\"成功\",\"data\":{\"robot_list\":[";
	int index = 0;
	for(auto i : Robot_start_pos)
	{
        Robot_id.push_back(index);
		printf("{\"robot_index\": \"%d\",\"start_pos\": \"%d\"}",index++,ID(i.first,i.second));
		if (i != *prev(Robot_start_pos.end())) printf(",");
	}
	printf("]}}\n");
}
void GetLearnedQRError()
{
	Robot_learned_edge.clear();
	int cnt = rand() % 5 + 1;
	while(cnt--)
	{
		int temp = rand() % Edg_info.size();
		Robot_learned_edge.insert(make_pair(Edg_info[temp].head,Edg_info[temp].tail));
	}
	cout << "{\"returnCode\":0,\"returnMsg\":\"succ\",\"returnUserMsg\":\"成功\",\"data\":{\"robot_learn_edge_list\":[";
	int index = 0;
	for(auto i : Robot_learned_edge)
	{
		printf("{\"robot_index\": \"%d\",\"learned_times\":%d,\"head\": \"%d\",\"tail\":\"%d\"}",Robot_id[rand()%Robot_id.size()],rand()%4+1,i.first,i.second);
		if (i != *prev(Robot_learned_edge.end())) printf(",");
	}
	printf("]}}\n");
}
int main()
{
    //int n = 40 , m = 40;
    freopen("/home/zengming/桌面/data/1.in","w",stdout);
    scanf("%d%d",&n,&m);
    memset(G,0,sizeof(G));
    memset(vis,0,sizeof(vis));
    int sx = rand() % n , sy = rand() % m;
    dfs(sx,sy);
    initMap();
    cout << "{\"returnCode\":0,\"returnMsg\":\"succ\",\"returnUserMsg\":\"成功\",\"data\":{\"map_edge_list\":[";
    for(int i = 0; i < Edg_info.size(); i++)
    {
        cout<<"{\"head\":\""<<Edg_info[i].head<<"\",\"tail\":\""<<Edg_info[i].tail<<"\"}";
        if(i != Edg_info.size() - 1) printf(",");
    }
    printf("],");
    printf("\"map_node_list\":[");
    for(int i = 0 ; i < Point_info.size() ; i++)
    {
        printf("{\"nodeID\": \"%d\",\"x\":%d,\"y\":%d}",Point_info[i].id,Point_info[i].x,Point_info[i].y);
        if(i != Point_info.size()-1) printf(",");
    }
    printf("]}}\n");
     Robot_start_pos.clear();
    int cnt = 2;
    while(cnt--)
    {
        int temp = rand() % Grid.size();
        Robot_start_pos.insert(Grid[temp]);
    }
    cout << "{\"returnCode\":0,\"returnMsg\":\"succ\",\"returnUserMsg\":\"成功\",\"data\":{\"robot_list\":[";
	int index = 0;
	for(auto i : Robot_start_pos)
	{
        Robot_id.push_back(index);
		printf("{\"robot_index\": \"%d\",\"start_pos\": \"%d\"}",index++,ID(i.first,i.second));
		if (i != *prev(Robot_start_pos.end())) printf(",");
	}
	printf("]}}\n");
    Robot_learned_edge.clear();
	cnt = rand() % 5 + 1;
	while(cnt--)
	{
		int temp = rand() % Edg_info.size();
		Robot_learned_edge.insert(make_pair(Edg_info[temp].head,Edg_info[temp].tail));
	}
	cout << "{\"returnCode\":0,\"returnMsg\":\"succ\",\"returnUserMsg\":\"成功\",\"data\":{\"robot_learn_edge_list\":[";
	index = 0;
	for(auto i : Robot_learned_edge)
	{
		printf("{\"robot_index\": \"%d\",\"learned_times\":%d,\"head\": \"%d\",\"tail\":\"%d\"}",Robot_id[rand()%Robot_id.size()],rand()%4+1,i.first,i.second);
        printf("{\"robot_index\": \"%d\",\"learned_times\":%d,\"head\": \"%d\",\"tail\":\"%d\"}",Robot_id[rand()%Robot_id.size()],rand()%4+1,i.second,i.first);
		if (i != *prev(Robot_learned_edge.end())) printf(",");
	}
	printf("]}}\n");
	//GetMapdetail();
	//GetLearnRobotUrl();
	//GetLearnedQRError();
}