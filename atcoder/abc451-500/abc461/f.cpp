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

ll N;
vector<ll> D;
vector<ll> Ds[3030];
map<ll,int> re;
int M;
const ll mo=998244353;
ll ret;
ll fact[3030];

void dfs(ll pre,ll d,ll sum,int num) {
	int id=re[d];
	if(d==1) {
		(ret+=sum*fact[num])%=mo;
		return;
	}
	if(pre>d) return;
	int cur=lower_bound(ALL(Ds[id]),pre+1)-Ds[id].begin();
	while(cur<Ds[id].size()) {
		dfs(Ds[id][cur],d/Ds[id][cur],sum+Ds[id][cur],num+1);
		cur++;
	}
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	fact[0]=1;
	FOR(i,303) fact[i+1]=fact[i]*(i+1)%mo;
	
	cin>>N;
	if(N==1) {
		cout<<1<<endl;
		return;
	}
	
	for(i=1;1LL*i*i<=N;i++) if(N%i==0) {
		D.push_back(i);
		if(N/i!=i) D.push_back(N/i);
	}
	sort(ALL(D));
	M=D.size();
	FOR(i,M) {
		re[D[i]]=i;
		FOR(j,i+1) {
			if(D[i]%D[j]==0&&(D[i]/D[j]==1||D[i]/D[j]>D[j])) Ds[i].push_back(D[j]);
		}
	}
	dfs(0,N,0,0);
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
