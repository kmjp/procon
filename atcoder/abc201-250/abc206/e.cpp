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


int L,R;
ll S[1010100];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>L>>R;
	ll ret=0;
	for(int g=2;g<=R;g++) {
		int AL=(L+g-1)/g;
		int AR=R/g;
		if(AR-AL<=0) continue;
		for(i=1;i<=AR;i++) {
			int num=AR/i-((AL+i-1)/i-1);
			if(i==1&&(AL+i-1)/i==1) num--;
			S[i]=1LL*num*(num-1)/2;
		}
		for(i=AR;i>=1;i--) {
			for(j=i*2;j<=AR;j+=i) S[i]-=S[j];
		}
		ret+=S[1]*2;
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
