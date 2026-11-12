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
ll A[1505050],B[1505050],S[505050];
const int DI=500;
ll add[DI+2][DI+2];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x>>y;
		if(y>=DI) {
			int cur=0;
			while(cur<=500000) {
				A[cur]++;
				A[cur+y-x]--;
				B[cur]-=cur-x;
				B[cur+y-x]+=cur-x;
				cur+=y-x;
				x=0;
			}
		}
		else {
			FOR(j,y) {
				add[y][j]+=x;
				x=(x+1)%y;
			}
		}
	}
	FOR(i,501010) {
		A[i+1]+=A[i];
		B[i+1]+=B[i];
		S[i]=A[i]*i+B[i];
	}
	for(i=1;i<=DI;i++) {
		FOR(j,501010) S[j]+=add[i][j%i];
	}
	
	int Q;
	cin>>Q;
	while(Q--){
		cin>>x;
		cout<<S[x]<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
