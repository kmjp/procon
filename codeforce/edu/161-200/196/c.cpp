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

int T,N;
int D[202020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N+1) D[i]=1;
		x=0;
		while(1<<(x+1)<=N) x++;
		for(i=x+1;i>=1;i--) {
			int num=0;
			for(j=1;j<=N;j++) num^=j*D[j];
			if((num&(1<<i))==0) {
				for(j=1;j<=N;j++) if(j&(1<<(i-1))) {
					D[j]++;
					break;
				}
			}
		}
		int k=0,m=0;
		for(i=1;i<=N;i++) {
			k|=i;
			m^=D[i]*i;
			cout<<D[i]-1<<" ";
		}
		cout<<endl;
		assert(m>=2*k);
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
