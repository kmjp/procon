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

int T,N;
vector<int> E[303030];
int D[303030],S[303030];
int ND[303030];
ll ret;

int dfs(int cur,int pre,int d) {
	D[cur]=d;
	ND[d]++;
	S[cur]=1;
	FORR(e,E[cur]) if(e!=pre) {
		int a=dfs(e,cur,d+1);
		ret-=1LL*(2*d+1)*(S[cur]-1)*a;
		S[cur]+=a;
	}
	return S[cur];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N+3) {
			E[i].clear();
			ND[i]=D[i]=S[i]=0;
		}
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		ret=0;
		dfs(0,0,0);
		for(i=N+1;i>=0;i--) {
			ret+=1LL*i*ND[i]*(ND[i]-1);
			ND[i]+=ND[i+1];
		}
		FOR(i,N) {
			ret+=2LL*D[i]*(ND[D[i]+1]-(S[i]-1));
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
