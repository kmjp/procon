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
ll A[2020];
ll memo[2020][2020][2];

ll hoge(int L,int R,int S) {
	if(memo[L][R][S]>=0) return memo[L][R][S];
	ll& ret=memo[L][R][S];
	ret=1LL<<60;
	
	if(L==0 && R==N-1) {
		if(S==0) ret=A[0];
		else ret=A[N-1];
	}
	else {
		if(S==0) {
			if(L) ret=min(ret,hoge(L-1,R,0)+1);
			if(R<N-1) ret=min(ret,hoge(L,R+1,1)+(R+1-L));
			ret=max(ret,A[L]);
		}
		else {
			if(L) ret=min(ret,hoge(L-1,R,0)+(R-(L-1)));
			if(R<N-1) ret=min(ret,hoge(L,R+1,1)+1);
			ret=max(ret,A[R]);
		}
	}
	return ret;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	MINUS(memo);
	
	ll mi=1LL<<50;
	FOR(i,N) mi=min(mi,hoge(i,i,0));
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
