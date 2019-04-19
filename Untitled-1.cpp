#include <bits/stdc++.h>
using namespace std;
const int Roulette_size = 12;
const int Box_size = 6;
const int Goods_number = 3000;
const int Roulette_speed = 3;
const int Box_speed = 1;
int Roulette_cur_pos , Box_cur_pos,curtime;
struct Goods
{
	int OrderID , GoodsID;
	int frame_pos,Box_pos , Roulette_pos;
	Goods (int OrderID , int GoodsID , int frame_pos,int Box_pos,int Roulette_pos) : 
	OrderID(OrderID) , GoodsID(GoodsID) ,frame_pos(frame_pos),Box_pos(Box_pos),Roulette_pos(Roulette_pos) {}
};
bool Roulette_is_used[Roulette_size];
vector<pair<int,int> >Box_detil[Roulette_size][Box_size];
vector<Goods>all_Goods;
map<int,queue<Goods> >Need_Time;
bool check(Goods a)
{
	while(Roulette_is_used[Roulette_cur_pos] == true)
	{
		Roulette_cur_pos = (curtime + 1) % Roulette_size;
		Box_cur_pos = (Box_cur_pos+1) % (Box_size * Roulette_speed);
		curtime = curtime + 1;
		while(!Need_Time[curtime].empty())
		{
			Goods temp = Need_Time[curtime].front();
			Need_Time[curtime].pop();
			Roulette_is_used[temp.Roulette_pos]= 0;
			Box_detil[temp.frame_pos][temp.Box_pos].push_back(make_pair(temp.GoodsID,temp.OrderID));
		}
	}
	Roulette_is_used[Roulette_cur_pos] = 1;
	a.Roulette_pos = Roulette_cur_pos;
	int needtime = a.frame_pos + Box_cur_pos;
	if(needtime / Roulette_speed + (needtime % Roulette_speed == 0) == a.Box_pos)
	{
		Need_Time[curtime+a.frame_pos].push(a);
	}
	else 
	{

	}
}
int main()
{
	Roulette_is_used[0] = 1;
	for(auto i : all_Goods)
	{
		if(check(i));
	}
}