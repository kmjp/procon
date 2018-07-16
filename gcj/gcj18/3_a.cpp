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

int T,testcase;
int N;

int ok(vector<int> X, ll v) {
	ll L=-1LL<<60,R=1LL<<60;
	
	FORR(x,X) {
		L=max(L,x-v);
		R=min(R,x+v);
	}
	return L<=R;
}

int hoge(vector<int> V) {
	ll ret=(1LL<<60)-1;
	int i;
	for(i=59;i>=0;i--) if(ok(V,ret-(1LL<<i))) ret-=(1LL<<i);
	return ret;
}

void solve(int TC) {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<int> X,Y;
	FOR(i,N) {
		cin>>x>>y;
		X.push_back(x);
		Y.push_back(y);
	}
	
	int mi=max(hoge(X),hoge(Y));
	
	
	
	_P("Case #%d: %d\n",TC, mi);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0);
	
	cin>>T;
	for(testcase=1;testcase<=T;testcase++) solve(testcase);
	return 0;
}
