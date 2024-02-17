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
vector<int> E[5050];
pair<int,int> P[5050];
ll A[5050];
ll W[5050];

ll sc[5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	FOR(i,N) {
		cin>>P[i].first;
		P[i].second=i;
		W[i]=P[i].first;
	}
	FOR(i,N) cin>>A[i];
	
	sort(P,P+N);
	ll ret=0;
	FOR(i,N) {
		x=P[i].second;
		ll from[5050]={1};
		FORR(e,E[x]) {
			for(y=5000;y>=W[e];y--) from[y]=max(from[y],from[y-W[e]]+sc[e]);
		}
		sc[x]=*max_element(from,from+W[x]);
		ret+=A[x]*sc[x];
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
