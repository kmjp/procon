#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll N,K;
string S;
ll tot[100001];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	cin>>S;
	
	i=0; y=0;
	for(x=1;x<=N*10;x++) {
		if(y==0) i++, y++;
		tot[x]=i;
		y+=S[(x-1)%N]-'0'-1;
	}
	if(K<=N*10) return _P("%lld\n",tot[K]);
	
	ll dif=tot[N*8]-tot[N*7];
	ll a=(K/N)-7;
	return _P("%lld\n",tot[N*7+(K%N)]+a*dif);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
