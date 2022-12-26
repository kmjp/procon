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
ll A[202020],SA[202020];
map<ll,ll> M,L,R;
ll ret;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	M[0]=1;
	R[0]=0;
	FOR(i,N) {
		cin>>A[i];
		SA[i+1]=SA[i]+A[i];
		ret+=M[SA[i+1]];
		M[SA[i+1]]++;
		L[SA[i+1]]=0;
		R[SA[i+1]]++;
	}
	L[0]=1;
	
	ll cur=0;
	FORR(m,L) cur+=m.second*R[m.first];
	
	ll ma=cur;
	FOR(i,N-1) {
		ll a=SA[i+1];
		cur-=L[a]*R[a];
		L[a]++;
		R[a]--;
		cur+=L[a]*R[a];
		ma=max(ma,cur);
	}
	
	cout<<ret-ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
