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

ll T[2];
ll A[2],B[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T[0]>>T[1];
	cin>>A[0]>>A[1];
	cin>>B[0]>>B[1];
	
	ll X=T[0]*A[0]+T[1]*A[1];
	ll Y=T[0]*B[0]+T[1]*B[1];
	
	if(X==Y) {
		cout<<"infinity"<<endl;
		return;
	}
	
	if(A[0]>B[0] && X>Y) return _P("0\n");
	if(A[0]<B[0] && X<Y) return _P("0\n");
	
	ll P=abs(A[0]-B[0]);
	ll D=abs(X-Y);
	ll Z=P*T[0];
	if(Z%D==0) {
		cout<<Z/D*2<<endl;
	}
	else {
		cout<<1+Z/D*2<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
