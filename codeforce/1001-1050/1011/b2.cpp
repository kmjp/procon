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

int T,N,A[5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) cin>>A[i];
		
		vector<pair<int,int>> R;
		if(N>4) {
			R.push_back({4,N});
			set<int> S;
			for(i=3;i<N;i++) S.insert(A[i]);
			A[3]=0;
			while(S.count(A[3])) A[3]++;
		}
		N=4;
		int n0=0;
		FOR(i,N) if(A[i]==0) n0++;
		if(n0==0) {
			R.push_back({1,4});
		}
		else if((A[0]==0&&A[2]==0)||(A[0]==0&&A[3]==0)||(A[1]==0&&A[2]==0)||(A[1]==0&&A[3]==0)) {
			R.push_back({3,4});
			R.push_back({1,2});
			R.push_back({1,2});
		}
		else if(A[0]==0&&A[1]==0){
			R.push_back({1,3});
			R.push_back({1,2});
		}
		else if(A[2]==0&&A[3]==0){
			R.push_back({2,4});
			R.push_back({1,2});
		}
		else if(A[0]==0) {
			R.push_back({1,3});
			R.push_back({1,2});
		}
		else {
			R.push_back({2,4});
			R.push_back({1,2});
		}
		cout<<R.size()<<endl;
		FORR2(a,b,R) cout<<a<<" "<<b<<endl;
	
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
