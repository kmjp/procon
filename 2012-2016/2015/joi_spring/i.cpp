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
int C[505],A[505];
ll V[505];
ll memo[505][505][505];

ll hoge(int pre,int a,int b) {
	if(memo[pre+1][a][b]>=0) return memo[pre+1][a][b];
	ll ret=0;
	int c;
	if(b<pre) c=pre+1;
	else c=b+1;
	
	if(a<N && (pre==-1 || (C[pre]==C[a]||A[pre]==A[a]))) {
		ret=max(ret,V[a]+hoge(a,b,c));
	}
	if(c<N && (pre==-1 || (C[pre]==C[c]||A[pre]==A[c]))) {
		ret=max(ret,V[c]+hoge(c,a,b));
	}
	return memo[pre+1][a][b]=ret;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(memo);
	cin>>N;
	FOR(i,N) cin>>C[i]>>A[i]>>V[i];
	cout<<hoge(-1,0,1)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
