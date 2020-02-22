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
vector<int> E[5050];
int num[5050];
ll fact[5050];
ll C[5050][5050];
ll mo=1000000007;
ll from[5050];
ll to[5050];

pair<int,int> dfs_center(int cur,int pre) {
	pair<int,int> res=make_pair(1<<30,-1);
	int ma=0;
	num[cur]=1;
	
	FORR(r,E[cur]) if(r!=pre) {
		res=min(res,dfs_center(r,cur));
		ma=max(ma,num[r]);
		num[cur]+=num[r];
	}
	return min(res,make_pair(max(ma,N-num[cur]),cur));
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	FOR(i,5005) for(j=0;j<=i;j++) C[i][j]=(j==0||j==i)?1:(C[i-1][j-1]+C[i-1][j])%mo;
	fact[0]=1;
	for(i=1;i<=5000;i++) fact[i]=fact[i-1]*i%mo;
	pair<int,int> p=dfs_center(0,-1);
	
	FOR(i,N) if(num[i]*2==N) {
		ll ret=1;
		for(i=1;i<=N/2;i++) ret=ret*i%mo;
		cout<<ret*ret%mo<<endl;
		return;
	}
	
	vector<int> V;
	V.push_back(N-num[p.second]);
	FORR(e,E[p.second]) if(num[e]<num[p.second]) V.push_back(num[e]);
	int tot=0;
	from[0]=1;
	FORR(v,V) {
		ZERO(to);
		FOR(x,tot+1) FOR(y,v+1) {
			(to[x+y]+=from[x]*C[v][y]%mo*C[v][y]%mo*fact[y])%=mo;
		}
		tot+=v;
		swap(from,to);
	}
	
	ll ret=0;
	FOR(i,N) (ret+=mo+(i%2==0?1:-1)*fact[N-i]*from[i])%=mo;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
