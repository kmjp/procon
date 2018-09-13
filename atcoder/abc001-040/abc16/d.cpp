#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll X[2],Y[2];
int N;
ll TX[150],TY[150];

int cross(ll xx1,ll yy1,ll xx2,ll yy2) {
	
	ll x1=xx1-X[0];
	ll x2=xx2-X[0];
	ll y1=yy1-Y[0];
	ll y2=yy2-Y[0];
	ll x3=X[1]-X[0];
	ll y3=Y[1]-Y[0];
	if((y3*x1-x3*y1)*(y3*x2-x3*y2)>=0) return 0;
	
	x1=X[0]-xx1;
	x2=X[1]-xx1;
	x3=xx2-xx1;
	y1=Y[0]-yy1;
	y2=Y[1]-yy1;
	y3=yy2-yy1;
	
	return (y3*x1-x3*y1)*(y3*x2-x3*y2)<0;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X[0]>>Y[0]>>X[1]>>Y[1];
	cin>>N;
	FOR(i,N) cin>>TX[i]>>TY[i];
	j=0;
	FOR(i,N) j+=cross(TX[i],TY[i],TX[(i+1)%N],TY[(i+1)%N]);
	
	cout<<1+j/2<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
