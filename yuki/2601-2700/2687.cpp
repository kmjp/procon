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
pair<ll,ll> A[101010];
pair<ll,ll> B[101010];

int ret[1010];
int K;
ll P[1010];
map<ll,int> Ps;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>A[i].first>>A[i].second;
		A[i].first*=2;
		A[i].second*=2;
	}
	FOR(i,M) {
		cin>>B[i].first>>B[i].second;
		B[i].first*=2;
		B[i].second*=2;
	}
	sort(A,A+N);
	sort(B,B+M);
	ll R=-1LL<<60;
	int ok=0;
	FOR(i,N) {
		if(A[i].first<=R) ok=1;
		R=max(R,A[i].second);
		A[i].first-=1LL<<50;
		A[i].second-=1LL<<50;
	}
	R=-1LL<<60;
	FOR(i,M) {
		if(B[i].first<=R) ok=1;
		R=max(R,B[i].second);
		B[i].first+=1LL<<50;
		B[i].second+=1LL<<50;
	}
	
	cin>>K;
	FOR(i,K) {
		cin>>P[i];
		P[i]*=2;
		if(ok) {
			ret[i]=1;
		}
		else {
			Ps[P[i]]=i;
		}
	}
	FOR(x,N) FOR(y,M) {
		ll L=(A[x].first+B[y].first)/2;
		ll R=(A[x].second+B[y].second)/2;
		while(1) {
			auto it=Ps.lower_bound(L);
			if(it==Ps.end()||it->first>R) break;
			ret[it->second]=1;
			Ps.erase(it);
		}
	}
	
	FOR(i,K) cout<<ret[i]<<" ";
	cout<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
