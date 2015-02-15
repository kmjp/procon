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

ll N,C;
ll A[100020],B[100020],F[100020];
pair<ll,int> P[1000050];

ll ma=0;
vector<pair<ll,ll> > V;

void solve() {
	int i,j,k,l,r,y; string s;
	
	cin>>N>>C;
	FOR(i,N) {
		cin>>A[i]>>B[i]>>F[i];
		P[i]=make_pair(B[i],i);
	}
	V.push_back(make_pair(0,0));
	
	sort(P,P+N);
	FOR(j,N) {
		i=P[j].second;
		ll x=F[i]-C*(B[i]-A[i]); // first
		vector<pair<ll,ll> >::iterator it=lower_bound(V.begin(),V.end(),make_pair(A[i]+1,0LL));
		it--;
		x=max(x,it->second + F[i] - C*(B[i]-it->first));
		while(V.size() && V.back().first==B[i] && V.back().second<x) V.pop_back();
		int ng=0;
		if(V.size() && V.back().second-C*(B[i]-V.back().first)>=x) ng=1;
		if(ng==0) V.push_back(make_pair(B[i],x));
		ma=max(ma,x);
	}
	cout<<ma<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
