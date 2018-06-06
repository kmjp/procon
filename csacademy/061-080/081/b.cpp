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

ll A1,L1,A2,L2;
ll C,X,Y;

int win(ll a1,ll l1, ll a2,ll l2) {
	return (l2+a1-1)/a1 <= (l1+a2-1)/a2;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A1>>L1>>A2>>L2;
	cin>>C>>X>>Y;
	
	for(i=0;i<=C;i++) {
		if(win(A1+i*X,L1+(C-i)*Y,A2,L2)) return _P("1\n");
	}
	_P("0\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
