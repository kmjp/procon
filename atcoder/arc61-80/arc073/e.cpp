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
ll X[202020],Y[202020];
pair<ll,ll> P[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll RI=1LL<<30,RA=0;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		if(X[i]>Y[i]) swap(X[i],Y[i]);
		RI=min(RI,X[i]);
		RA=max(RA,Y[i]);
		P[i]={X[i],Y[i]};
	}
	sort(P,P+N);
	
	ll ret=1LL<<60;
	ll LA=P[N-1].first,RB=RA;
	FOR(i,N) RB=min(RB,P[i].second);
	ret=min(ret,(LA-RI)*(RA-RB));
	
	set<pair<ll,int>> S;
	S.insert({P[0].second,1000000});
	FOR(i,N) if(i) S.insert({P[i].second,i});
	while(1) {
		ll dif=S.rbegin()->first-S.begin()->first;
		ret=min(ret,(RA-RI)*dif);
		
		auto a=*S.rbegin();
		S.erase(*S.rbegin());
		if(a.second>=1000000) break;
		S.insert({P[a.second].first,1000000});
	}
	
	cout<<ret<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
