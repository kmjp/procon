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
int X,Y;
ll A[303030],B,C;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X>>Y>>B>>C;
	if(B<C) swap(B,C),swap(X,Y);
	FOR(i,N) {
		cin>>A[i];
	}
	sort(A,A+N);
	ll ret=3LL<<60;
	for(x=0;x<=min(X,Y);x++) {
		if(X+Y-x>N) continue;
		vector<ll> D;
		int cur=0;
		if(x) {
			D.push_back(A[cur]+B+C);
			D.push_back(A[cur+x-1]+B+C);
			cur+=x;
		}
		y=X-x;
		if(y) {
			D.push_back(A[cur]+B);
			D.push_back(A[cur+y-1]+B);
			cur+=y;
		}
		y=Y-x;
		if(y) {
			D.push_back(A[cur]+C);
			D.push_back(A[cur+y-1]+C);
			cur+=y;
		}
		y=N-(X+Y-x);
		if(y) {
			D.push_back(A[cur]);
			D.push_back(A[cur+y-1]);
			cur+=y;
		}
		sort(ALL(D));
		ret=min(ret,D.back()-D[0]);
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
