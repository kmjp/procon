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

int K;
int D[303];

int N;
vector<vector<int>> E;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K;
	FOR(i,K) cin>>D[i];
	sort(D,D+K);
	
	N=3;
	E.push_back({2,0,D[0]/2});
	E.push_back({2,1,D[0]/2});
	vector<int> Ss={0,1};
	for(i=1;i<K;i++) {
		Ss.push_back(N);
		E.push_back({N,N+1,D[i]/2});
		E.push_back({N-1,N+1,(D[i]-D[i-1])/2});
		N+=2;
	}
	
	cout<<E.size()+1<<endl;
	FORR(e,E) cout<<e[0]+1<<" "<<e[1]+1<<" "<<e[2]<<endl;
	cout<<Ss.size()<<endl;
	FOR(i,Ss.size()) {
		if(i) cout<<" ";
		cout<<Ss[i]+1;
	}
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
