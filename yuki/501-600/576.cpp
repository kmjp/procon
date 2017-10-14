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

int N,K;
string S;
double B[1010101];

int ok(double v) {
	int i;
	FOR(i,N) B[i+1]=B[i]+S[i]-v;
	
	deque<pair<double,int>> D;
	for(i=1;i<=N/2;i++) {
		while(D.size() && D.back().first<B[i]) D.pop_back();
		D.push_back({B[i],i});
	}
	FOR(i,N/2) {
		while(D.size() && D.front().second<=i+K-1) D.pop_front();
		if(D.front().first>=B[i]) return 1;
		while(D.size() && D.back().first<B[i+N/2+1]) D.pop_back();
		D.push_back({B[i+N/2+1],i+N/2+1});
	}
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>S;
	int NB=0;
	
	N+=N;
	S+=S;
	FOR(i,N) {
		S[i]-='0';
	}
	
	double L=0,R=1;
	FOR(i,60) {
		double M=(L+R)/2;
		if(ok(M)) L=M;
		else R=M;
	}
	
	_P("%.12lf\n",(L+R)/2);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
