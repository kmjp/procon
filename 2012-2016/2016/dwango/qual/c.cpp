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

int N,M;
int st,ed;
ll D[2][50500];
int L[505050];
vector<int> S[505050];
vector<int> W[505050];
vector<ll> Sum[505050];
vector<pair<int,int>> P[252525];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	cin>>st>>ed;
	FOR(i,M) {
		cin>>L[i];
		S[i].resize(L[i]);
		Sum[i].resize(L[i]);
		W[i].resize(L[i]-1);
		FOR(x,L[i]) {
			cin>>S[i][x];
			P[S[i][x]].push_back({i,x});
		}
		FOR(x,L[i]-1) {
			cin>>W[i][x];
			Sum[i][x+1]=Sum[i][x]+W[i][x];
		}
	}
	memset(D,0x3f,sizeof(D));
	D[1][ed]=0;
	priority_queue<pair<ll,int>> Q;
	Q.push({0,ed});
	while(Q.size()) {
		auto aa=Q.top();
		Q.pop();
		ll co=-aa.first;
		int cur=aa.second;
		if(D[1][cur]!=co) continue;
		FORR(r,P[cur]) {
			int ro=r.first;
			int id=r.second;
			if(id) {
				int tar=S[ro][id-1];
				ll co2=co+W[ro][id-1];
				if(D[1][tar]>co2) D[1][tar]=co2, Q.push({-co2,tar});
			}
			if(id<L[ro]-1) {
				int tar=S[ro][id+1];
				ll co2=co+W[ro][id];
				if(D[1][tar]>co2) D[1][tar]=co2, Q.push({-co2,tar});
			}
		}
	}
	
	ll mi=1LL<<60;
	D[0][ed]=0;
	Q.push({0,ed});
	while(Q.size()) {
		auto aa=Q.top();
		Q.pop();
		ll co=-aa.first;
		int cur=aa.second;
		if(D[0][cur]!=co) continue;
		FORR(r,P[cur]) {
			int ro=r.first;
			int id=r.second;
			if(id) {
				int tar=S[ro][id-1];
				ll co2=max(W[ro][id-1]+co,Sum[ro][L[ro]-1]-Sum[ro][id-1]+D[1][S[ro].back()]);
				if(D[0][tar]>co2) D[0][tar]=co2, Q.push({-co2,tar});
			}
			if(id<L[ro]-1) {
				int tar=S[ro][id+1];
				ll co2=max(W[ro][id]+co,Sum[ro][id+1]+D[1][S[ro][0]]);
				if(D[0][tar]>co2) D[0][tar]=co2, Q.push({-co2,tar});
			}
		}
	}
	
	
	cout<<D[0][st]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
