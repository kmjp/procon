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
int P[101010];
vector<int> E[101010];
set<int> S;
int ret[101010];
vector<int> O[101010];

void dfs(int cur) {
	set<int> add,del;
	
	FORR(r,O[cur]) {
		if(r<0) {
			if(S.count(-r)) {
				del.insert(-r);
				S.erase(-r);
			}
		}
		else {
			if(S.count(r)==0) {
				add.insert(r);
				S.insert(r);
			}
		}
	}
	ret[cur]=S.size();
	FORR(e,E[cur]) dfs(e);
	FORR(r,add) S.erase(r);
	FORR(r,del) S.insert(r);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x;
		P[i+1]=x-1;
		E[x-1].push_back(i+1);
	}
	FOR(i,N) {
		cin>>x;
		FOR(j,x) cin>>y, O[i].push_back(y);
	}
	dfs(0);
	FOR(i,N) cout<<ret[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
