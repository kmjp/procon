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
pair<int,int> P[202020];
vector<int> C[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>P[i].first;
	FOR(i,N) cin>>P[i].second;
	sort(P,P+N);
	FOR(i,M) {
		cin>>x>>y;
		C[x].push_back(y);
	}
	multiset<int> S;
	sort(ALL(C[0]));
	int cur=0;
	sort(P,P+N);
	FORR(c,C[0]) {
		while(cur<N&&P[cur].first<=c) {
			S.insert(P[cur].second);
			cur++;
		}
		if(S.size()) S.erase(S.find(*S.rbegin()));
	}
	while(cur<N) S.insert(P[cur++].second);
	sort(ALL(C[1]));
	FORR(c,C[1]) {
		auto it=S.lower_bound(c+1);
		if(it!=S.begin()) S.erase(prev(it));
	}
	cout<<S.size()<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
