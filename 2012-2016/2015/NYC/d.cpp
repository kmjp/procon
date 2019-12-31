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

int N,Q;
int A[400];
int mi[20002];
set<int> S;
vector<int> V;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(x,N) FOR(y,N) S.insert(2*(A[x]-A[y]));
	ITR(it,S) if(*it) V.push_back(*it);
	
	FOR(x,20001) mi[x]=1000000;
	mi[0]=0;
	queue<int> q;
	q.push(0);
	while(q.size()) {
		int k=q.front();
		q.pop();
		ITR(it,V) {
			x=k+*it;
			if(x>20000) break;
			if(x>=0 && mi[x]>mi[k]+2) mi[x]=mi[k]+2, q.push(x);
		}
	}
	
	cin>>Q;
	while(Q--) {
		cin>>x>>y;
		if(x>y) swap(x,y);
		
		if((y-x)%2) {
			_P("-1\n");
			continue;
		}
		int m=mi[y-x];
		FOR(i,N) {
			j=2*A[i]-x;
			m=min(m,1+mi[abs(y-j)]);
		}
		if(m>=100000) m=-1;
		_P("%d\n",m);
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
