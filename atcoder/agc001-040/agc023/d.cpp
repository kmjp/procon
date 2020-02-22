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
 
 
int N,S,M;
int X[101010];
ll P[101010];
ll ret;

void dfs(int L,int R,int pre) {
	if(L==M) {
		ret+=X[R]-X[M];
		if(pre>=0) ret+=abs(X[R]-X[pre]);
		return;
	}
	if(R==M) {
		ret+=X[M]-X[L];
		if(pre>=0) ret+=abs(X[L]-X[pre]);
		return;
	}
	if(P[L]>=P[R]) {
		P[L]+=P[R];
		if(pre>=0) ret+=abs(X[pre]-X[R]);
		dfs(L,R-1,R);
	}
	else {
		P[R]+=P[L];
		if(pre>=0) ret+=abs(X[pre]-X[L]);
		dfs(L+1,R,L);
		
	}
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	int first=1;
	FOR(i,N) {
		cin>>X[i]>>P[i];
		if(first&&X[i]>S) {
			first=0;
			M=i;
			N++;
			X[i+1]=X[i];
			P[i+1]=P[i];
			X[i]=S;
			P[i]=0;
			i++;
		}
	}
	if(first) X[N]=S,P[N]=0,N++;
	dfs(0,N-1,-1);
	
	cout<<ret<<endl;
	
}
 
 
int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
