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
ll S,K;

int A[1<<20],B[1<<20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>S>>K;
		
		if(S%K==0) {
			cout<<K<<endl;
			continue;
		}
		if(S>=K*K) {
			cout<<max(1,(int)K-2)<<endl;
			continue;
		}
		ZERO(A);
		ZERO(B);
		A[0]=1;
		for(i=K;i>=2;i--) {
			if(i%2==K%2) {
				FOR(j,S+1) {
					if(j<i) B[j]=0;
					else B[j]=B[j-i]|A[j-i];
				}
				if(B[S]==1) break;
			}
			else {
				for(j=S;j>=0;j--) {
					if(j+i>S) A[j]=0;
					else A[j]=A[j+i]|B[j+i];
				}
			}
		}
		cout<<i<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
