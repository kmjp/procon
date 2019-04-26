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
set<int> V[101010];
map<string,int> mp;
ll ok[40];
int dp[1<<20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	int pre=0;
	FOR(i,N) {
		cin>>x;
		if(x==1) {
			pre=i;
		}
		else {
			cin>>s;
			if(mp.count(s)==0) {
				x=mp.size();
				mp[s]=x;
			}
			V[mp[s]].insert(pre);
		}
	}
	
	FOR(x,M) {
		FOR(y,M) if(x!=y) {
			i=x,j=y;
			if(V[i].size()>V[j].size()) swap(i,j);
			r=1;
			FORR(v,V[i]) if(V[j].count(v)) {
				r=0;
				break;
			}
			if(r) ok[x] |= 1LL<<y;
		}
		ok[x] |= 1LL<<x;
	}
	int mask;
	for(mask=1;mask<1<<20;mask++) {
		ll ma=(1LL<<40)-1;
		FOR(i,20) if(mask&(1<<i)) ma &= ok[20+i];
		ma>>=20;
		if((mask&ma)==mask) dp[mask]=__builtin_popcount(mask);
	}
	FOR(i,20) {
		FOR(mask,1<<20) if(mask&(1<<i)) dp[mask]=max(dp[mask],dp[mask^(1<<i)]);
	}
	int best=0;
	for(mask=0;mask<1<<20;mask++) {
		ll ma=(1LL<<40)-1;
		FOR(i,20) if(mask&(1<<i)) ma &= ok[i];
		if((mask&ma)!=mask) continue;
		
		best=max(best,__builtin_popcount(mask)+dp[ma>>20]);
		
	}
	
	
	cout<<best<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
