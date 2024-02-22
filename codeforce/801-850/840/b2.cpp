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

int T,N,K;
int H[222222],P[222222];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		vector<pair<int,int>> V;
		FOR(i,N) cin>>H[i];
		FOR(i,N) {
			cin>>P[i];
			V.push_back({H[i],-P[i]});
		}
		sort(ALL(V));
		for(i=N-1;i>=0;i--) {
			V[i].second=-V[i].second;
			if(i<N-1) V[i].second=min(V[i].second,V[i+1].second);
		}
		int cur=0;
		ll sum=0;
		while(cur<N&&K>0) {
			sum+=K;
			while(cur<N&&V[cur].first<=sum) cur++;
			if(cur<N) K-=V[cur].second;
		}
		if(cur==N) {
			cout<<"YES"<<endl;
		}
		else {
			cout<<"NO"<<endl;
		}
			
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
