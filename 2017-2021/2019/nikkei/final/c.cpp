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

int H,W,K;
ll R[101010],C[101010];

void solve() {
	int i,j,k,l,r,x,y;
	
	cin>>H>>W>>K;
	FOR(y,H) R[y]=W;
	FOR(x,W) C[x]=H;
	FOR(i,K) {
		cin>>y>>x;
		R[y-1]--;
		C[x-1]--;
	}
	
	ll sum=1LL*H*W-K;
	ll ret=0;
	ll s=0;
	FOR(y,H) {
		s+=R[y];
		if(s>sum/2) break;
	}
	FOR(i,H) ret+=R[i]*abs(y-i);
	s=0;
	FOR(x,W) {
		s+=C[x];
		if(s>sum/2) break;
	}
	FOR(i,W) ret+=C[i]*abs(x-i);
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
