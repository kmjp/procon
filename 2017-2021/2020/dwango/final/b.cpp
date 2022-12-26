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

int N,M,K,D;
int A[20];
vector<pair<int,int>> E[202020];
int mask[101010];
ll dist[101010];
ll p2[202020];
ll num[1<<20];
const ll mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K>>D;
	FOR(i,K) cin>>A[i];
	FOR(i,M) {
		cin>>x>>y>>r;
		E[x].push_back({y,r});
		E[y].push_back({x,r});
	}
	
	FOR(i,K) {
		FOR(x,N) dist[x]=1LL<<60;
		priority_queue<pair<ll,int>> Q;
		dist[A[i]]=0;
		Q.push({0,A[i]});
		while(Q.size()) {
			ll co=-Q.top().first;
			int cur=Q.top().second;
			Q.pop();
			if(co!=dist[cur]) continue;
			if(co>D) break;
			mask[cur] |= 1<<i;
			FORR(e,E[cur]) if(dist[e.first]>co+e.second) {
				dist[e.first]=co+e.second;
				Q.push({-dist[e.first],e.first});
			}
		}
	}
	
	p2[0]=1;
	FOR(i,N) {
		num[mask[i]]++;
		p2[i+1]=p2[i]*2%mo;
	}
	FOR(i,K) {
		FOR(x,1<<K) if((x&(1<<i))) num[x^(1<<i)]+=num[x];
	}
	FOR(x,1<<K) num[x]=p2[num[x]]-1;
	FOR(i,K) {
		FOR(x,1<<K) if((x&(1<<i))==0) (num[x]+=mo-num[x^(1<<i)])%=mo;
	}
	
	ll ret=0;
	FOR(x,1<<K) ret^=num[x]%mo;
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
