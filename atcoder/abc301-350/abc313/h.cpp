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
int A[5050],B[5050];
ll from[5555],to[5555];
const ll mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(i,N+1) cin>>B[i];
	sort(A,A+N);
	sort(B,B+N+1);
	
	from[0]=1;
	FOR(i,N) {
		ZERO(to);
		FOR(j,i+1) if(from[j]) {
			//新規連結成分を作る。
			if(B[i+j]>=A[i]) (to[j+1]+=from[j]*(j+1))%=mo;
			//既存連結成分に追加
			if(B[i+j]>=A[i]) (to[j]+=from[j]*(2*j))%=mo;
			//既存連結成分の間
			if(j) (to[j-1]+=from[j]*(j-1))%=mo;
		}
		
		swap(from,to);
	}
	
	cout<<from[1]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
