#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
int S[5001];
int P[5001],num[5001];
vector<int> E[5001];
int T[5001];
ll sum;
ll dpdp[5001][5001];

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N;
	FOR(i,N) cin>>S[i], sum+=S[i];
	FOR(i,N-1) {
		cin>>x>>y;
		x--;y--;
		if(x>y) swap(x,y);
		P[y]=x;
		E[x].push_back(y);
	}
	FOR(x,5001) FOR(y,5001) dpdp[x][y]=1LL<<50;
	for(i=N-1;i>=0;i--) {
		num[i]=1;
		dpdp[i][0]=0;
		dpdp[i][1]=S[i];
		ITR(it,E[i]) {
			for(j=num[i]+num[*it];j>=2;j--) {
				for(k=1;k<=num[*it];k++) {
					if(j-k<1) break;
					dpdp[i][j]=min(dpdp[i][j],dpdp[i][j-k]+dpdp[*it][k]);
				}
			}
			num[i]+=num[*it];
		}
	}
	
	
	cin>>M;
	FOR(i,M) cin>>T[i];
	sort(T,T+M);
	reverse(T,T+M);
	ll ma=sum,ts=0;
	for(i=1;i<=M;i++) {
		ts+=T[i-1];
		ma=max(ma,sum-dpdp[0][i]+ts);
	}
	cout << ma << endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
