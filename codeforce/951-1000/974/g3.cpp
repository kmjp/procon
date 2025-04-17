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

int T,N,M,K;
ll D[101010],A[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M>>K;
		FOR(i,N) cin>>D[i]>>A[i];
		D[N]=2<<20;
		
		vector<pair<ll,ll>> V;
		ll ret=0;
		FOR(i,N) {
			ll cur=D[i];
			ll nex=D[i+1];
			V.push_back({cur,A[i]});
			while(cur<nex&&V.size()) {
				
				if(cur>=V.back().first+K) {
					V.clear();
					break;
				}
				ll a=V.back().second/M;
				a=min(a,nex-cur);
				a=min(a,V.back().first+K-cur);
				if(cur+a>=nex) {
					a=nex-cur;
					ret+=a;
					V.back().second-=a*M;
					break;
				}
				else if(cur+a>=V.back().first+K) {
					ret+=V.back().first+K-cur;
					V.clear();
					break;
				}
				else {
					ret+=a;
					cur+=a;
					if(V.size()==1) {
						V.clear();
					}
					else {
						V[V.size()-2].second+=V.back().second-M*a;
						V.pop_back();
					}
				}
			}
		}
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
