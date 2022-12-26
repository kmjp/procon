#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int A[100010];
vector<int> divs[10001];
set<pair<int,int> > S[10001];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		for(j=1;j*j<=A[i];j++) if(A[i]%j==0) {
			S[j].insert(make_pair(A[i],i));
			S[A[i]/j].insert(make_pair(A[i],i));
			divs[i].push_back(j);
			if(j*j!=A[i]) divs[i].push_back(A[i]/j);
		}
	}
	
	int id=0;
	FOR(i,N-1) {
		_P("%d ",A[id]);
		
		r=1<<30;
		ITR(it,divs[id]) {
			S[*it].erase(make_pair(A[id],id));
			if(S[*it].empty()) continue;
			pair<int,int> p=*S[*it].begin();
			y=p.first*A[id]/__gcd(p.first,A[id]);
			if(y<r || (y==r && p.first<A[x])) x=p.second, r=y;
		}
		id = x;
	}
	_P("%d\n",A[id]);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
