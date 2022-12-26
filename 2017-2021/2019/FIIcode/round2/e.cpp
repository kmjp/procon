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

ll N,Q;
vector<ll> A,B,L,M,R;

int NG[7070];
ll ML[7070],MR[7070];
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,Q) {
		ll v;
		cin>>x>>v;
		if(x) A.push_back(v);
		else B.push_back(v);
	}
	
	sort(ALL(A));
	sort(ALL(B));
	FORR(b,B) {
		if(b<A[0]) L.push_back(b);
		if(A[0]<b && b<A.back()) M.push_back(b);
		if(b>A.back()) R.push_back(b);
	}
	
	ll f=0,g=0;
	FORR(a,A) {
		if(f==0) f=a;
		else g=__gcd(g,a-f);
	}
	vector<ll> D;
	map<ll,int> rev;
	for(ll a=1;a*a<=g;a++) if(g%a==0) {
		D.push_back(a);
		if(a*a!=g) D.push_back(g/a);
	}
	sort(ALL(D));
	FOR(i,D.size()) {
		rev[D[i]]=i;
		ML[i]=1;
		MR[i]=N;
	}
	FORR(m,M) NG[rev[__gcd(g,m-f)]]=1;
	FORR(l,L) ML[rev[__gcd(g,f-l)]]=l+1;
	reverse(ALL(R));
	FORR(r,R) MR[rev[__gcd(g,r-f)]]=r-1;
	
	ll ret=0;
	FOR(i,D.size()) {
		for(j=i+1;j<D.size();j++) if(D[j]%D[i]==0) {
			NG[i]|=NG[j];
			ML[i]=max(ML[i],ML[j]);
			MR[i]=min(MR[i],MR[j]);
		}
		if(NG[i]) continue;
		ll lef=(1+(f-ML[i])/D[i])%mo;
		ll ri=(1+(MR[i]-A.back())/D[i])%mo;
		(ret+=lef*ri)%=mo;
	}
	
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
