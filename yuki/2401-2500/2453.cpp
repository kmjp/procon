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
int A[101010],B[101010],C[101010];


struct cmp {
  bool operator() (pair<pair<int,int>,int> L, pair<pair<int,int>,int> R) {
	if(1LL*L.first.first*B[R.first.second]<1LL*R.first.first*B[L.first.second]) return 1;
	if(1LL*L.first.first*B[R.first.second]>1LL*R.first.first*B[L.first.second]) return 0;
	if(L.second>R.second) return 1;
	return 0;
  }
};

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>A[i];
	FOR(i,M) cin>>B[i+1];
	
	priority_queue<pair<pair<int,int>,int>, vector<pair<pair<int,int>,int>>, cmp> Q;
	FOR(i,N) {
		Q.push({{A[i],1},i});
	}
	FOR(i,M) {
		auto p=Q.top();
		Q.pop();
		x=p.second;
		cout<<x+1<<endl;
		C[x]++;
		Q.push({{A[x],C[x]+1},x});
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
