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
int A[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	ll ret=0;
	priority_queue<pair<int,int>> Q;
	FOR(i,N) {
		cin>>A[i];
		Q.push({A[i],i});
	}
	while(Q.size()) {
		auto p=Q.top();
		Q.pop();
		x=p.second;
		if(A[x]==p.first) {
			if(x&&A[x]-A[x-1]>K) {
				ret+=A[x]-K-A[x-1];
				A[x-1]=A[x]-K;
				Q.push({A[x-1],x-1});
			}
			if(x+1<N&&A[x]-A[x+1]>K) {
				ret+=A[x]-K-A[x+1];
				A[x+1]=A[x]-K;
				Q.push({A[x+1],x+1});
			}
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
