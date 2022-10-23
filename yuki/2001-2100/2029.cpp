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

int N;
int A[202020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	
	int ret=N/2;
	ll sum=0;
	if(N%2) {
		vector<int> V;
		FOR(i,N) if(A[i]<=N/2) V.push_back(i);
		assert(V.size()==ret);
		FOR(i,V.size()) sum+=abs(V[i]-(i*2+1));
	}
	else {
		vector<int> V;
		FOR(i,N) if(A[i]<=N/2) V.push_back(i);
		ll cur=0;
		FOR(i,N/2) cur+=abs(V[i]-(i*2));
		sum=cur;
		FOR(i,N/2) {
			cur-=abs(V[i]-(i*2));
			cur+=abs(V[i]-(i*2+1));
			sum=min(sum,cur);
		}
	}
	cout<<ret<<" "<<sum<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
