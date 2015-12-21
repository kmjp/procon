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

int N,M,K,S;
int A[202020], B[202020], T[202020], C[202020];
vector<pair<int,int> > PP[2];
ll sum[2][202020];

ll num[202020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K>>S;
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>B[i];
	FOR(i,M) {
		cin>>T[i]>>C[i];
		T[i]--;
		PP[T[i]].push_back({C[i],i+1});
	}
	sort(ALL(PP[0]));
	sort(ALL(PP[1]));
	
	MINUS(num);
	FOR(i,2) FOR(j,PP[i].size()) sum[i][j+1]=sum[i][j]+PP[i][j].first;
	
	int DD=-1,PD=-1;
	ll D=1LL<<30,P=1LL<<30;
	FOR(i,N) {
		if(A[i]<D) D=A[i], DD=i;
		if(B[i]<P) P=B[i], PD=i;
		if(DD==i || PD==i) {
			FOR(j,PP[0].size()+1) {
				if(sum[0][j]*D>S) break;
				ll left=S-sum[0][j]*D;
				ll hoge=left/P;
				x=(lower_bound(sum[1],sum[1]+(PP[1].size()+1),hoge+1)-sum[1])-1;
				if(j+x>=K) {
					_P("%d\n",i+1);
					FOR(y,j)   _P("%d %d\n",PP[0][y].second,DD+1);
					FOR(y,K-j) _P("%d %d\n",PP[1][y].second,PD+1);
					return;
				}
				
			}
		}
	}
	_P("-1\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
