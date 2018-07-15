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

int N,D1,D2;
vector<pair<int,int>> NG;

void hoge(int v) {
	for(int a=0;a*a<=v;a++) {
		int b;
		for(b=0;a*a+b*b<v;b++);
		if(a*a+b*b==v) {
			NG.push_back({a,b});
			NG.push_back({a,-b});
			NG.push_back({-a,b});
			NG.push_back({-a,-b});
		}
	}
}

int ok[606][606];

vector<pair<int,int>> D[2];
void dfs(int y,int x,int d) {
	if(ok[y][x]==0) return;
	ok[y][x]=0;
	D[d].push_back({x,y});
	FORR(a,NG) {
		if(x+a.first<0) continue;
		if(x+a.first>2*N) continue;
		if(y+a.second<0) continue;
		if(y+a.second>2*N) continue;
		dfs(y+a.second,x+a.first,d^1);
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>D1>>D2;
	hoge(D1);
	sort(ALL(NG));
	NG.erase(unique(ALL(NG)),NG.end());

	FOR(x,2*N) FOR(y,2*N) ok[y][x]=1;
	vector<pair<int,int>> R;
	
	FOR(y,2*N) FOR(x,2*N) if(ok[y][x]) {
		D[0].clear();
		D[1].clear();
		dfs(y,x,0);
		if(D[0].size()<D[1].size()) swap(D[0],D[1]);
		FORR(d,D[0]) R.push_back(d);
	}
	NG.clear();
	hoge(D2);
	sort(ALL(NG));
	NG.erase(unique(ALL(NG)),NG.end());
	
	FOR(x,2*N) FOR(y,2*N) ok[y][x]=0;
	FORR(r,R) ok[r.first][r.second]=1;
	R.clear();
	FOR(y,2*N) FOR(x,2*N) if(ok[y][x]) {
		D[0].clear();
		D[1].clear();
		dfs(y,x,0);
		if(D[0].size()<D[1].size()) swap(D[0],D[1]);
		FORR(d,D[0]) R.push_back(d);
	}
	
	assert(R.size()>=N*N);
	FOR(i,N*N) cout<<R[i].first<<" "<<R[i].second<<endl;	
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
