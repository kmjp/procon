#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int T,N,A[202020];
int inloop[202020];
int vis[202020];

int in[202020];
int num[202020];
int F[202020];

int dfs(int cur,int from) {
	if(cur<0||cur>=N) return 0;
	if(vis[cur]) {
		if(vis[cur]==1) return inloop[cur];
		inloop[cur]=1;
		return 1;
	}
	F[cur]=from;
	vis[cur]=2;
	inloop[cur]=dfs(A[cur],from);
	vis[cur]=1;
	return inloop[cur];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			cin>>x;
			A[i]=i+x;
			vis[i]=inloop[i]=0;
			in[i]=0;
			num[i]=1;
		}
		
		FOR(i,N) if(vis[i]==0) dfs(i,i);
		
		FOR(i,N) if(A[i]>=0&&A[i]<N) {
			in[A[i]]++;
		}
		queue<int> Q;
		FOR(i,N) if(in[i]==0) Q.push(i);
		while(Q.size()) {
			x=Q.front();
			Q.pop();
			y=A[x];
			if(y>=0&&y<N) {
				in[y]--;
				num[y]+=num[x];
				if(in[y]==0) Q.push(y);
			}
		}
		int tloop=0;
		FOR(i,N) tloop+=inloop[i];
		
		ll ret=0;
		if(inloop[0]) {
			FOR(i,N) if(F[i]==0) {
				ret+=(2*N+1-tloop);
			}
		}
		else {
			ret=1LL*N*(2*N+1);
			FOR(i,N) if(F[i]==0) {
				ret-=tloop+num[i];
			}
		}
		cout<<ret<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
