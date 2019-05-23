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
ll X,S;
ll A[1010101];
ll R[1010101];

bool cmp(vector<ll> L,vector<ll> R) {
	__int128_t A=__int128_t(L[0])*R[1];
	__int128_t B=__int128_t(L[1])*R[0];
	
	if(A>B) return 1;
	if(A<B) return 0;
	return L[2]>R[2];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X;
	FOR(i,N) cin>>A[i], S+=A[i];
	
	
	vector<vector<ll>> V;
	FOR(i,N) {
		ll num=X*A[i]/S;
		V.push_back({1,A[i],i,num});
		V.push_back({abs(num*S-X*A[i])-abs((num+1)*S-X*A[i]),A[i]*S,i,1});
		V.push_back({-1,A[i],i,1LL<<30});
	}
	sort(ALL(V),cmp);
	
	FORR(v,V) {
		ll num=min(X,v[3]);
		//cout<<v[2]<<" "<<num<<" "<<v[0]<<"/"<<v[1]<<endl;
		X-=num;
		R[v[2]]+=num;
	}
	
	FOR(i,N) cout<<R[i]<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
