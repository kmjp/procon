#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,Q;
int A[101010];
ll sum[30][2];
int cur[30][2];

string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(j,30) cur[j][1]=1;
	
	FOR(i,N) cin>>A[i];
	cin>>S;
	
	FOR(i,N) {
		if(S[i]=='0') {
			FOR(j,30) FOR(x,2) {
				if((A[i]&(1<<j))==0 && cur[j][x]) {
					sum[j][x]+=1<<j;
					cur[j][x]=0;
				}
			}
		}
		else {
			FOR(j,30) FOR(x,2) {
				if((A[i]&(1<<j)) && cur[j][x]==0) {
					sum[j][x]+=1<<j;
					cur[j][x]=1;
				}
			}
		}
	}
	FOR(i,Q) {
		cin>>x;
		ll ret=0;
		FOR(j,30) ret+=sum[j][(x>>j)&1];
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
