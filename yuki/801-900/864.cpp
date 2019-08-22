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

ll N,K;

ll ret;

ll hoge(ll v) {
	if(v<2 || v>2*N) return 0;
	if(v<=N+1) return v-1;
	return 2*N-v+1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	for(ll a=1;a*a<=K;a++) if(K%a==0) {
		if(a*a==K) ret+=hoge(a)*hoge(K/a);
		else ret+=hoge(a)*hoge(K/a)*2;
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
