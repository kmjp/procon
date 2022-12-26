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

ll dp[101][101][101];
ll mo=1000000007;

ll hoge(int T,int mi,int num) {
	if(T<mi) return 0;
	if(num==0) return 1;
	if(dp[T][mi][num]>=0) return dp[T][mi][num];
	dp[T][mi][num]=hoge(T,mi+1,num)+hoge(T-mi,mi,num-1);
	return dp[T][mi][num];
}

int N,A,B,C;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(dp);
	
	cin>>N;
	while(N--) {
		cin>>A>>B>>C;
		ll ret=0;
		for(x=0;x<A;x++) {
			y=C-x;
			if(0<=y && y<B) (ret += hoge(A,1,x)*hoge(B,1,y))%=mo;
		}
		cout<<ret<<endl;
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
