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

ll N,P,Q;
ll C[505050];
ll S[505050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>P>>Q;
	ll sc=0;
	vector<ll> V;
	FOR(i,N) {
		cin>>C[i];
		V.push_back(C[i]+P*(i+1));
		sc+=P*(Q+i);
	}
	sort(ALL(V));
	reverse(ALL(V));
	ll add=0;
	ll ma=0;
	FOR(i,V.size()) {
		add+=V[i];
		ll na=add+(i+1LL)*(i+1LL)*P-(i+1)*P*(Q+2*N);
		ma=max(ma,na);
	}
	cout<<sc+ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
