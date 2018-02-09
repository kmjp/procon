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
int A[10101],B[10101];
int M;
int X[10101],Y[10101];
map<int,vector<int>> P;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i]>>B[i];
	cin>>M;
	FOR(i,M) {
		cin>>x>>y;
		int cnt=0;
		FOR(j,N) {
			if(x<=A[j] && y>=B[j]) cnt++;
		}
		P[cnt].push_back(i+1);
	}
	
	auto a=P.rbegin()->second;
	if(P.rbegin()->first==0) {
		cout<<0<<endl;
	}
	else {
		FORR(v,a) cout<<v<<endl;
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
