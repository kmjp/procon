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
vector<pair<int,int>> E[2][505050];
int st[2][505050];
int W[2][505050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y>>r;
		E[0][x].push_back({y,r});
		E[1][y].push_back({x,r});
		W[0][y]++;
		W[1][x]++;
	}
	queue<int> Q;
	FOR(i,N) {
		if(W[0][i]==0) Q.push(i);
		if(W[1][i]==0) Q.push(i+100000);
	}
	while(Q.size()) {
		int k=Q.front()%100000;
		int t=Q.front()/100000;
		
		Q.pop();
		FORR(r,E[t][k]) {
			st[t][r.first] = max(st[t][r.first],st[t][k]+r.second);
			if(--W[t][r.first]==0) Q.push(r.first+t*100000);
		}
	}
	
	int ret=0;
	FOR(i,N) if(st[0][i]+st[1][i] != st[0][N-1]+st[1][N-1]) ret++;
	cout<<st[0][N-1]<<" "<<ret<<"/"<<N<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
