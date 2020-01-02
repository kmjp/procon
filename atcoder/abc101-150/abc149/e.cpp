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
ll M;
ll A[101010],S[202020];

ll num(ll v) {
	ll tot=0;
	int i;
	FOR(i,N) {
		tot+=N-(lower_bound(A,A+N,v-A[i])-A);
	}
	return tot;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>A[i];
	}
	sort(A,A+N);
	FOR(i,N) S[i+1]=S[i]+A[N-1-i];
	
	ll mi=0;
	for(i=40;i>=0;i--) if(num(mi+(1LL<<i))>=M) mi+=1LL<<i;
	
	ll num=0;
	ll ret=0;
	FOR(i,N) {
		x=N-(lower_bound(A,A+N,mi-A[i])-A);
		num+=x;
		ret+=A[i]*x+S[x];
		
	}
	ret-=(num-M)*mi;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
