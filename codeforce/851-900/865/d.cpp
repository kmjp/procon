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
ll N,M;
const ll mo=998244353;

ll num[61][2],sum[61][2];
ll ret;

pair<ll,ll> dfs(int d,int c) {
	if(d==60) {
		if(c==0) return {1,0};
		else return {0,0};
	}
	if(num[d][c]>=0) {
		return {num[d][c],sum[d][c]};
	}
	ll nu=0,su=0;
	
	if((N>>d)&1) {
		if(c==0) {
			//01+0
			auto p=dfs(d+1,0);
			nu+=p.first;
			su+=p.first+p.second*2;
		}
		else {
			//00+1
			auto p=dfs(d+1,0);
			nu+=p.first;
			su+=p.second*2;
			//11+1
			p=dfs(d+1,1);
			nu+=p.first;
			su+=p.second*2;
		}
	}
	else {
		if(c==0) {
			//00+0
			auto p=dfs(d+1,0);
			nu+=p.first;
			su+=p.second*2;
			//11+0
			p=dfs(d+1,1);
			nu+=p.first;
			su+=p.second*2;
		}
		else {
			//01+1
			auto p=dfs(d+1,1);
			nu+=p.first;
			su+=p.first+p.second*2;
		}
	}
	num[d][c]=nu%mo;
	sum[d][c]=su%mo;
	return {num[d][c],sum[d][c]};
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		if(M==1) {
			ret=N%mo;
		}
		else if(M>=3) {
			if(N%2) {
				ret=((1+N)/2%mo)*((1+N)/2%mo)%mo;
			}
			else {
				N/=2;
				ret=(N%mo)*((N+1)%mo)%mo;
			}
		}
		else {
			MINUS(num);
			MINUS(sum);
			ret=dfs(0,0).second%mo;
			
			
			
		}
		cout<<ret%mo<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
