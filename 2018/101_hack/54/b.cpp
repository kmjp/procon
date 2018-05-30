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

int N;
ll X[202020];
ll W,V;
int Q;

double hoge(int c,pair<ll,ll> a) {
	
	__int128 p1=X[c];
	__int128 q1=V;
	__int128 p2=a.first;
	__int128 q2=a.second;
	// p1/q1>=p2/q2
	
	double now=1.0*p1/q1;
	__int128 x=p2*q1-p1*q2;
	__int128 y=q1*q2*W;
	if(x>0) {
		if(x%y==0) {
			now += (x/y)*W;
		}
		else {
			now += (x/y+1)*W;
		}
	}
	return now+1.0*(X[N-1]-X[c])/V;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>X[i];
	cin>>W>>V;
	cin>>Q;
	FOR(i,Q) {
		ll P,T,U;
		cin>>P>>T>>U;
		double ret=T+(X[N-1]-P)*1.0/U;
		
		x=lower_bound(X,X+N,P)-X;
		ret=min(ret,hoge(x,{T*U+abs(X[x]-P),U}));
		if(x) ret=min(ret,hoge(x-1,{T*U+abs(X[x-1]-P),U}));
		
		_P("%.12lf\n",ret);
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
