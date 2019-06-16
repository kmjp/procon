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
vector<ll> R,L,U,D,X,Y;
vector<ll> cand;

void hoge(vector<ll>& V) {
	if(V.size()) {
		sort(ALL(V));
		int x=V[0];
		int y=V.back();
		V.clear();
		V={x,y};
		
	}
}

void hogev(vector<ll>& A,vector<ll>& B,int d) {
	if(A.size()&&B.size()) {
		cand.push_back(abs(A[0]-B[0])/d);
		cand.push_back(abs(A[0]-B[1])/d);
		cand.push_back(abs(A[1]-B[0])/d);
		cand.push_back(abs(A[1]-B[1])/d);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	FOR(i,N) {
		cin>>x>>y>>s;
		x*=2;
		y*=2;
		if(s=="L") {
			L.push_back(x);
			Y.push_back(y);
		}
		if(s=="R") {
			R.push_back(x);
			Y.push_back(y);
		}
		
		if(s=="U") {
			U.push_back(y);
			X.push_back(x);
		}
		if(s=="D") {
			D.push_back(y);
			X.push_back(x);
		}
	}
	hoge(L);
	hoge(R);
	hoge(U);
	hoge(D);
	hoge(X);
	hoge(Y);
	
	cand.push_back(0);
	cand.push_back(1<<30);
	
	hogev(L,X,1);
	hogev(R,X,1);
	hogev(L,R,2);
	hogev(U,Y,1);
	hogev(D,Y,1);
	hogev(U,D,2);
	ll ret=1LL<<60;
	FORR(c,cand) {
		ll x1=1LL<<40,x2=-1LL<<40;
		ll y1=1LL<<40,y2=-1LL<<40;
		if(L.size()) x1=min(x1,L[0]-c),x2=max(x2,L[1]-c);
		if(R.size()) x1=min(x1,R[0]+c),x2=max(x2,R[1]+c);
		if(X.size()) x1=min(x1,X[0]+0),x2=max(x2,X[1]+0);
		if(U.size()) y1=min(y1,U[0]+c),y2=max(y2,U[1]+c);
		if(D.size()) y1=min(y1,D[0]-c),y2=max(y2,D[1]-c);
		if(Y.size()) y1=min(y1,Y[0]+0),y2=max(y2,Y[1]+0);
		ret=min(ret,(x2-x1)*(y2-y1));
	}
	
	_P("%.12lf\n",ret/4.0);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
