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

int N,A[202];
const ll mo=998244353;

ll from[101010];
ll to[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int pre=0,ma=0;;
	from[0]=1;
	FOR(i,N) {
		cin>>x;
		int dif=x-pre;
		ZERO(to);
		if(dif>=0) {
			for(j=0;j<=100000-dif;j++) {
				to[j+dif]+=from[j];
			}
		}
		else {
			for(j=ma;j<=100000;j++) {
				to[j]+=from[j];
			}
			
		}
		FOR(j,100001) {
			if(j) (to[j]+=to[j-1])%=mo;
			from[j]=to[j];
		}
		pre=x;
		ma=max(ma,x);
	}
	
	ll ret=0;
	FOR(i,100001) ret+=from[i];
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
