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
vector<int> E[202020];
vector<int> C[3];
int R[202020];

vector<int> cand[2];

void dfs(int cur,int pre,int d) {
	cand[d].push_back(cur);
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur,d^1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	for(i=1;i<=N;i++) C[i%3].push_back(i);
	
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(0,0,0);
	
	if(cand[0].size()>cand[1].size()) swap(cand[0],cand[1]);
	
	if(cand[0].size()<=C[0].size()) {
		while(cand[0].size()&&C[0].size()) {
			x=cand[0].back();
			y=C[0].back();
			cand[0].pop_back();
			C[0].pop_back();
			R[x]=y;
		}
	}
	else {
		assert(C[2].size()<=cand[0].size());
		assert(C[1].size()<=cand[1].size());
		while(cand[0].size()&&C[2].size()) {
			x=cand[0].back();
			y=C[2].back();
			cand[0].pop_back();
			C[2].pop_back();
			R[x]=y;
		}
		while(cand[1].size()&&C[1].size()) {
			x=cand[1].back();
			y=C[1].back();
			cand[1].pop_back();
			C[1].pop_back();
			R[x]=y;
		}
	}
	
	FORR(c,cand[0]) {
		FOR(i,3) if(C[i].size()) {
			R[c]=C[i].back();
			C[i].pop_back();
			break;
		}
	}
	FORR(c,cand[1]) {
		FOR(i,3) if(C[i].size()) {
			R[c]=C[i].back();
			C[i].pop_back();
			break;
		}
	}
	
	
	
	FOR(i,N) cout<<R[i]<<" ";
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
