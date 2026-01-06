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
ll A[101010];
ll B[101010];
ll C[101010];
ll P[101010];
vector<int> E[101010];
ll S;
ll NS[202020];

const ll mo=998244353;
ll ret=0;

void dfs(int cur) {
	NS[cur]=A[cur];
	ll LS=S-NS[cur];
	
	vector<pair<int,ll>> num;
	FORR(e,E[cur]) {
		dfs(e);
		LS-=NS[e];
		NS[cur]+=NS[e];
		num.push_back({C[e],NS[e]});
		
		//左
		ll lef=C[e]*(C[e]+1)/2;
		ll ri=(A[cur]-1-C[e])*(A[cur]-C[e])/2;
		(ret+=(lef+ri)%mo*(NS[e]%mo))%=mo;
		
	}
	//親方向
	(ret+=LS%mo*(NS[cur]%mo))%=mo;
	//親から左右
	ll lef=B[cur]*(B[cur]+1)/2;
	ll ri=(A[cur]-1-B[cur])*(A[cur]-B[cur])/2;
	(ret+=(lef+ri)%mo*(LS%mo))%=mo;
	
	sort(ALL(num));
	ll numS=0;
	ll distS=0;
	FORR2(a,b,num) {
		b%=mo;
		(ret+=b*(numS*a%mo-distS)%mo)%=mo;
		//親方向に向けた移動
		(ret+=(LS%mo)*(b%mo)%mo*abs(a-B[cur])%mo)%=mo;
		
		(numS+=b)%=mo;
		(distS+=a*b)%=mo;
	}
	ret=(ret%mo+mo)%mo;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		S+=A[i];
		__int128 a=A[i]-1;
		ret+=(a*(a+1)*(2*a+1)/6+a*(a+1)/2)/2%mo;
	}
	FOR(i,N-1) {
		cin>>B[i+1];
		B[i+1]--;
	}
	FOR(i,N-1) {
		cin>>C[i+1];
		C[i+1]--;
	}
	FOR(i,N-1) {
		cin>>P[i+1];
		P[i+1]--;
		E[P[i+1]].push_back(i+1);
	}
	dfs(0);
	cout<<ret*2%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
