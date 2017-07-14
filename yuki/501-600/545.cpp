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
ll A[40],B[40];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i]>>B[i];
	
	if(i==1) return _P("%lld\n",min(A[0],B[0]));
	
	int L=N/2;
	int R=N-N/2;
	
	set<ll> P;
	for(int mask=0;mask<1<<L;mask++) {
		ll dif=0,sum=0;
		FOR(i,L) {
			if(mask&(1<<i)) {
				dif+=A[i];
			}
			else {
				dif-=B[i];
			}
		}
		P.insert(dif);
	}
	
	ll mi=1LL<<50, ret=0;
	for(int mask=0;mask<1<<R;mask++) {
		ll dif=0;
		FOR(i,R) {
			if(mask&(1<<i)) {
				dif+=A[i+L];
			}
			else {
				dif-=B[i+L];
			}
		}
		
		auto it=P.lower_bound(-dif);
		
		if(it!=P.begin()) {
			auto it2=it;
			it2--;
			mi=min(mi,abs(dif+*it2));
			
		}
		if(it!=P.end()) {
			mi=min(mi,abs(dif+*it));
			auto it3=it;
			it3++;
			if(it3!=P.end()) mi=min(mi,abs(dif+*it3));
			
		}
	}
	
	cout<<mi<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
