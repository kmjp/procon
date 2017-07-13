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

ll A[4];

ll hoge(ll a,ll x,ll y,ll z) {
	ll B[3]={x,y,z};
	sort(B,B+3);
	a+=B[0]*2;
	
	B[2]-=B[0];
	B[1]-=B[0];
	B[0]-=B[0];
	
	ll X=B[1]*1/3;
	a-=X;
	a+=4*X;
	B[1]-=X*3;
	B[2]-=X*3;
	
	if(B[1]==2) a++;
	return a;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,4) cin>>A[i];
	
	ll ma=0;
	ma=max(ma,hoge(A[0],A[1],A[2],A[3]));
	ma=max(ma,hoge(A[1],A[0],A[2],A[3]));
	ma=max(ma,hoge(A[2],A[0],A[1],A[3]));
	ma=max(ma,hoge(A[3],A[0],A[1],A[2]));
	
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
