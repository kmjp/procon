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

int T;
int N;
int A[202020];
int B[202020];
int L[202020],R[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		set<int> W;
		vector<pair<int,int>> P;
		FOR(i,N) {
			cin>>A[i];
			P.push_back({-A[i],i});
		}
		sort(ALL(P));
		W.insert(-1);
		W.insert(N);
		FOR(i,N) {
			x=P[i].second;
			auto it=W.lower_bound(x);
			R[x]=*it-1;
			L[x]=*prev(it)+1;
			W.insert(x);
		}
		
		
		FOR(i,N) cin>>B[i];
		
		int cur=0;
		FOR(i,N) {
			while(cur<N&&(A[cur]!=B[i]||(i<L[cur]||i>R[cur]))) cur++;
			if(cur==N) break;
		}
		if(i==N) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
