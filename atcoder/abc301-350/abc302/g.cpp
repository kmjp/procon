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
int A[202020],B[202020];
int dp[4][4];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		B[i]=--A[i];
	}
	sort(B,B+N);
	FOR(i,N) if(A[i]!=B[i]) dp[A[i]][B[i]]++;
	int num=0;
	vector<int> V={0,1,2,3};
	for(i=2;i<=4;i++) {
		do {
			x=1<<30;
			FOR(j,i) {
				x=min(x,dp[V[j]][V[(j+1)%i]]);
			}
			num+=(i-1)*x;
			FOR(j,i) {
				dp[V[j]][V[(j+1)%i]]-=x;
			}
			
		} while(next_permutation(ALL(V)));
	}
	
	cout<<num<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
