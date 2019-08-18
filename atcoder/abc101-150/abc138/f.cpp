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

ll L,R;
ll mo=1000000007;
ll dp[2][2][2][63];

ll hoge(int d,int S,int LT,int RT) {
	if(d==-1) return S==1;
	if(dp[S][LT][RT][d]>=0) return dp[S][LT][RT][d];
	
	ll ret=0;
	
	int a,b;
	FOR(a,2) FOR(b,2) {
		if(a==0 && LT && (L&(1LL<<d))>0) continue;
		if(b==1 && RT && (R&(1LL<<d))==0) continue;
		if(a>b) continue;
		if(S==0 && a!=b) continue;
		int NLT=LT&&(((L>>d)&1)==a);
		int NRT=RT&&(((R>>d)&1)==b);
		int NS=S || (a==1 && b==1);
		ret+=hoge(d-1,NS,NLT,NRT);
	}
	
	return dp[S][LT][RT][d]=ret%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>L>>R;
	MINUS(dp);
	cout<<hoge(61,0,1,1)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
