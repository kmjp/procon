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

int N,Q;
int A[101010],B[101010];
pair<ll,ll> P[101010];
ll C[101010];
int ret[101010];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	P[0]={0,0};
	FOR(i,N) cin>>A[i];
	FOR(i,N) {
		cin>>B[i];
		P[i+1]={P[i].first+A[i],P[i].second+B[i]};
	}
	cin>>Q;
	while(Q--) {
		ll X;
		cin>>X;
		x=lower_bound(P,P+N+1,make_pair(X+1,0LL))-P;
		x--;
		if(P[x].second==X) cout<<"draw"<<endl;
		if(P[x].second>X) cout<<"usagi"<<endl;
		if(P[x].second<X) cout<<"kame"<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
