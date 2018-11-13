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

int N,M,S;
vector<pair<int,int>> V[201010];
vector<pair<int,int>> E[201010];

ll dp1[202020];
ll dp2[202020];
deque<pair<int,ll>> D[202020];
ll DS[202020];
ll mo=1000000007;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>S;
	FOR(i,M) {
		cin>>x>>y>>r;
		x--,y--;
		V[r-1].push_back({x,-y});
	}
	FOR(i,S) if(V[i].size()) {
		sort(ALL(V[i]));
		vector<pair<int,int>> V2;
		FORR(v,V[i]) {
			while(V2.size() && V2.back().first<=v.first && -v.second<=-V2.back().second) V2.pop_back();
			V2.push_back(v);
		}
		FORR(v,V2) {
			E[v.first].push_back({i,-v.second});
		}
	}
	dp1[0]=1;
	FOR(i,N) {
		FORR(e,E[i]) {
			j=e.first;
			int r=e.second+1;
			while(D[j].size() && D[j].front().first<i+1) DS[j]-=D[j].front().second, D[j].pop_front();
			DS[j]=(DS[j]%mo+mo)%mo;
			ll add=(dp1[i]-DS[j]+mo)%mo;
			(dp2[r]+=add)%=mo;
			(DS[j]+=add)%=mo;
			D[j].push_back({r,add});
		}
		dp1[i+1]=(dp1[i]*S-dp2[i+1]+mo)%mo;
	}
	cout<<dp1[N]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
