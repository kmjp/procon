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


int N,M,Q;
vector<int> RE[101010];
vector<pair<int,int>> dp[101010];
int T,Y;
int D[101010];
vector<int> E;

int dis[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>Q;
	FOR(i,M) {
		cin>>x>>y;
		RE[y-1].push_back(x-1);
	}
	MINUS(D);
	FOR(i,N) {
		E.clear();
		D[i]=0;
		E.push_back(i);
		FORR(e,RE[i]) {
			FORR(m,dp[e]) {
				if(D[m.second]==-1) E.push_back(m.second);
				D[m.second]=max(D[m.second],m.first+1);
			}
		}
		FORR(m,E) {
			if(D[m]>=0) {
				dp[i].push_back({D[m],m});
				D[m]=-1;
			}
		}
		sort(ALL(dp[i]));
		reverse(ALL(dp[i]));
		if(dp[i].size()>=210) dp[i].resize(210);
	}
	
	
	while(Q--) {
		vector<int> S;
		cin>>T>>Y;
		T--;
		FOR(i,Y) cin>>x, S.push_back(x-1), dis[x-1]=1;
		
		if(Y<=200) {
			int ma=-1;
			FORR(d,dp[T]) if(dis[d.second]==0) {
				ma=max(ma,d.first);
				break;
			}
			cout<<ma<<endl;
		}
		else {
			FOR(i,N) {
				if(dis[i]) D[i]=-101010;
				else D[i]=0;
				FORR(e,RE[i]) D[i]=max(D[i],D[e]+1);
			}
			if(D[T]<0) D[T]=-1;
			cout<<D[T]<<endl;
		}
		FORR(s,S) dis[s]=0;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
