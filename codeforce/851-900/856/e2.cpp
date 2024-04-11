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


int N;
int C[202020];
vector<int> E[202020];

ll mo;
ll dp[202020];
int ok[202020];
map<ll,vector<int>> cand;
ll p2[202020];
int B=135;

ll dfs1(int cur,int pre) {
	dp[cur]=1;
	FORR(e,E[cur]) if(e!=pre) {
		(dp[cur]+=B*dfs1(e,cur))%=mo;
	}
	return dp[cur];
}
void dfs2(int cur,int pre,ll p) {
	(dp[cur]+=p)%=mo;
	cand[dp[cur]].push_back(cur);
	FORR(e,E[cur]) if(e!=pre) {
		ll h=(dp[cur]+mo-B*dp[e]%mo)%mo;
		dfs2(e,cur,B*h%mo);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	srand(time(NULL));
	cin>>N;
	FOR(i,N-1) {
		cin>>x;
		C[x]++;
	}
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	FOR(i,4) {
		ZERO(dp);
		ll moc[4]={998244353,1000000007,1000000009,1000000021};
		mo=moc[i];
		p2[0]=1;
		B=rand()%10000+1;
		FOR(j,N+1) p2[j+1]=p2[j]*B%mo;
		
		cand.clear();
		
		dfs1(0,0);
		dfs2(0,0,0);
		
		ll hash=0;
		FOR(j,N) {
			(hash+=C[j]*p2[j])%=mo;
		}
		FOR(j,N) {
			ll hash2=(hash+p2[j])%mo;
			FORR(v,cand[hash2]) ok[v]++;
		}
	}
	int num=0;
	FOR(i,N) if(ok[i]==4) num++;
	cout<<num<<endl;
	FOR(i,N) if(ok[i]==4) cout<<i+1<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
