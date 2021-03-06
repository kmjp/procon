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

int ma[101010];
int ret[101010];
vector<int> E[101010];
int N,M,Q;
int A[101010],B[101010],C[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	cin>>Q;
	FOR(i,Q) {
		cin>>A[Q-1-i]>>B[Q-1-i]>>C[Q-1-i];
		A[Q-1-i]--;
	}
	MINUS(ma);
	
	FOR(i,Q) {
		if(B[i]<=ma[A[i]]) continue;
		
		queue<int> Q;
		if(ma[A[i]]==-1) ret[A[i]]=C[i];
		ma[A[i]]=B[i];
		Q.push(A[i]);
		
		while(Q.size()) {
			x=Q.front();
			Q.pop();
			FORR(r,E[x]) if(ma[r]<ma[x]-1) {
				if(ma[r]==-1) ret[r]=C[i];
				ma[r]=ma[x]-1;
				if(ma[r]>0) Q.push(r);
			}
		}
	}
	FOR(i,N) cout<<ret[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
