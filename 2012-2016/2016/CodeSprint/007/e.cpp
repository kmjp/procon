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

int N,D;
int A[1<<20];
int B[1<<20];
priority_queue<int> L[20];
map<int,int> M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	while(2<<D<=N) D++;
	FOR(i,2*N-1) cin>>x, M[x]++;
	
	if(M.size()!=N) return _P("NO\n");
	
	L[D].push(0);
	
	FORR(r,M) {
		int T=r.first;
		int num=r.second;
		
		if(num>D+1) return _P("NO\n");
		if(L[num-1].size()==0) return _P("NO\n");
		
		x = -L[num-1].top();
		L[num-1].pop();
		while(num>0) {
			B[x]=T;
			if(num-1>0) L[num-2].push(-(x*2+2));
			x=x*2+1;
			num--;
		}
	}
	
	_P("YES\n");
	FOR(i,2*N-1) _P("%d%c",B[i],(i==2*N-2)?'\n':' ');
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
