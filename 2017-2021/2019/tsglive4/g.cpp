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
int L;
string S[1024];
int pat[11][1024][1024];
map<vector<int>,int> M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	while(1<<(L+1)<=N) L++;
	int cnt[2]={};
	vector<pair<int,int>> cand;
	FOR(y,N) {
		cin>>S[y];
		cnt[0]+=count(ALL(S[y]),'#');
		cnt[1]+=count(ALL(S[y]),'.');
		FOR(x,N) if(S[y][x]=='?') cand.push_back({y,x});
	}
	if(cnt[0]==0 || cnt[1]==0) return _P("1\n");
	M[{1,1,1,1}]=1;
	M[{2,2,2,2}]=2;
	FOR(y,N) FOR(x,N) {
		if(S[y][x]=='#') pat[0][y][x]=1;
		else if(S[y][x]=='.') pat[0][y][x]=2;
	}
	
	vector<vector<int>> unfixed;
	for(i=1;i<=L;i++) {
		int step=(1<<i);
		for(y=0;y<N;y+=step) for(x=0;x<N;x+=step) {
			vector<int> V;
			V.push_back(pat[i-1][y][x]);
			V.push_back(pat[i-1][y+step/2][x]);
			V.push_back(pat[i-1][y][x+step/2]);
			V.push_back(pat[i-1][y+step/2][x+step/2]);
			if(count(ALL(V),0)) {
				unfixed.push_back({i,y,x});
			}
			else if(M.count(V)) {
				pat[i][y][x]=M[V];
			}
			else {
				pat[i][y][x]=M.size()+1;
				M[V]=pat[i][y][x];
			}
		}
	}
	
	int mi=1<<30;
	for(int mask=0;mask<1<<cand.size();mask++) {
		FOR(i,cand.size()) {
			pat[0][cand[i].first][cand[i].second]=1+((mask>>i)&1);
		}
		vector<vector<int>> added;
		FORR(u,unfixed) {
			i=u[0];
			y=u[1];
			x=u[2];
			vector<int> V;
			int step=(1<<i);
			V.push_back(pat[i-1][y][x]);
			V.push_back(pat[i-1][y+step/2][x]);
			V.push_back(pat[i-1][y][x+step/2]);
			V.push_back(pat[i-1][y+step/2][x+step/2]);
			if(M.count(V)) {
				pat[i][y][x]=M[V];
			}
			else {
				pat[i][y][x]=M.size()+1;
				M[V]=pat[i][y][x];
				added.push_back(V);
			}
		}
		mi=min(mi,(int)M.size());
		FORR(a,added) M.erase(a);
		
	}
	cout<<mi<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
