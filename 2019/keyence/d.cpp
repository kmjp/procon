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

int H,W;
int A[1010],B[1010];
int As[1010*1010];
int Bs[1010*1010];

int C[1010][1010];

ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(As);
	MINUS(Bs);
	cin>>H>>W;
	FOR(i,H) {
		cin>>A[i];
		if(As[A[i]]>=0) return _P("0\n");
		As[A[i]]=i;
	}
	FOR(i,W) {
		cin>>B[i];
		if(Bs[B[i]]>=0) return _P("0\n");
		Bs[B[i]]=i;
	}
	
	ll ret=1;
	int cand=0;
	for(i=H*W;i>=1;i--) {
		if(As[i]>=0 && Bs[i]>=0) {
			FOR(x,W) {
				if(C[As[i]][x]==1) cand++;
				C[As[i]][x]++;
			}
			FOR(y,H) {
				if(C[y][Bs[i]]==1) cand++;
				C[y][Bs[i]]++;
			}
			
		}
		else if(As[i]>=0) {
			int pat=0;
			FOR(x,W) {
				if(C[As[i]][x]==1) cand++;
				C[As[i]][x]++;
				if(C[As[i]][x]==2) pat++;
			}
			ret=ret*pat%mo;
		}
		else if(Bs[i]>=0) {
			int pat=0;
			FOR(y,H) {
				if(C[y][Bs[i]]==1) cand++;
				C[y][Bs[i]]++;
				if(C[y][Bs[i]]==2) pat++;
			}
			ret=ret*pat%mo;
		}
		else {
			ret=ret*cand%mo;
		}
		cand--;
		
	}
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
