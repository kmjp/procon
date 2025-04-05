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
int N;
int A[202020],B[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) cin>>A[i];
		FOR(i,N) cin>>B[i];
		map<pair<int,int>,ll> X[3];
		X[0][{0,0}]=1;
		FOR(i,N) {
			map<pair<int,int>,ll> Y[3];
			x=A[i],y=B[i];
			FORR2(a,b,X[0]) {
				Y[0][{__gcd(a.first,x),__gcd(a.second,y)}]+=b;
				Y[1][{__gcd(a.first,y),__gcd(a.second,x)}]+=b;
			}
			FORR2(a,b,X[1]) {
				Y[1][{__gcd(a.first,y),__gcd(a.second,x)}]+=b;
				Y[2][{__gcd(a.first,x),__gcd(a.second,y)}]+=b;
			}
			FORR2(a,b,X[2]) {
				Y[2][{__gcd(a.first,x),__gcd(a.second,y)}]+=b;
			}
			swap(X,Y);
		}
		int ma=0;
		ll num=0;
		FORR2(a,b,X[1]) {
			if(a.first+a.second>ma) {
				ma=a.first+a.second;
				num=0;
			}
			if(a.first+a.second==ma) num+=b;
		}
		FORR2(a,b,X[2]) {
			if(a.first+a.second>ma) {
				ma=a.first+a.second;
				num=0;
			}
			if(a.first+a.second==ma) num+=b;
		}
		cout<<ma<<" "<<num<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
