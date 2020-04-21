#include <iostream>
#include <algorithm>
using namespace std;

void init_set(int *arr, int n){
	for(int i=0;i<n;i++) arr[i] = i;
}
bool cmp(vector<int> a, vector<int> b){
	if(a[2] == b[2]) return a[0] < b[0];
	return a[2] < b[2];
}

int find(int n, int *arr){
	if(n == arr[n]) return n;
	else return n = find(arr[n], arr);
}

int main(){
	int answer = 0;// 최소로 연결되는 비용의 합 
	vector<vector<int>> v; // x, y, cost
	int n = 9;
	v.push_back({0,1,4}); // 0과 1은 정점이고 4는 비용 
	v.push_back({0,7,8});
	v.push_back({1,2,8});
	v.push_back({1,7,11});
	v.push_back({2,3,7});
	v.push_back({2,5,4});
	v.push_back({2,8,2});
	v.push_back({3,4,9});
	v.push_back({3,5,14});
	v.push_back({4,5,10});
	v.push_back({5,6,2});
	v.push_back({6,7,1});
	v.push_back({6,8,6});
	v.push_back({7,8,7});
	
	sort(v.begin(), v.end(), cmp); // 비용에 따른 오름차순으로 퀵sort 
	
	int len = v.size();
	int parent[n];// 가장 최상위에 있는 부모노드를 알려주는 배열
	
	init_set(parent, n);
	
	for(int i=0;i<len;i++){
		int startPoint_parent = find(v[i][0], parent);
		int destination_parent = find(v[i][1], parent);
		int cost = v[i][2];
		if(startPoint_parent != destination_parent) { 
			parent[startPoint_parent] = destination_parent; // union();
			answer += cost; // cost
		}
	}
	
	for(int i=0;i<n;i++) cout << i << " ";
	cout << " 정점 번호입니다.\n";
	for(int i=0;i<n;i++) cout << parent[i] << " ";
	cout << " 정점 값입니다.\n";
	cout << "모든 노드를 연결할 때 요구되는 가장 작은 비용은 "<<answer << " 입니다.\n";
	
}
