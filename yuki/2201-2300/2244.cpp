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

int N,M;
int A[30303];
int B[30303];

bool isprime(ll v) {
	for(ll i=2;i*i<=v;i++) if(v%i==0) return false;
	return (v!=1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>x;
		A[x]++;
	}
	FOR(i,M) {
		cin>>x;
		B[x]++;
	}
	if(A[1]+B[1]!=2) {
		cout<<1<<endl;
	}
	else {
		for(i=1;i<=30100;i++) if(A[i]+B[i]==0) break;
		for(k=i*i;k<(i+1)*(i+1);k++) {
			int a;
			for(a=1;a*a<=k;a++) if(k%a==0) {
				x=sqrt(a+0.1);
				y=sqrt(k/a+0.1);
				if(A[x]&&B[y]) break;
				if(B[x]&&A[y]) break;
			}
			if(a*a>k) {
				cout<<k<<endl;
				return;
			}
		}
		cout<<(i+1)*(i+1)<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
