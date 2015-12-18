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

int X1,X2,Y1,Y2,D;

ll hoge(ll x1,ll x2,ll y1,ll y2,ll D) {
	if(x1+y1>D) return 0;
	if(x2+y2<=D) return (y2-y1+1)*(x2-x1+1);
	
	D-=x1+y1;
	x2-=x1;
	y2-=y1;
	
	ll ret=0;
	if(D>y2) {
		ret=(D-y2)*(y2+1);
		x2 -= D-y2;
		D=y2;
	}
	x2=min(x2,D);
	return ret+(D+1+(D+1-x2))*(x2+1)/2;
}

ll range(ll a,ll b,ll D) {
	ll l=-D,r=D;
	l=max(a,-D);
	r=min(b,D);
	if(r<l) return 0;
	return (r-l)+1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X1>>Y1>>X2>>Y2>>D;
	
	ll ret=0;
	if(X2<0) X1=-X1,X2=-X2,swap(X1,X2);
	if(Y2<0) Y1=-Y1,Y2=-Y2,swap(Y1,Y2);
	
	ret += hoge(max(1,X1),X2,max(1,Y1),Y2,D);
	if(X1<0) ret += hoge(1,-X1,max(1,Y1),Y2,D);
	if(Y1<0) ret += hoge(max(1,X1),X2,1,-Y1,D);
	if(X1<0 && Y1<0) ret += hoge(1,-X1,1,-Y1,D);
	
	if(X1<=0) ret+=range(Y1,Y2,D);
	if(Y1<=0) ret+=range(X1,X2,D);
	if(X1<=0 && Y1<=0) ret--;
	
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
