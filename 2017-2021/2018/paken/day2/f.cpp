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

ll K;
vector<int> E[151];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K;
	
	int cur=2;
	vector<int> C[32];
	FOR(i,30) {
		FOR(j,4) {
			if(i==29&&j==3) break;
			C[i].push_back(cur++);
		}
	}
	FORR(c,C[0]) E[1].push_back(c);
	FOR(i,29) {
		FORR(c,C[i]) FORR(d,C[i+1]) E[c].push_back(d);
	}
	
	for(i=1;i<=30;i++) C[i].push_back(cur++);
	for(i=1;i<=29;i++) E[C[i].back()].push_back(C[i+1].back());
	for(i=29;i>=0;i--) {
		FORR(c,C[i]) {
			if(i&&c==C[i].back()) continue;
			if(K>=1LL<<(2*i)) {
				K-=1LL<<(2*i);
				E[c].push_back(C[i+1].back());
			}
		}
	}
	int num=0;
	FOR(i,151) num+=E[i].size();
	cout<<cur-1<<" "<<num<<endl;
	FOR(i,151) FORR(e,E[i]) cout<<i<<" "<<e<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
