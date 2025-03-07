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

int T;
int K;
int N[1010101];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>K;
		FOR(i,K) {
			cin>>N[i];
			FOR(j,N[i]-1) cin>>x;
		}
		sort(N,N+K);
		int cur=0;
		for(i=K-1;i>=0;i--) {
			x=N[i];
			int want=(1<<30)-1-cur;
			
			for(j=29;j>=0;j--) {
				if(want&(1<<j)) {
					if(x&(1<<j)) {
						cur|=1<<j;
					}
				}
				else if(x&(1<<j)) {
					x=(1<<30)-1;
				}
			}
		}
		cout<<cur<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
