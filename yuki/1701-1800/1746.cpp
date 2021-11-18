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
set<int> A[202020];

ll H[1010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,1010000) {
		H[i]=(1LL*rand()<<32)|rand();
	}
	ll cur=0;
	map<ll,int> M;
	ll ret=0;
	M[0]=1;
	cin>>N;
	FOR(i,N) {
		cin>>x;
		for(j=2;j*j<=x;j++) while(x%j==0) {
			x/=j;
			cur^=H[j];
		}
		if(x>1) cur^=H[x];
		ret+=M[cur];
		M[cur]++;
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
