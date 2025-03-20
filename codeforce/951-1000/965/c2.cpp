#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int T,N,K;
pair<ll,ll> P[202020];

ll num(ll v) {
	int need=(N+1)/2;
	int i;
	FOR(i,N-1) if(P[i].first>=v) need--;
	
	ll ret=0;
	for(i=N-1;i>=0;i--) if(P[i].first<v&&P[i].second&&need>0) {
		ret+=v-P[i].first;
		need--;
	}
	
	if(need>0) return 1LL<<60;
	return ret;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		FOR(i,N) cin>>P[i].first;
		FOR(i,N) cin>>P[i].second;
		sort(P,P+N);
		
		ll ret=0;
		x=N/2-1;
		FOR(i,N) if(P[i].second) {
			ret=max(ret,P[i].first+K+P[x+(i<=x)].first);
		}
		
		if(P[N-1].second==0) {
			int ma=0;
			for(i=29;i>=0;i--) if(num(ma+(1<<i))<=K) ma+=1<<i;
			ret=max(ret,P[N-1].first+ma);
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
