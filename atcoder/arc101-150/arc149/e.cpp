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

int N,M,K;
int B[303030],A[303030];
const ll mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N>>M>>K;
	FOR(i,N) {
		cin>>B[i];
	}
	
	if(M+K-1>=N) {
		int dif=M+K-1-N;
		FOR(i,N) A[i]=B[i];
		ZERO(B);
		FOR(i,N) {
			if(i+M-1>=N) {
				B[i]=A[(i+dif)%N];
			}
			else {
				int span=((dif)+(N-(M-1))-1-i)/(N-(M-1));
				B[i]=A[(i+1LL*span*(N-(M-1)))%N];
			}
		}
		K-=dif;
	}
	else {
		N=M+K-1;
	}
	
	vector<int> V;
	FOR(i,N) V.push_back(B[i]);
	sort(ALL(V));
	ll ret=1;
	int pre=-1;
	FOR(i,N) {
		B[i]=lower_bound(ALL(V),B[i])-V.begin();
		if(i>=N-(M-1)) {
			if(B[i]!=i) ret=0;
		}
		else if(pre<B[i]) {
			//cout<<"!"<<M<<" "<<B[i]<<endl;
			ret=ret*M%mo;
			pre=B[i];
		}
	}
	for(i=1;i<=M-1;i++) ret=ret*i%mo;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
