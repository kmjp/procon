#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


int N;
int A[101],B[101];
int T[202];
int isf;

int memo[202][202];

void dfs(int cur,int f) {
	if(cur==2*N) {
		cout<<"Yes"<<endl;
		exit(0);
	}
	if(memo[cur][f]==0) return;
	memo[cur][f]=0;
	
	int len;
	for(len=1;cur+len*2<=2*N;len++) {
		int cf=f;
		int x;
		for(x=cur;x<cur+len;x++) {
			if(T[x]>=N) break;
			if(T[x+len]>=0&&T[x+len]<N) break;
			if(T[x]>=0&&T[x+len]>=0&&T[x+len]!=T[x]+N) break;
			
			if(T[x]==-1&&T[x+len]==-1) cf--;
		}
		if(x==cur+len&&cf>=0) dfs(cur+len*2,cf);
	}
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N;
	MINUS(T);
	MINUS(memo);
	FOR(i,N) {
		cin>>A[i]>>B[i];
		if(A[i]>=0) {
			A[i]--;
			if(T[A[i]]!=-1) return _P("No\n");
			T[A[i]]=i;
		}
		if(B[i]>=0) {
			B[i]--;
			if(T[B[i]]!=-1) return _P("No\n");
			T[B[i]]=i+N;
		}
		if(A[i]>=0&&B[i]>=0&&A[i]>=B[i]) return _P("No\n");
		if(A[i]==-1&&B[i]==-1) isf++;
	}
	
	
	dfs(0,isf);
	cout<<"No"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
