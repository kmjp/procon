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
string S;
ll L[202020],R[202020];
ll NA[202020],NC[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	int num=0;
	int q=0;
	ll sum=0;
	FOR(i,N) {
		NA[i+1]=NA[i];
		NC[i+1]=NC[i];
		if(S[i]=='A') {
			num++;
			NA[i+1]++;
		}
		if(S[i]=='?') num++;
		if(S[i]=='C') {
			sum+=num;
			NC[i+1]++;
		}
		if(S[i]=='?') q++;
		L[i+1]=sum;
	}
	sum=num=0;
	for(i=N-1;i>=0;i--) {
		if(S[i]=='C') num++;
		if(S[i]=='?') num++;
		if(S[i]=='A') sum+=num;
		R[i]=sum;
	}
	ll ret=sum;
	int p=0;
	FOR(i,N+1) {
		ll a=L[i]+R[i]+(NA[i]+p)*((NC[N]-NC[i])+(q-p));
		if(i<N&&S[i]=='?') p++;
		ret=max(ret,a);
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
