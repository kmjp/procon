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
set<pair<int,int>> S;
int D[101010];
vector<int> R;

void dfs(int cur,int d) {
	if(D[cur]>=0) return;
	D[cur]=d;
	if(d*3%N==0) R.push_back(cur);
	FORR(e,E[cur]) dfs(e,d+1);
}


void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		E[x].push_back(y);
		E[y].push_back(x);
		S.insert({x,y});
		S.insert({y,x});
	}
	
	for(i=1;i<=N;i++) {
		FOR(z,E[i].size()) {
			FOR(y,z) {
				if(S.count({E[i][y],E[i][z]})) {
					return _P("%d %d %d\n",i,E[i][y],E[i][z]);
				}
				else {
					FOR(x,y) {
						if(S.count({E[i][x],E[i][z]})==0 && S.count({E[i][x],E[i][y]})==0) {
							return _P("%d %d %d\n",E[i][x],E[i][y],E[i][z]);
						}
					}
				}
			}
		}
	}
	
	if(N==M && N%3==0) {
		MINUS(D);
		dfs(1,0);
		_P("%d %d %d\n",R[0],R[1],R[2]);
		return;
	}
	
	_P("-1\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
