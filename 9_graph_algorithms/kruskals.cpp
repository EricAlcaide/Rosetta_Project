#include <bits/stdc++.h>
#define N 10
using namespace std;
int parent[N + 5], ranki[N + 5];
#define mypair pair< int, pair<int,int> >
#define pb push_back
#define f first
#define s second
vector<mypair> edges;
int ne,n;
void init() {
	//initially all are members of group that contains themselves only (therefore 1)
	memset(ranki, 1, N + 5);

	//iniitially all are parent of themselves
	for (int i = 0; i < N; i++)
		parent[i] = i;

}
//find parent of 'n' upto the root
int find(int n) {
	queue<int> q;
	q.push(n);  //queue for 'n' and all its parent for path compression
	while (n != parent[n]) {
		n = parent[n];
		q.push(n);
	}
	while (!q.empty()) {
		parent[q.front()] = n;   //assign root as parent of all ancestors of 'n'
		q.pop();
	}

	return n;
}
void merge(int x, int y) {
	int _x = find(x);   //traverse upwards and find root of x;
	int _y = find(y);   //same with y

	//if dont belong to same union merge
	if (_x != _y) {

		if (ranki[_x] > ranki[_y]) {
			parent[_y] = _x;
			ranki[_x]++;
		} else {
			parent[_x] = _y;
			ranki[_y]++;
		}

	}
}
void kruskal(){
   sort(edges.begin(),edges.end());
    
   int count=0;
    for(int i=0;count<n-1&&i<ne;i++){
       
       if(find(edges[i].s.f)!=find(edges[i].s.s))
         {    count++;
             cout<<edges[i].s.f<<" <-- "<<edges[i].f<<" --> "<<edges[i].s.s<<endl;
                         merge(edges[i].s.f,edges[i].s.s);
         } 

    }



}
int main() {
	init();
	cout<<"Enter number of nodes and edges:";
	 cin>>n>>ne;
	 cout<<"source destination cost:\n";
	 for(int i=0;i<ne;i++)
	 {  int s,d,c;	
	  cin>>s>>d>>c;
      edges.pb({c,{s,d}});
     }
   kruskal();
	return 0;
}