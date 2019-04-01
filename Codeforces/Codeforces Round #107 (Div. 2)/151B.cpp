#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
struct node{
	string name;
	int id;
	int taxi,pizza,girl;
}arr[105];
int cmp1(node a,node b){
	if(a.taxi==b.taxi) return a.id<b.id;
	return a.taxi>b.taxi;
}
int cmp2(node a,node b){
	if(a.pizza==b.pizza) return a.id<b.id;
	return a.pizza>b.pizza;
}
int cmp3(node a,node b){
	if(a.girl==b.girl) return a.id<b.id;
	return a.girl>b.girl;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
    	int m;
    	cin>>m>>arr[i].name;
    	arr[i].id=i;
    	for(int j=0;j<m;j++){
    		int a,b,c;
    		scanf("%d-%d-%d",&a,&b,&c);
    		if(a%10==a/10&&a==b&&b==c) arr[i].taxi++;
    		else if(a/10>a%10&&a%10>b/10&&b/10>b%10&&b%10>c/10&&c/10>c%10)  arr[i].pizza++;
    		else arr[i].girl++;
		}
	}
	sort(arr,arr+n,cmp1);
	printf("If you want to call a taxi, you should call: ");
	int first=1;
	for(int i=0;i<n;i++){
	    if(arr[i].taxi!=arr[0].taxi) break;
		if(!first) cout<<", ";
		cout<<arr[i].name;
		first=0;
	}
	cout<<"."<<endl;
	
	
	sort(arr,arr+n,cmp2);
	printf("If you want to order a pizza, you should call: ");
	first=1;
	for(int i=0;i<n;i++){
	    if(arr[i].pizza!=arr[0].pizza) break;
		if(!first) cout<<", ";
		cout<<arr[i].name;
		first=0;
	}
	cout<<"."<<endl;
	
	
	sort(arr,arr+n,cmp3);
	printf("If you want to go to a cafe with a wonderful girl, you should call: ");
	first=1;
	for(int i=0;i<n;i++){
	    if(arr[i].girl!=arr[0].girl) break;
		if(!first) cout<<", ";
		cout<<arr[i].name;
		first=0;
	}
	cout<<"."<<endl;
	return 0;
} 