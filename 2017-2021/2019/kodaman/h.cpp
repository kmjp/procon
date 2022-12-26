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

int N,X;
int V[101010];
int T[101010];
int did[101010];

int ok(int v) {
	ZERO(did);
	int i;
	queue<int> Q;
	FOR(i,N) {
		T[i]=V[i];
		if(i==0 || i==N-1) T[i]-=X;
		if(T[i]<=v) Q.push(i);
	}
	
	int num=0;
	while(Q.size()) {
		int x=Q.front();
		Q.pop();
		if(did[x]) continue;
		num++;
		did[x]=1;
		if(x) {
			T[x-1]-=X;
			if(T[x-1]<=v) Q.push(x-1);
		}
		if(x+1<N) {
			T[x+1]-=X;
			if(T[x+1]<=v) Q.push(x+1);
		}
		
	}
	return num==N;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X;
	FOR(i,N) {
		cin>>V[i];
	}
	
	int mi=(1<<30)-1;
	for(i=29;i>=0;i--) if(ok(mi-(1<<i))) mi-=1<<i;
	cout<<mi<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
