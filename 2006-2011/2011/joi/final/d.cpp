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
ll X[101010];
ll Y[101010];
ll Xs[101010];
ll Ys[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>x>>y;
	cin>>N;
	
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		Xs[i]=X[i];
		Ys[i]=Y[i];
	}
	sort(Xs,Xs+N);
	sort(Ys,Ys+N);
	
	ll L,R,U,D;
	if(N%2==0) {
		L=Xs[N/2-1];
		R=Xs[N/2];
		U=Ys[N/2-1];
		D=Ys[N/2];
	}
	else {
		L=R=Xs[N/2];
		U=D=Ys[N/2];
	}
	
	ll tot=0;
	FOR(i,N) tot+=abs(L-X[i])+abs(U-Y[i]);
	tot*=2;
	
	ll best=-1;
	ll bx,by;
	
	FOR(i,N) {
		if(X[i]<=L) x=R;
		else x=L;
		if(Y[i]<=U) y=D;
		else y=U;
		ll d=abs(X[i]-x)+abs(Y[i]-y);
		
		if(d==best) {
			if(x<bx || (x==bx&&y<by)) {
				bx=x;
				by=y;
			}
		}
		if(d>best) {
			best=d;
			bx=x;
			by=y;
		}
	}
	cout<<tot-best<<endl;
	cout<<bx<<" "<<by<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
