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

int N,K;
int A[101010];
ll S[101010];
const ll mo=998244353;
int P[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>A[i];
		S[i+1]=S[i]+A[i];
		P[i+1]=P[i]+(A[i]>0);
	}
	ll ret=1;
	FOR(i,N) {
		ll s=S[i+1]-1;
		int fix=0;
		if(s>0) {
			fix=1;
			for(j=i+1;j<N&&fix;j++) {
				if(A[j]>s) fix=0;
				if(s>K) break;
				s*=2;
			}
		}
		else if(s==0) {
			fix=(P[N]-P[i+1])==0;
		}
		else if(s<0) {
			fix=1;
			for(j=i+1;j<N&&fix;j++) {
				if(A[j]>s) fix=0;
				s*=2;
			}
		}
		
		if(fix==0) ret=ret*(A[i]+K+1)%mo;
		
	}
	cout<<ret<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
