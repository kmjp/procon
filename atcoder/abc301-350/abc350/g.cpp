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

int N,Q;
const ll mo=998244353;

unordered_set<int> E[202020];
int NB[202020];
unordered_set<int> big;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	int ret=0;
	while(Q--) {
		int A,B,C;
		cin>>A>>B>>C;
		A=1+1LL*A*(1+ret)%mo%2;
		B=1+1LL*B*(1+ret)%mo%N;
		C=1+1LL*C*(1+ret)%mo%N;
		
		if(A==1) {
			E[B].insert(C);
			E[C].insert(B);
			if(E[B].size()==1000) {
				FORR(b,E[B]) {
					NB[b]++;
					if(NB[b]==2) big.insert(b);
				}
			}
			if(E[B].size()>1000) {
				NB[C]++;
				if(NB[C]==2) big.insert(C);
			}
			if(E[C].size()==1000) {
				FORR(b,E[C]) {
					NB[b]++;
					if(NB[b]==2) big.insert(b);
				}
			}
			if(E[C].size()>1000) {
				NB[B]++;
				if(NB[B]==2) big.insert(B);
			}
		}
		else {
			if(E[B].size()>=1000&&E[C].size()<1000) swap(B,C);
			ret=0;
			if(E[B].size()<1000) {
				FORR(e,E[B]) if(E[C].count(e)) ret=e;
			}
			else {
				FORR(b,big) if(E[b].count(B)&&E[b].count(C)) ret=b;
			}
			
			
			cout<<ret<<endl;
		}
		
		
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
