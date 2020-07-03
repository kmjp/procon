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

int N,R,G,B,S;
int mo=1000000007;

const int CN=4001;
ll C[CN][CN];
ll p2[3050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,CN) for(j=0;j<=i;j++) C[i][j]=(j==0||j==i)?1:(C[i-1][j-1]+C[i-1][j])%mo;
	p2[0]=1;
	FOR(i,3030) p2[i+1]=1LL*p2[i]*2%mo;
	
	cin>>N>>R>>G>>B;
	S=N-R-G-B;
	int slot=S+1;
	
	ll ret=0;
	for(int s2=0;s2<=slot;s2++) {
		int s1=R+G+B-s2*2;
		int s0=slot-s1-s2;
		if(s1<0 || s0<0) continue;
		
		ll pat=1LL*C[slot][s2]*C[s0+s1][s0]%mo;
		ll hoge=0;
		for(int r2=0;r2<=min(R,s2);r2++) {
			ll pat1=C[s2][r2];
			int r1=R-r2;
			if(r1>s1) continue;
			(pat1*=C[s1][r1])%=mo;
			int bl=B-(s2-r2);
			int gl=G-(s2-r2);
			if(bl<0 || gl<0) continue;
			(hoge += pat1*C[bl+gl][gl]%mo)%=mo;
		}
		(ret += pat*hoge%mo*p2[s2])%=mo;
	}
	
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
