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


int N,M;
vector<int> E[101010];
int can[101010];
int X,Y;

int vis[101010];

void dfs(int cur,int col) {
	if(can[cur]&col) return;
	can[cur]|=col;
	FORR(e,E[cur]) dfs(e,col);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	cin>>X>>Y;
	X--,Y--;
	FOR(i,M) {
		cin>>x>>y;
		E[y-1].push_back(x-1);
	}
	
	dfs(X,1);
	dfs(Y,2);
	int both=0;
	FOR(i,N) if(can[i]==3) both=1;
	FOR(i,N) {
		x;
		if(can[i]==3) {
			x=0;
		}
		else if(can[i]==1) {
			x=1;
		}
		else if(can[i]==2) {
			x=1;
		}
		else {
			if(both) x=1;
			else x=2;
		}
		cout<<x<<" ";
	}
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
