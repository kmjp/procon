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

int M;
ll N;
ll ret;
vector<pair<pair<ll,ll>,int>> C;
int nex;

ll dp[1505050];
set<int> Vs[1505050];

const ll mo=998244353;

bool cmp2(pair<ll,ll> L,pair<ll,ll> R) {
	return (__int128)L.first*R.second<(__int128)L.second*R.first;
}

bool cmp(pair<pair<ll,ll>,int> L,pair<pair<ll,ll>,int> R) {
	if(L.first.first*R.first.second<L.first.second*R.first.first) return 1;
	if(L.first.first*R.first.second>L.first.second*R.first.first) return 0;
	return L.second<R.second;
}

int dfs(int L,int R,pair<ll,ll> VCL,pair<ll,ll> VCR) {
	if(L>R) return -1;
	int cur=nex++;
	dp[cur]=0;
	Vs[cur].clear();
	pair<ll,ll> VCM={VCL.first+VCR.first,VCL.second+VCR.second};
	
	if(cmp2(VCM,C[L].first)) {
		int step=0;
		int i;
		for(i=29;i>=0;i--) {
			VCM.first=VCL.first+(step+(1LL<<i))*VCR.first;
			VCM.second=VCL.second+(step+(1LL<<i))*VCR.second;
			if(cmp2(VCM,C[L].first)) step+=1LL<<i;
		}
		
		
		VCM.first=VCL.first+(step)*VCR.first;
		VCM.second=VCL.second+(step)*VCR.second;
		int C=dfs(L,R,VCM,VCR);
		(ret+=(step-1)*(1LL*N*(N+1)/2%mo-dp[C]))%=mo;
		dp[cur]=dp[C];
		swap(Vs[cur],Vs[C]);
	}
	else if(cmp2(C[R].first,VCM)) {
		int step=0;
		int i;
		for(i=29;i>=0;i--) {
			VCM.first=(step+(1LL<<i))*VCL.first+VCR.first;
			VCM.second=(step+(1LL<<i))*VCL.second+VCR.second;
			if(cmp2(C[R].first,VCM)) step+=1LL<<i;
		}
		
		VCM.first=(step)*VCL.first+VCR.first;
		VCM.second=(step)*VCL.second+VCR.second;
		
		int C=dfs(L,R,VCL,VCM);
		(ret+=(step-1)*(1LL*N*(N+1)/2%mo-dp[C]))%=mo;
		dp[cur]=dp[C];
		swap(Vs[cur],Vs[C]);
	}
	else {
		pair<pair<ll,ll>,int> TV={VCM,0};
		int M=lower_bound(C.begin()+L,C.begin()+R+1,TV,cmp)-C.begin();
		int LE=M;
		int pre=-1;
		while(M<=R&&C[M].first==VCM) {
			(dp[cur]+=1LL*(C[M].second-pre-1)*(C[M].second-pre)/2)%=mo;
			pre=C[M].second;
			Vs[cur].insert(pre);
			M++;
		}
		(dp[cur]+=1LL*(N-1-pre)*(N-pre)/2)%=mo;
		
		int i;
		FOR(i,2) {
			int C;
			if(i==0) C=dfs(L,LE-1,VCL,VCM);
			else C=dfs(M,R,VCM,VCR);
			if(C==-1) continue;
			if(Vs[cur].size()<Vs[C].size()) {
				swap(dp[cur],dp[C]);
				swap(Vs[cur],Vs[C]);
			}
			FORR(v,Vs[C]) {
				auto it=Vs[cur].lower_bound(v);
				int a,b;
				if(it==Vs[cur].begin()) {
					a=-1;
					b=*it;
				}
				else if(it==Vs[cur].end()) {
					a=*--it;
					b=N;
				}
				else {
					b=*it;
					a=*--it;
				}
				(dp[cur]-=1LL*(b-a-1)*(b-a)/2)%=mo;
				(dp[cur]+=1LL*(b-v-1)*(b-v)/2)%=mo;
				(dp[cur]+=1LL*(v-a-1)*(v-a)/2)%=mo;
				Vs[cur].insert(v);
			}
			(dp[cur]=dp[cur]%mo+mo)%=mo;
		}
		
	}
	(ret+=1LL*N*(N+1)/2-dp[cur])%=mo;
	
	return cur;
}


void hoge(vector<pair<ll,ll>> C3) {
	N=C3.size();
	if(N==0) return;
	vector<pair<pair<ll,ll>,int>> C2;
	int i;
	FOR(i,N) C2.push_back({C3[i],i});
	sort(ALL(C2),cmp);
	C=C2;
	int L=0,R=C.size()-1;
	while(L<C.size()&&C[L].first.first==0) L++;
	while(R>=0&&C[R].first.second==0) R--;
	if(L>R) return;
	nex=0;
	pair<ll,ll> SL={0,1};
	pair<ll,ll> SR={1,0};
	dfs(L,R,SL,SR);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>M;
	vector<pair<ll,ll>> C;
	FOR(i,M) {
		cin>>x>>y;
		if(__gcd(x,y)!=1) {
			hoge(C);
			C.clear();
		}
		else {
			C.push_back({x,y});
		}
	}
	hoge(C);
	
	cout<<(ret%mo+mo)%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
