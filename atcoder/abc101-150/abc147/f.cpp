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

ll N;
ll X,D;

map<ll,vector<pair<ll,ll>>> M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X>>D;
	
	if(D==0) {
		if(X==0) cout<<1<<endl;
		else cout<<(N+1)<<endl;
		return;
	}
	
	if(D<0) {
		X+=(N-1)*D;
		D=-D;
	}
	
	ll tot=D*N*(N-1)/2;
	FOR(i,N+1) {
		ll ma=D*N*i-D*i*(i+1)/2;
		ll mi=D*i*(i-1)/2;
		
		ll lef=X*i-X*(N-i)+mi-(tot-mi);
		ll ri=X*i-X*(N-i)+ma-(tot-ma)+2*D;
		ll cat=(lef%(2*D)+2*D)%(2*D);
		assert((ri-lef)%(2*D)==0);
		M[cat].push_back({lef,ri});
	}
	
	ll ret=0;
	FORR(m,M) {
		vector<pair<ll,ll>> V=m.second;
		sort(ALL(V));
		ll L=-1LL<<62,R=L;
		FORR(v,V) {
			if(v.first<=R) {
				R=max(R,v.second);
			}
			else {
				ret+=(R-L)/(2*D);
				L=v.first;
				R=v.second;
			}
		}
		ret+=(R-L)/(2*D);
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
