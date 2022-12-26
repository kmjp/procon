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

ll A,B,C,D;
ll mo=1000000007;

bool cmp(pair<ll,ll>& L,pair<ll,ll>& R) {
	return L.first*R.second < L.second*R.first;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>C>>D;
	
	vector<pair<ll,ll>> V;
	for(i=0;i<=D+1;i++) {
		if(i&&i<A) V.push_back({i,A});
		if(A-1-i>0) V.push_back({A-1-i,A});
		if(i&&i<B) V.push_back({i,B});
		if(B-1-i>0) V.push_back({B-1-i,B});
		if(i&&i<C) V.push_back({i,C});
		if(C-1-i>0) V.push_back({C-1-i,C});
	}
	sort(ALL(V),cmp);
	V.erase(unique(ALL(V)),V.end());
	
	ll ret=min(D+1,A)*min(D+1,B)%mo*min(D+1,C)%mo;
	ll a[3]={};
	FORR(v,V) {
		ll b[3]={a[0],a[1],a[2]};
		FOR(i,3) 
		a[0]=v.first*A/v.second;
		a[1]=v.first*B/v.second;
		a[2]=v.first*C/v.second;
		
		ll dx=min(A-1,b[0]+D)-max(0LL,b[0]-D)+1;
		ll dy=min(B-1,b[1]+D)-max(0LL,b[1]-D)+1;
		ll dz=min(C-1,b[2]+D)-max(0LL,b[2]-D)+1;
		
		if(a[0]+D<A) ret+=(a[0]-b[0])*dy%mo*dz%mo;
		if(a[1]+D<B) ret+=(a[1]-b[1])*dx%mo*dz%mo;
		if(a[2]+D<C) ret+=(a[2]-b[2])*dy%mo*dx%mo;
		ret%=mo;
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
