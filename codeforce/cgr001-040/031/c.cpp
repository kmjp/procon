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

int T,N,K;
int A[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		
		if(K%2) {
			FOR(i,K) cout<<N<<" ";
			cout<<endl;
		}
		else {
			FOR(i,K) A[i]=N;
			
			int num=0;
			for(i=29;i>=0;i--) {
				if(N&(1<<i)) {
					num=min(num+1,K);
					A[num-1]^=1<<i;
				}
				else {
					for(j=0;j+2<=num;j+=2) {
						A[j]^=1<<i;
						A[j+1]^=1<<i;
					}
				}
			}
			
			int xo=0;
			int sum=0;
			FOR(i,K) {
				cout<<A[i]<<" ";
				xo^=A[i];
				sum+=A[i];
			}
			cout<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
