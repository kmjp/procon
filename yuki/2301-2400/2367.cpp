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
const ll mo=1000000007;

ll memo[101010][8];

ll hoge(int K,int pat) {
	if(K==0) {
		if(pat==0) return N;
		if(pat==1||pat==2||pat==3) return N-1;
		if(pat==4||pat==5) return N-2;
		return N-3;
	}
	if(memo[K][pat]>=0) return memo[K][pat];
	
	ll ret=0;
	if(pat==0) {
		ret=N*hoge(K-1,1)%mo*hoge(K-1,1)%mo*hoge(K-1,1)%mo;     // *** -> X**,X**,X**
	}
	if(pat==1) {
		ret=(N-1)*hoge(K-1,4)%mo*hoge(K-1,4)%mo*hoge(K-1,1)%mo; // A** -> AX*,AX*,X**
		ret+=hoge(K-1,2)%mo*hoge(K-1,2)%mo*hoge(K-1,1)%mo;      // A** -> AA*,AA*,A**
	}
	if(pat==2) {
		ret=(N-1)*hoge(K-1,5)%mo*hoge(K-1,4)%mo*hoge(K-1,4)%mo; // AA* -> AAX,AX*,AX*
		ret+=hoge(K-1,3)%mo*hoge(K-1,2)%mo*hoge(K-1,2)%mo;      // AA* -> AAA,AA*,AA*
	}
	if(pat==3) {
		ret=(N-1)*hoge(K-1,5)%mo*hoge(K-1,5)%mo*hoge(K-1,5)%mo; // AAA -> AAX,AAX,AAX
		ret+=hoge(K-1,3)%mo*hoge(K-1,3)%mo*hoge(K-1,3)%mo;      // AAA -> AAA,AAA,AAA
	}
	if(pat==4) {
		ret=(N-2)*hoge(K-1,6)%mo*hoge(K-1,4)%mo*hoge(K-1,4)%mo; // AB* -> ABX,AX*,BX*
		ret+=2*hoge(K-1,5)%mo*hoge(K-1,2)%mo*hoge(K-1,4)%mo;    // AB* -> AAB,AA*,AB*
	}
	if(pat==5) {
		ret=(N-2)*hoge(K-1,6)%mo*hoge(K-1,6)%mo*hoge(K-1,5)%mo; // ABB -> ABX,ABX,BBX
		ret+=hoge(K-1,5)%mo*hoge(K-1,5)%mo*hoge(K-1,5)%mo;      // ABB -> AAB,AAB,ABB
		ret+=hoge(K-1,3)%mo*hoge(K-1,5)%mo*hoge(K-1,5)%mo;      // ABB -> ABB,ABB,BBB
	}
	if(pat==6) {
		ret=(N-3)*hoge(K-1,6)%mo*hoge(K-1,6)%mo*hoge(K-1,6)%mo; // ABC -> ABX,BCX,ACX
		ret+=3*hoge(K-1,5)%mo*hoge(K-1,5)%mo*hoge(K-1,6)%mo;    // ABC -> AAB,ABC,AAC
	}
	
	return memo[K][pat]=ret%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K>>N;
	if(N==1) {
		cout<<(K==0)<<endl;
		return;
	}
	if(N==2) {
		cout<<2<<endl;
		return;
	}
	MINUS(memo);
	cout<<hoge(K,0)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
