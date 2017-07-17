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
int A[10101];

int hoge(int m,int v) {
	vector<pair<int,int>> X,Y;
	X.push_back({-1,0});
	Y.push_back({-1,0});
	int i;
	FOR(i,m) {
		if(X.back().first!=A[i]) X.push_back({A[i],0});
		X.back().second++;
	}
	if(X.back().first!=v) X.push_back({v,0});
	X.back().second++;
	
	for(i=N-1;i>m;i--) {
		if(Y.back().first!=A[i]) Y.push_back({A[i],0});
		Y.back().second++;
	}
	int ret=N;
	while(X.back().first==Y.back().first && X.back().second+Y.back().second>=4) {
		ret -= X.back().second+Y.back().second;
		X.pop_back();
		Y.pop_back();
	}
	return ret;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	int mi=N;
	FOR(i,N) {
		mi=min(mi,hoge(i,1));
		mi=min(mi,hoge(i,2));
		mi=min(mi,hoge(i,3));
	}
	
	cout<<mi<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
