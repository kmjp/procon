#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
int X[101000];
vector<int> E[201000],RE[201000];
int col[202000];
int numb[202000];

bool ok(int v) {
	int i;
	
	MINUS(col);
	ZERO(numb);
	queue<int> Q;
	FOR(i,N) {
		if(X[i]>=v) col[i]=1, Q.push(i);
		else col[100000+i]=1, Q.push(100000+i);
		
		if(E[i].empty()) {
			if(col[i]==-1) col[i]=0, Q.push(i);
			if(col[100000+i]==-1) col[100000+i]=0, Q.push(100000+i);
		}
	}
	
	while(Q.size()) {
		int cur=Q.front();
		Q.pop();
		
		if(col[cur]==0) { // white
			FORR(r,RE[cur]) if(col[r]==-1) col[r]=1, Q.push(r);
		}
		else { // black
			FORR(r,RE[cur]) if(col[r]==-1 && ++numb[r] == E[r].size()) col[r]=0, Q.push(r);
		}
	}
	
	return col[0]==1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>X[i];
	while(M--) {
		cin>>x>>y;
		x--,y--;
		E[x].push_back(100000+y);
		RE[100000+y].push_back(x);
		E[100000+x].push_back(y);
		RE[y].push_back(100000+x);
	}
	
	x=1;
	for(i=29;i>=0;i--) if(ok(x+(1<<i))) x+=1<<i;
	cout<<x<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
