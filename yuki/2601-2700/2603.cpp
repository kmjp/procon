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
int A[202020],B[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>A[i+1];
	FOR(i,N) {
		cin>>x;
		A[i+1]=x-A[i+1];
		if(A[i+1]<0) A[i+1]+=M;
	}
	deque<int> Q;
	for(i=1;i<=N+1;i++) {
		x=(A[i]-A[i-1]+M)%M;
		Q.push_back(x);
	}
	sort(ALL(Q));
	ll ret=0;
	while(Q.size()) {
		while(Q.size()&&Q.front()==0) Q.pop_front();
		while(Q.size()&&Q.back()==M) Q.pop_back();
		if(Q.empty()) break;
		assert(Q.size()>1);
		x=min(Q.front(),M-Q.back());
		ret+=x;
		Q.front()-=x;
		Q.back()+=x;
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
