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
ll P,Q;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>C>>D;
	cin>>P>>Q;
	ll ma_x,ma_y=-1LL<<60;
	ll mi_x,mi_y=1LL<<60;
	for(ll a=P;a<=Q;a++) {
		ll F=a*a*a*A+a*a*B+a*C+D;
		if(F>ma_y) ma_y=F, ma_x=a;
		if(F<mi_y) mi_y=F, mi_x=a;
	}
	
	cout<<ma_y<<" "<<ma_x<<" "<<mi_y<<" "<<mi_x<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
