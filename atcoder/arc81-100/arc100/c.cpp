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
int A[202020];

ll hoge(ll a) {
	ll tot=0;
	int i;
	FOR(i,N) tot+=abs(A[i]-(a+i));
	return tot;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	
	ll L=-1LL<<40,R=1LL<<40;
	while(R-L>=4) {
		ll m1=(2*L+R)/3;
		ll m2=(L+2*R)/3;
		
		ll v1=hoge(m1);
		ll v2=hoge(m2);
		if(v1==v2) L=m1,R=m2;
		else if(v1<v2) R=m2;
		else L=m1;
	}
	
	ll ret=1LL<<60;
	for(ll a=L;a<=R;a++) ret=min(ret,hoge(a));
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
