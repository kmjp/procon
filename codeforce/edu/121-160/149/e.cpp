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

int K,N;
int A[1<<20];
int rk[1<<20];
int num[22],fix[22];

int R[1<<20];
const ll mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(R);
	scanf("%d",&K);
	
	x=0;
	for(i=1;i<=1<<19;i++) {
		if(i>(1<<x)) x++;
		rk[i]=x;
		num[x]++;
	}
	
	N=1<<K;
	
	FOR(i,N) {
		scanf("%d",&A[i]);
		if(A[i]!=-1) {
			A[i]=rk[A[i]];
			fix[A[i]]++;
		}
	}
	ll ret=1;
	FOR(i,K+1) {
		for(j=1;j<=num[i]-fix[i];j++) ret=ret*j%mo;
	}
	
	while(K>0) {
		FOR(i,1<<(K-1)) {
			x=A[i*2];
			y=A[i*2+1];
			if(x==-1&&y==-1) {
				ret=ret*2%mo;
				A[i]=-1;
			}
			else if(x==-1) {
				if(y==K) {
					A[i]=-1;
				}
				else {
					A[i]=y;
				}
			}
			else if(y==-1) {
				if(x==K) {
					A[i]=-1;
				}
				else {
					A[i]=x;
				}
			}
			else if(x>=K&&y>=K) {
				ret=0;
			}
			else if(x<K&&y<K) {
				ret=0;
			}
			else {
				A[i]=min(x,y);
			}
		}
		K--;
	}
	cout<<ret<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
