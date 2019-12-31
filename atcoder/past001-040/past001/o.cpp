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
int A[303030][6];
vector<int> As;
int T[202020];
double dp[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		FOR(x,6) {
			cin>>A[i][x];
			As.push_back(A[i][x]);
		}
		sort(A[i],A[i]+6);
	}
	sort(ALL(As));
	As.erase(unique(ALL(As)),As.end());
	FOR(i,N) FOR(x,6) {
		A[i][x]=lower_bound(ALL(As),A[i][x])-As.begin();
		T[A[i][x]]=i;
	}
	
	dp[N*6-1]=1;
	for(i=N*6-2;i>=0;i--) {
		double tot=1;
		FOR(x,6) tot+=dp[A[T[i+1]][x]]/6.0;
		dp[i]=max(dp[i+1],tot);
	}
	
	double ma=0;
	FOR(i,N) {
		double tot=1;
		FOR(x,6) tot+=dp[A[i][x]]/6;
		ma=max(ma,tot);
	}
	_P("%.12lf\n",ma);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
