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
ll S[1010101];
const ll mo=998244353;
int sum[10101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) cin>>S[i];
		FOR(i,S[N-1]+1) sum[i]=0;
		FOR(i,N) sum[S[i]]=1;
		FOR(i,S[N-1]+1) sum[i+1]+=sum[i];
		
		vector<pair<pair<int,int>,ll>> V;
		for(i=1;i<=S[N-1];i++) {
			x=S[N-1]/i;
			y=S[N-1]/i+(S[N-1]%i!=0);
			if(V.empty()||V.back().first!=make_pair(x,y)) V.push_back({{x,y},0});
			V.back().second+=i;
		}
		ll ret=0;
		FORR2(a,v,V) {
			v%=mo;
			if(a.first==a.second) {
				for(x=a.first;x<=S[N-1];x+=a.first) ret+=v*(sum[x]-sum[x-1])%mo;
			}
			else {
				for(x=1;x<a.first;x++) {
					ll L=1LL*x*a.first;
					ll R=min(S[N-1],1LL*x*a.second);
					if(L>R) break;
					ret+=v*(sum[R]-sum[L-1])%mo;
				}
				ll b=1LL*a.first*a.first;
				if(b<=S[N-1]) ret+=v*(sum[S[N-1]]-sum[b-1])%mo;
			}
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
