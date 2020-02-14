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

int H,W,K;
string S;
ll A[101000];
ll B[101000];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K>>S;
	
	ll ret=0;
	if(S=="+") {
		map<int,int> M;
		FOR(x,W) {
			cin>>A[x];
			M[A[x]%K]++;
		}
		FOR(y,H) {
			cin>>B[y];
			ret+=M[(K-B[y]%K)%K];
		}
	}
	else {
		map<int,int> M,M2;
		FOR(x,W) {
			cin>>A[x];
			M[__gcd(A[x],(ll)K)]++;
		}
		FOR(y,H) {
			cin>>B[y];
			M2[__gcd(B[y],(ll)K)]++;
		}
		FORR(m,M) {
			FORR(m2,M2) {
				if(1LL*m.first*m2.first%K==0) ret+=1LL*m.second*m2.second;
			}
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
