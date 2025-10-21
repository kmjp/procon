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
ll from[5050];
ll to[5050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i]>>B[i];
		from[i+1]=-1LL<<60;
	}
	for(i=N-1;i>=0;i--) {
		FOR(j,N+1) to[j]=-1LL<<60;
		FOR(j,N+1) {
			//—^‚¦‚é
			to[j+1]=max(to[j+1],from[j]+B[i]);
			//ƒ`ƒƒ[ƒW
			to[j]=max(to[j],from[j]+1LL*j*A[i]);
		}
		
		swap(from,to);
	}
	ll ma=0;
	FOR(j,N+1) ma=max(ma,from[j]);
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
