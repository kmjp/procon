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
int W[303030];
int M;
int S[303030];

ll dp[202020];

ll hoge(vector<pair<int,int>> V) {
	if(V.size()==0) return 0;
	if(V.size()==1) return 1LL*V.back().second*V.back().second;
	if(V[0].first==3) {
		V[1].second+=V[0].second;
		V.erase(V.begin());
	}
	if(V.back().first==3) {
		V[V.size()-2].second+=V.back().second;
		V.pop_back();
	}
	
	int N=V.size();
	int i,j;
	FOR(i,N+1) dp[i]=-1LL<<60;
	dp[0]=0;
	
	FOR(i,N) {
		if(i%2==0) {
			if(i+1<=N) dp[i+1]=max(dp[i+1],dp[i]+1LL*V[i].second*V[i].second);
			if(i+2<=N) dp[i+2]=max(dp[i+2],dp[i]+1LL*(V[i].second+V[i+1].second)*(V[i].second+V[i+1].second));
		}
		else {
			if(i+2<=N) dp[i+2]=max(dp[i+2],dp[i]+1LL*(V[i].second+V[i+1].second)*(V[i].second+V[i+1].second));
			if(i+3<=N) dp[i+3]=max(dp[i+3],dp[i]+1LL*(V[i].second+V[i+1].second+V[i+2].second)*(V[i].second+V[i+1].second+V[i+2].second));
		}
	}
	
	
	return dp[N];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	vector<pair<int,int>> V;
	cin>>N;
	FOR(i,N) cin>>W[i];
	cin>>M;
	FOR(i,M) cin>>S[i];
	x=y=0;
	
	ll ret=0;
	
	while(x<N||y<M) {
		if(W[x]==0) {
			x++;
			continue;
		}
		if(S[y]==0) {
			y++;
			continue;
		}
		int mi=min(W[x],S[y]);
		W[x]-=mi;
		S[y]-=mi;
		int v=((x+1)%2)+2*((y+1)%2);
		if(v==0) {
			ret+=hoge(V);
			V.clear();
		}
		else {
			if(v!=3&&V.size()>=2&&V[V.size()-2].first==v) {
				V[V.size()-2].second+=mi;
				V[V.size()-2].second+=V.back().second;
				V.pop_back();
			}
			else {
				if(V.size()&&V.back().first+v==3) {
					V.push_back({3,0});
				}
				V.push_back({v,mi});
			}
		}
	}
	ret+=hoge(V);
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
