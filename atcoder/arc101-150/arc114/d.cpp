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

int N,K;
ll A[5050],T[5050];

ll FL[5050],FR[5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	vector<pair<int,int>> ev;
	FOR(i,N) {
		cin>>A[i];
		ev.push_back({A[i],-1});
	}
	FOR(i,K) {
		cin>>T[i];
		ev.push_back({T[i],i});
	}
	
	sort(ALL(ev));
	FOR(i,5050) FL[i]=1LL<<60;
	FOR(i,5050) FR[i]=1LL<<60;
	FL[0]=FR[0]=0;
	
	int pre=-1LL<<30;
	int blue=0;
	FORR(e,ev) {
		
		if(e.first!=pre) {
			if(blue==0) {
				for(i=1;i<=N;i+=2) FL[i]=FR[i]=1LL<<60;
				for(i=0;i<=N;i+=2) {
					FL[i]+=i*1LL*(e.first-pre);
					FR[i]+=i*1LL*(e.first-pre);
				}
			}
			else {
				for(i=0;i<=N;i+=2) FL[i]=FR[i]=1LL<<60;
				for(i=1;i<=N;i+=2) {
					FL[i]+=i*1LL*(e.first-pre);
					FR[i]+=i*1LL*(e.first-pre);
				}
			}
		}
		
		// R‚ðŒ¸‚ç‚·
		for(i=N;i>=0;i--) FR[i]=min(FR[i],FR[i+1]);
		FL[0]=FR[0]=min(FL[0],FR[0]);
		// L‚ð‘‚â‚·
		FOR(i,N) FL[i+1]=min(FL[i],FL[i+1]);
		
		if(e.second>=0) {
			blue^=1;
		}
		else {
			// L‚ð‰ñŽû
			FOR(i,N) FL[i]=min(FL[i],FL[i+1]);
			// R‚ð‘‚â‚·
			for(i=N;i>=1;i--) FR[i]=min(FR[i-1],FR[i]);
		}
		pre=e.first;
	}
	
	
	ll ret=FL[0];
	FOR(i,N+1) ret=min(ret,FR[i]);
	if(ret>=1LL<<60) ret=-1;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
