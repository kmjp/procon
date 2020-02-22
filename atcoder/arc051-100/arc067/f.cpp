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

int N,M;
ll A[5050];
int B[5050][202];
ll ret;

int more[5050][202];
ll add[5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&M);
	FOR(i,N-1) {
		scanf("%d",&x);
		A[i+1]=A[i]+x;
	}
	
	FOR(y,N) FOR(x,M) scanf("%d",&B[y][x]);
	FOR(x,M) {
		stack<pair<int,int>> S;
		B[N][x]=1<<30;
		S.push({1<<30,N});
		more[N][x]=N;
		for(y=N-1;y>=0;y--) {
			while(S.top().first<B[y][x]) S.pop();
			more[y][x]=S.top().second;
			S.push({B[y][x],y});
		}
		
		y=0;
		while(y<N) {
			add[more[y][x]]+=B[more[y][x]][x]-B[y][x];
			y=more[y][x];
		}
	}
	
	FOR(y,N) {
		ll cur=0;
		FOR(x,M) cur+=B[y][x];
		ret=max(ret,cur);
		for(int z=y+1;z<N;z++) {
			cur+=add[z];
			ret=max(ret,cur-(A[z]-A[y]));
		}
		
		FOR(x,M) {
			j=more[y][x];
			add[j]-=B[j][x]-B[y][x];
			i=y+1;
			while(i<j) {
				add[more[i][x]]+=B[more[i][x]][x]-B[i][x];
				i=more[i][x];
			}
		}
		
	}
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
