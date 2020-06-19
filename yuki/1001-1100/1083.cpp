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

int N,K,A[20];
set<int> S[1<<20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>A[i];
	S[0].insert(K);
	int mask;
	FOR(mask,1<<N) {
		FORR(s,S[mask]) {
			int nmask=mask;
			FOR(i,N) if(s<A[i]) nmask|=1<<i;
			if(nmask!=mask) {
				S[nmask].insert(s);
			}
			else {
				FOR(i,N) if((mask&(1<<i))==0) {
					S[mask|(1<<i)].insert(s%A[i]);
				}
			}
		}
	}
	auto it=S[(1<<N)-1].end();
	cout<<*prev(it)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
