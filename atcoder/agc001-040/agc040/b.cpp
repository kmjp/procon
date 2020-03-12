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
pair<ll,ll> P[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll ma=0;
	FOR(i,N) {
		cin>>P[i].first>>P[i].second;
		P[i].second;
	}
	
	sort(P,P+N);
	ll L=P[0].first,R=P[0].second;
	A[0]=R-L;
	for(i=1;i<N;i++) {
		L=max(L,P[i].first);
		R=min(R,P[i].second);
		A[i]=max(0LL,R-L);
	}
	L=P[N-1].first,R=P[N-1].second;
	B[N-1]=R-L;
	for(i=N-2;i>=0;i--) {
		L=max(L,P[i].first);
		R=min(R,P[i].second);
		B[i]=max(0LL,R-L);
	}
	FOR(i,N) {
		ma=max(ma,A[i]+B[i+1]);
	}
	
	
	multiset<int> SL,SR;
	FOR(i,N) SL.insert(P[i].first),SR.insert(P[i].second);
	FOR(i,N) {
		SL.erase(SL.find(P[i].first));
		SR.erase(SR.find(P[i].second));
		
		int AL=*SL.rbegin();
		int AR=*SR.begin();
		ma=max(ma,P[i].second-P[i].first+max(0,AR-AL));
		SL.insert(P[i].first);
		SR.insert(P[i].second);
	}
	
	
	
	cout<<ma<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
