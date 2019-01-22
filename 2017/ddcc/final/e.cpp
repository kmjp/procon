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

int N;
vector<vector<int>> E;
vector<int> MD[404040];
ll DS[404040];
ll LS[404040],TLS;
ll dp[505050];

pair<int,int> farthest(vector<vector<int>>& E, int cur,int pre,int d,vector<int>& D) {
	D[cur]=d;
	pair<int,int> r={d,cur};
	FORR(e,E[cur]) if(e!=pre) r=max(r, farthest(E,e,cur,d+1,D));
	return r;
}

pair<int,vector<int>> diameter(vector<vector<int>>& E) { // diameter,center
	vector<int> D[2];
	D[0].resize(E.size());
	D[1].resize(E.size());
	auto v1=farthest(E,0,0,0,D[0]);
	auto v2=farthest(E,v1.second,v1.second,0,D[0]);
	farthest(E,v2.second,v2.second,0,D[1]);
	pair<int,vector<int>> R;
	R.first = v2.first;
	//dS‚ðŽæ‚éê‡
	for(int i=E.size()-1;i>=0;i--) if(D[0][i]+D[1][i]==R.first && abs(D[0][i]-D[1][i])<=1) R.second.push_back(i);
	//—¼’[‚ðŽæ‚éê‡
	R.second.push_back(v1.second);
	R.second.push_back(v2.second);

	return R;
}

void dfs(int cur,int pre) {
	MD[cur].push_back(0);
	if(E[cur].size()==1) LS[cur]=1;
	
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		MD[cur].push_back(MD[e][0]+1);
		LS[cur]+=LS[e];
		DS[cur]+=DS[e]+LS[e];
	}
	sort(ALL(MD[cur]));
	reverse(ALL(MD[cur]));
}

void dfs2(int cur,int pre,int far,ll ps) {
	
	if(far!=-1) {
		MD[cur].push_back(far);
		sort(ALL(MD[cur]));
		reverse(ALL(MD[cur]));
	}
	DS[cur]+=ps;
	FORR(e,E[cur]) if(e!=pre) {
		int f2=MD[cur][0]+1;
		if(MD[cur][0]==MD[e][0]+1) f2=MD[cur][1]+1;
		dfs2(e,cur,f2,DS[cur]-(DS[e]+LS[e])+TLS-LS[e]);
		
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	E.resize(2*N-1);
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(N+i);
		E[y-1].push_back(N+i);
		E[N+i].push_back(x-1);
		E[N+i].push_back(y-1);
	}
	N=2*N-1;
	auto dia=diameter(E);
	r=dia.second[0];
	int di=dia.first/2;
	
	dfs(r,r);
	TLS=LS[r];
	dfs2(r,r,-1,0);
	
	FOR(i,505000) dp[i]=-1;
	FOR(i,N) if(E[i].size()>=2) {
		int R=MD[i][0];
		dp[R]=max(dp[R],(1LL*R*TLS-DS[i])/2);
	}
	FOR(i,505000) {
		if(dp[i]!=-1) {
			if(dp[i+2]==-1) {
				dp[i+2]=dp[i]+TLS;
			}
			else {
				dp[i+2]=max(dp[i+2],dp[i]+TLS);
			}
		}
	}
	
	
	
	int Q;
	cin>>Q;
	while(Q--) {
		ll K;
		cin>>K;
		
		x=lower_bound(dp+di,dp+500000,K)-dp;
		if(x==500000) {
			cout<<min(((K-dp[494949])+TLS-1)/TLS*2+494949,((K-dp[494948])+TLS-1)/TLS*2+494948)<<endl;
		}
		else {
			cout<<x<<endl;
		}
		
	}
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
