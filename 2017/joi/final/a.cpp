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
ll S,T;
ll D[202020];
ll L,R,X;

ll sc(ll dif) {
	if(dif<0) return -dif*T;
	return -dif*S;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q>>S>>T;
	ll pre=0;
	ll tot=0;
	FOR(i,N+1) {
		cin>>D[i];
		D[i]-=pre;
		tot+=sc(D[i]);
		pre=D[i]+pre;
	}
	FOR(i,Q) {
		cin>>L>>R>>X;
		tot-=sc(D[L]);
		D[L]+=X;
		tot+=sc(D[L]);
		if(R<N) {
			tot-=sc(D[R+1]);
			D[R+1]-=X;
			tot+=sc(D[R+1]);
		}
		cout<<tot<<endl;
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
