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

int N,D,A;
pair<ll,ll> P[202020];
ll DD[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>D>>A;
	FOR(i,N) {
		cin>>x>>y;
		P[i]={x,(y+A-1)/A};
	}
	sort(P,P+N);
	P[N]={1LL<<60,0};
	
	ll sum=0;
	FOR(i,N) {
		if(i) DD[i]+=DD[i-1];
		P[i].second-=DD[i];
		if(P[i].second>0) {
			x=lower_bound(P,P+N,make_pair(P[i].first+2LL*D+1,-1LL<<60))-P;
			sum+=P[i].second;
			DD[i]+=P[i].second;
			DD[x]-=P[i].second;
		}
	}
	cout<<sum<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
