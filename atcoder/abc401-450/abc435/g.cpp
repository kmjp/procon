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

int N,M;
int L[505050],R[505050];
const ll mo=998244353;

vector<int> evadd[505050],evdel[505050];

ll dp[505050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	
	N+=10;
	FOR(i,M) {
		cin>>L[i]>>R[i];
		L[i]+=5;
		R[i]+=5;
		evadd[L[i]+1].push_back(i);
		evadd[L[i]].push_back(i);
		evdel[R[i]+1].push_back(i);
		evdel[R[i]].push_back(i);
	}
	FOR(i,5) dp[i]=1;
	
	ll Tsum[2]={0,0};
	ll mul[2]={1,1};
	ll add[2]={0,0};
	map<ll,ll> T[2];
	for(i=4;i<=501010;i++) {
		k=i%2;
		
		// T‚ÌXV
		mul[k]=(mo-mul[k])%mo;
		add[k]=((mo-add[k])+dp[i-4])%mo;
		ll v=mul[k]*(mo-add[k])%mo;
		FORR(a,evadd[i]) {
			T[k][a]=v;
			(Tsum[k]+=v)%=mo;
		}
		FORR(a,evdel[i]) {
			(Tsum[k]+=mo-T[k][a])%=mo;
			T[k].erase(a);
		}
		
		dp[i]=dp[i-1]+T[k].size()*dp[i-2]-Tsum[k]*mul[k]-T[k].size()*add[k];
		dp[i]=(dp[i]%mo+mo)%mo;
		
		
		
		
	}
	cout<<dp[501010]<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
