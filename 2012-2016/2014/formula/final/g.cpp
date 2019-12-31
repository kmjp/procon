#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
deque<int> D[3];
vector<pair<int,int> > R;

void dodo(int l,int r,int p) {
	bool same,rev;
	int i,n,S,sp;
	
	if(l>=r) return;
	S=D[p].size();
	sp=r-l;
	same=(D[p][S-sp]==l);
	rev=(D[p][S-sp]==r-1);
	FOR(i,r-l-1) {
		if(D[p][S-sp+i]+1!=D[p][S-sp+i+1]) same=false;
		if(D[p][S-sp+i]-1!=D[p][S-sp+i+1]) rev=false;
	}
	
	if(same) {
		FOR(i,r-l) D[p].pop_back();
		if(p!=0) {
			n=3-p;
			FOR(i,r-l) R.push_back(make_pair(p,n));
			FOR(i,r-l) R.push_back(make_pair(n,0));
		}
		return;
	}
	if(rev) {
		FOR(i,r-l) D[p].pop_back();
		if(p!=0) {
			FOR(i,r-l) R.push_back(make_pair(p,0));
		}
		else {
			FOR(i,r-l) R.push_back(make_pair(0,1));
			FOR(i,r-l) R.push_back(make_pair(1,2));
			FOR(i,r-l) R.push_back(make_pair(2,0));
		}
		return;
	}
	
	int sm,la;
	if(p==0) sm=1,la=2;
	if(p==1) sm=0,la=2;
	if(p==2) sm=0,la=1;
	FOR(i,r-l) {
		int v=D[p].back();
		D[p].pop_back();
		if(v<(r+l)/2) D[sm].push_back(v), R.push_back(make_pair(p,sm));
		else D[la].push_back(v), R.push_back(make_pair(p,la));
	}
	dodo(l,(r+l)/2,sm);
	dodo((r+l)/2,r,la);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>x, D[0].push_back(N-x);
	dodo(0,N,0);
	
	_P("%d\n",R.size());
	FOR(i,R.size()) _P("%d %d\n",R[i].first+1,R[i].second+1);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
