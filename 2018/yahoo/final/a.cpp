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

int N,M;
int cnt[101010];
int num[101010];

vector<ll> enumdiv(ll n) {
	vector<ll> V;
	for(ll i=2;i*i<=n;i++) {
		if(n%i==0) V.push_back(i);
		while(n%i==0) n/=i;
	}
	if(n>1) V.push_back(n);
	return V;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>x, cnt[x]++;
	
	for(i=1;i<=M;i++) {
		for(j=i;j<=100000;j+=i) num[i]+=cnt[j];
		
		vector<ll> D=enumdiv(i);
		ll ret=0;
		for(int mask=0;mask<1<<D.size();mask++) {
			int d=1;
			FOR(j,D.size()) if(mask&(1<<j)) d*=D[j];
			if(__builtin_popcount(mask)%2==0) ret+=num[d];
			else ret-=num[d];
		}
		cout<<ret<<endl;
	}
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
