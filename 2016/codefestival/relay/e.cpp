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

ll X1,Y1,X2,Y2,X,Y;

ll go(ll a,ll b) {
	if(a<b) swap(a,b);
	ll g=__gcd(a,b);
	a/=g;
	b/=g;
	return g*(a+b-1);
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X1>>Y1>>X2>>Y2;
	X=abs(X2-X1);
	Y=abs(Y2-Y1);
	cout<<go(X,Y)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
