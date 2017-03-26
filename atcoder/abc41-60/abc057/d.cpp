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

int N,A,B;
ll V[1010];

ll ma[51][51];
ll num[51][51];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>B;
	FOR(i,N) cin>>V[i];
	MINUS(ma);
	ma[0][0]=0;
	num[0][0]=1;
	
	FOR(i,N) {
		FOR(x,N) if(num[i][x]>0) {
			
			// take
			if(ma[i+1][x+1] < ma[i][x]+V[i]) ma[i+1][x+1] = ma[i][x]+V[i], num[i+1][x+1]=0;
			if(ma[i+1][x+1] == ma[i][x]+V[i]) num[i+1][x+1] += num[i][x];
			// not take
			if(ma[i+1][x] < ma[i][x]) ma[i+1][x] = ma[i][x], num[i+1][x]=0;
			if(ma[i+1][x] == ma[i][x]) num[i+1][x] += num[i][x];
		}
	}
	
	ll p=0,q=1;
	ll ret=0;
	for(i=A;i<=B;i++) {
		if(q*ma[N][i] > p*i) p=ma[N][i], q=i, ret=0;
		if(q*ma[N][i] == p*i) ret += num[N][i];
	}
	_P("%.12lf %lld\n",(double)p/q, ret);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
