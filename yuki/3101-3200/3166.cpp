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

int T,N,L,K;
int X[202020];

int ok(int d) {
	if(d<=0) return 0;
	map<int,int> M;
	int i;
	FOR(i,N) {
		int A=X[i]-d;
		int B=X[i]+d;
		if(A<0) {
			M[0]++;
			M[B]--;
			M[A+L]++;
			M[L]--;
		}
		else if(B>L) {
			M[A]++;
			M[L]--;
			M[0]++;
			M[B-L]--;
		}
		else {
			M[A]++;
			M[B]--;
		}
	}
	int cur=M[0];
	
	FORR2(a,b,M) {
		if(cur<K) return 0;
		if(a==0) continue;
		if(a==L) break;
		cur+=b;
		
		
		if(cur<K) return 0;
	}
	return 1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>L>>K;
		FOR(i,N) cin>>X[i];
		int ret=(L+1)/2;
		for(j=30;j>=0;j--) if(ok(ret-(1<<j))) ret-=1<<j;
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
