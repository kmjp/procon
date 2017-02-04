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

vector<int> enumdiv(int n) {
	vector<int> S;
	for(int i=1;i*i<=n;i++) if(n%i==0) {S.push_back(i); if(i*i!=n) S.push_back(n/i); }
	sort(S.begin(),S.end());
	return S;
}

int N,M,Q;
int A[101010],B[101010];
vector<int> P[101010];
ll cnt[2][101010];
int did[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=100000;i++) P[i]=enumdiv(i);
	
	cin>>N>>M>>Q;
	FOR(i,N) cin>>A[i];
	FOR(i,M) cin>>B[i];
	
	while(Q--) {
		int R1,R2,C1,C2;
		cin>>R1>>C1>>R2>>C2;
		ZERO(cnt);
		ZERO(did);
		for(i=R1;i<=R2;i++) FORR(r,P[A[i]]) cnt[0][r]++;
		
		for(i=C1;i<=C2;i++) if(did[B[i]]==0) {
			did[B[i]]=1;
			int cc[150]={};
			x=B[i];
			for(j=P[x].size()-1;j>=0;j--) cc[j]=cnt[0][P[x][j]];
			for(j=P[x].size()-1;j>=0;j--) {
				if(cc[j]) {
					cnt[1][P[x][j]]=1;
					FOR(y,j) if(P[x][j]%P[x][y]==0) cc[y]-=cc[j];
				}
			}
		}
		int ret=0;
		for(i=1;i<=100000;i++) if(cnt[1][i]) ret++;
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
