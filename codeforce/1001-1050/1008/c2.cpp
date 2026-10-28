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
string A[33],B[33];
ll X[33],Y[33];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		ll L=1,R=1,sum=0;
		FOR(i,N) {
			cin>>A[N-1-i]>>X[N-1-i]>>B[N-1-i]>>Y[N-1-i];
		}
		FOR(i,N) {
			ll ma=max(L,R);
			if(A[i]=="x") {
				L+=(X[i]-1)*ma;
			}
			else {
				sum+=X[i]*ma;
			}
			if(B[i]=="x") {
				R+=(Y[i]-1)*ma;
			}
			else {
				sum+=Y[i]*ma;
			}
		}
		cout<<sum+L+R<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
