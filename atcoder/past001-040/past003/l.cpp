#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
deque<int> T[101010];
int M;
int A;

set<pair<int,int>> Q[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		FOR(j,x) {
			cin>>y;
			T[i].push_back(y);
		}
		Q[0].insert({-T[i][0],i});
		Q[1].insert({-T[i][0],i});
		if(T[i].size()>=2) {
			Q[1].insert({-T[i][1],i});
		}
	}
	
	cin>>M;
	FOR(i,M) {
		cin>>x;
		if(x==1) {
			auto it=Q[0].begin();
			
			x=it->second;
			y=-it->first;
		}
		else {
			auto it=Q[1].begin();
			x=it->second;
			y=-it->first;
		}
		cout<<y<<endl;
		Q[0].erase({-T[x][0],x});
		Q[1].erase({-T[x][0],x});
		Q[1].erase({-T[x][1],x});
		
		if(T[x][0]==y) {
			T[x].pop_front();
		}
		else {
			y=T[x][0];
			T[x].pop_front();
			T[x].pop_front();
			T[x].push_front(y);
		}
		
		if(T[x].size()>=1) {
			Q[0].insert({-T[x][0],x});
			Q[1].insert({-T[x][0],x});
		}
		if(T[x].size()>=2) {
			Q[1].insert({-T[x][1],x});
		}
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
