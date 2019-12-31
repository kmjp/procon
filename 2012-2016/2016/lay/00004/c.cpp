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

int T;
int M;
ll N;
ll A[505*505];
ll U[505*505];

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>T;
	while(T--) {
		cin>>x>>y>>N;
		M=x*y;
		ll S=0;
		FOR(i,M) cin>>A[i], S+=A[i];
		if(S<0) {
			FOR(i,M) A[i]=-A[i];
			S=-S;
		}
		sort(A,A+M);
		ll num=0;
		FOR(i,M) {
			U[i]=S/M+(i<(S%M));
			if(A[i]>U[i]) num+=A[i]-U[i];
		}
		
		if(num<=N) FOR(i,M) A[i]=U[i];
		else {
			FOR(x,2) {
				int L=M-1;
				ll S=N;
				while(1) {
					if((A[L]-A[L-1])*(M-L)<=S) {
						S-=(A[L]-A[L-1])*(M-L);
						L--;
					}
					else {
						for(i=M-L-1;i>=0;i--) A[L+i]=A[L]-(S/(M-L)+(i<S%(M-L)));
						break;
					}
				}
				reverse(A,A+M);
				FOR(i,M) A[i]=-A[i];
			}
		}
		
		
		ll tot=0;
		FOR(i,M) tot+=1LL*A[i]*A[i];
		cout<<tot<<endl;
		
	}

}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
