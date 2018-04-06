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
ll X[101010],Y[101010];
ll SX[101010],SY[101010];
ll XS[101010],YS[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		SX[i]=X[i]+Y[i];
		SY[i]=X[i]-Y[i];
	}
	sort(SX,SX+N);
	sort(SY,SY+N);
	FOR(i,N) XS[i+1]=XS[i]+SX[i];
	FOR(i,N) YS[i+1]=YS[i]+SY[i];
	
	FOR(i,Q) {
		cin>>x>>y;
		ll QX=x+y;
		ll QY=x-y;
		
		ll ret=0;
		x=lower_bound(SX,SX+N,QX)-SX;
		y=lower_bound(SY,SY+N,QY)-SY;
		ret+=(QX*x-XS[x]) + (XS[N]-XS[x]-QX*(N-x));
		ret+=(QY*y-YS[y]) + (YS[N]-YS[y]-QY*(N-y));
		cout<<ret/2<<endl;
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
