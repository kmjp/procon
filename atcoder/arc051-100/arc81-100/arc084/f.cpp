#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
string S;
bitset<4000> X,P;
ll mo=998244353;
ll p2[202020];
int ng;

bitset<4000> gcd(bitset<4000> A,bitset<4000> B) {
	int i;
	for(i=3999;i>=0;i--) {
		if(A[i]==1 && B[i]==1) {
			B^=A;
			break;
		}
		if(A[i]==1) break;
		if(B[i]==1) {
			swap(A,B);
			break;
		}
	}
	
	// A>B
	while(1) {
		int x;
		for(x=i-1;x>=0;x--) if(B[x]) break;
		if(x<0) break;
		while(i>=x) {
			if(A[i]) A^=B<<(i-x);
			i--;
		}
		i=x;
		swap(A,B);
	}
	return A;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p2[0]=1;
	FOR(i,101010) p2[i+1]=p2[i]*2%mo;
	
	cin>>N>>S;
	FOR(i,S.size()) if(S[i]=='1') X[S.size()-1-i]=1;
	FOR(j,N) {
		cin>>S;
		bitset<4000> B;
		FOR(i,S.size()) if(S[i]=='1') B[S.size()-1-i]=1;
		if(j==0) P=B;
		else P=gcd(P,B);
	}
	
	ll ret=0;
	FOR(i,4000) if(P[i]) x=i;
	bitset<4000> Y;
	for(i=3999;i>=x;i--) {
		if(X[i]) ret+=p2[i-x];
		if(X[i]^Y[i]) Y^=P<<(i-x);
	}
	
	ret++;
	for(i=x-1;i>=0;i--) {
		if(Y[i]<X[i]) {
			break;
		}
		if(Y[i]>X[i]) {
			ret--;
			break;
		}
	}
	
	cout<<ret%mo<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
