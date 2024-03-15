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

int T;
int N,K,A[202020];
vector<int> E[202020];
vector<int> C;
vector<int> M[40];
map<int,int> re;
int num[202020][40];

void dfs(int cur,int pre) {
	int i,x;
	FOR(i,C.size()) num[cur][i]=1<<20;
	int c=0;
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		c++;
	}
	if(c==0) {
		num[cur][re[__gcd(A[0],A[cur]*A[cur])]]=1;
		num[cur][re[A[cur]]]=0;
	}
	else {
		FOR(i,C.size()) {
			int s=0;
			FORR(e,E[cur]) if(e!=pre) s=min(1<<20,s+num[e][i]);
			int v=__gcd(C[i],A[cur]);
			chmin(num[cur][re[v]],s);
			if(cur) chmin(num[cur][re[__gcd(A[0],v*v)]],s+1);
		}
	}
	
	FOR(x,C.size()) {
		FORR(d,M[x]) num[cur][x]=min(num[cur][x],num[cur][d]);
	}
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		FOR(i,N) {
			cin>>A[i];
			A[i]=__gcd(A[i],A[0]);
			E[i].clear();
		}
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		C.clear();
		re.clear();
		for(i=1;i<=A[0];i++) if(A[0]%i==0) C.push_back(i);
		FOR(x,C.size()) {
			re[C[x]]=x;
			M[x].clear();
			for(y=x+1;y<C.size();y++) if(C[y]%C[x]==0) M[x].push_back(y);
		}
		dfs(0,0);
		int ma=A[0];
		FOR(x,C.size()) if(num[0][x]<K) ma=max(ma,C[x]*A[0]);
		cout<<ma<<endl;
	}
			
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
