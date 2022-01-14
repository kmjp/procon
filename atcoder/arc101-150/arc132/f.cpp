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

int K,N,M;
int A[1<<24];
int B[1<<24];
ll C[1<<24];
int p3[13];

int decode(string S) {
	int mask=0;
	FORR(c,S) {
		mask*=4;
		if(c=='P') mask+=2;
		if(c=='S') mask++;
	}
	return mask;
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p3[0]=1;
	FOR(i,12) p3[i+1]=p3[i]*3;
	
	
	cin>>K>>N>>M;
	FOR(i,N) {
		cin>>s;
		A[decode(s)]=1;
	}
	FOR(i,M) {
		cin>>s;
		B[decode(s)]=1;
	}
	
	int mask;
	FOR(i,K) {
		int cur=1<<(2*i);
		FOR(mask,1<<(2*K)) if((mask>>(2*i))%4==3) {
			A[mask]+=A[mask-(cur*3)];
			A[mask]+=A[mask-(cur*2)];
			A[mask]+=A[mask-(cur*1)];
			B[mask]+=B[mask-(cur*3)];
			B[mask]+=B[mask-(cur*2)];
			B[mask]+=B[mask-(cur*1)];
		}
	}
	FOR(mask,1<<(2*K)) C[mask]=1LL*A[mask]*B[mask];
	FOR(i,K) {
		int cur=1<<(2*i);
		FOR(mask,1<<(2*K)) if((mask>>(2*i))%4==3) {
			C[mask-(cur*3)]-=C[mask];
			C[mask-(cur*2)]-=C[mask];
			C[mask-(cur*1)]-=C[mask];
		}
	}

	FOR(mask,p3[K]) {
		int nm=0;
		FOR(i,K) {
			nm |= (mask/p3[i])%3*(1<<(2*i));
		}
		cout<<1LL*N*M-abs(C[nm])<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
