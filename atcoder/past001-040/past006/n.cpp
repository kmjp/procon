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

int N,H;
ll A[101],B[101];
int C[101];

bool cmp(int a,int b) {
	return A[a]*B[b]>A[b]*B[a];
}

ll dp[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>H;
	FOR(i,N) {
		cin>>A[i]>>B[i];
		C[i]=i;
	}
	sort(C,C+N,cmp);
	ll ret=0;
	FOR(i,N) {
		x=C[i];
		for(j=0;j<=H;j++) {
			ll ret2=dp[j]+j*A[x];
			if(j>=B[x]) dp[j-B[x]]=max(dp[j-B[x]],ret2);
			ret=max(ret,ret2);
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
