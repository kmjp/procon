#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int Q;
vector<int> E[202020];
int ret[202020];

int dp1[202020],dp2[202020],dp3[202020];
int M;

int dfs2(int cur,int pre) {
	vector<int> cand={1,1,1};
	FORR(e,E[cur]) if(e!=pre&&e<M) cand.push_back(dfs2(e,cur)+1);
	sort(ALL(cand));
	reverse(ALL(cand));
	dp1[cur]=cand[0];
	dp2[cur]=cand[1];
	dp3[cur]=cand[2];
	return dp2[cur];
}

void dfs3(int cur,int pre,int pv) {
	int cand[]={dp1[cur],dp2[cur],dp3[cur],pv+1};
	sort(cand,cand+4);
	reverse(cand,cand+4);
	dp2[cur]=cand[1];
	FORR(e,E[cur]) if(e!=pre&&e<M) {
		if(dp2[e]+1==cand[0]||dp2[e]+1==cand[1]) dfs3(e,cur,cand[2]);
		else dfs3(e,cur,cand[1]);
	}
}

int hoge(int M_) {
	M=M_;
	
	dfs2(0,-1);
	dfs3(0,-1,0);
	
	
	int ma=0;
	int i;
	FOR(i,M) ma=max(ma,dp2[i]);
	return ma;
}



void dfs(int L,int R,int retL,int retR) {
	if(L>=R) return;
	if(retL==retR) {
		while(L<R) ret[L++]=retL;
		return;
	}
	int M=(L+R)/2;
	
	ret[M]=hoge(M);
	dfs(L,M,retL,ret[M]);
	dfs(M+1,R,ret[M],retR);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	FOR(i,Q) {
		cin>>x;
		E[x-1].push_back(i+1);
		E[i+1].push_back(x-1);
	}
	dfs(2,Q+2,1,17);
	
	FOR(i,Q) cout<<ret[i+2]<<" ";
	cout<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
