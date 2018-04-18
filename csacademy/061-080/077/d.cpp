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
string S[1010101];

ll tot;

void dfs(int L,int R,int C) {
	if(S[L].size()<=C) L++;
	if(R<=L+1) return;
	int LL[26],RR[26];
	int i;
	FOR(i,26) LL[i]=1010101,RR[i]=-2;
	for(i=L;i<R;i++) {
		int c=S[i][C]-'a';
		LL[c]=min(LL[c],i);
		RR[c]=max(RR[c],i+1);
	}
	FOR(i,26) if(LL[i]<RR[i]) {
		ll num=RR[i]-LL[i];
		tot+=num*(num-1)/2;
		dfs(LL[i],RR[i],C+1);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>S[i];
	sort(S,S+N);
	dfs(0,N,0);
	
	_P("%.12lf\n",tot/(1.0*N*(N-1)/2));
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
