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

int T,N;
ll C[202020],K;
ll ret[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		vector<pair<int,int>> V;
		FOR(i,N) {
			ret[i]=0;
			cin>>C[i];
			while(V.size()&&V.back().second>=C[i]) V.pop_back();
			V.push_back({i,C[i]});
		}
		
		cin>>K;
		
		ret[V[0].first]=K/V[0].second;
		ll sum=K%V[0].second;
		for(i=1;i<V.size();i++) {
			ll mi=min(ret[V[i-1].first],sum/(V[i].second-V[i-1].second));
			ret[V[i-1].first]-=mi;
			ret[V[i].first]+=mi;
			sum-=mi*(V[i].second-V[i-1].second);
		}
		for(i=N-2;i>=0;i--) ret[i]+=ret[i+1];
		FOR(i,N) cout<<ret[i]<<" ";
		cout<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
