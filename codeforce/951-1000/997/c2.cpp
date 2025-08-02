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
int A[101];

int B[]={15,8,8,8,15,5,8,1,15,5,8,15,15,15,8};
int C[]={7,3,3,7,5,3,7,7,3};
int D[]={1,1,2,3,1,2,3,4};

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		
		if(N>=15) {
			FOR(i,15) {
				if(i) cout<<" ";
				cout<<B[i];
			}
			for(i=16;i<=N;i++) cout<<" "<<i;
		}
		else if(N>=9) {
			FOR(i,9) {
				if(i) cout<<" ";
				cout<<C[i];
			}
			for(i=10;i<=N;i++) cout<<" "<<i;
		}
		else {
			FOR(i,N) {
				if(i) cout<<" ";
				cout<<D[i];
			}
		}
		cout<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
