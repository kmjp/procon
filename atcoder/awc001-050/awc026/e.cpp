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
int A[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>A[i];
	ll ret=0;
	multiset<int> S1,S2;
	for(int L=0,R1=0,R2=0;L<N;L++) {
		while(R1<N) {
			S1.insert(A[R1]);
			if(*S1.rbegin()-*S1.begin()<=K) {
				R1++;
			}
			else {
				S1.erase(S1.find(A[R1]));
				break;
			}
		}
		while(R2<N) {
			S2.insert(A[R2]);
			if(*S2.rbegin()-*S2.begin()<K) {
				R2++;
			}
			else {
				S2.erase(S2.find(A[R2]));
				break;
			}
		}
		if(K==0) {
			ret+=R1-L;
			if(S1.size()) S1.erase(S1.find(A[L]));
		}
		else {
			ret+=R1-R2;
			if(S1.size()) S1.erase(S1.find(A[L]));
			if(S2.size()) S2.erase(S2.find(A[L]));
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
