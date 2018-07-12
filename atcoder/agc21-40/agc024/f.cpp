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

int N,K;
string S[21];

int cnt[21][1<<21];
int R[21][2];

int ID(int L,int x) {
	return (1<<L) + x;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N+1) {
		cin>>S[i];
		FOR(x,1<<i) cnt[0][ID(i,x)]=S[i][x]=='1';
	}
	
	for(i=N;i>=0;i--) {
		FOR(x,1<<i) {
			R[i][0]=R[i][1]=i;
			for(j=i-1;j>=0;j--) {
				R[j][0]=R[j+1][0];
				R[j][1]=R[j+1][1];
				int prefix = x>>(i-1-j);
				R[j][prefix&1]=j;
			}
			
			FOR(j,i) {
				int prefix = x>>(i-j);
				cnt[j][ID(j,prefix)]+=cnt[j][ID(i,x)];
				if(R[j][0]<i) {
					int nex=(prefix<<(i-R[j][0])) | (x&((1<<(i-R[j][0]))-1));
					cnt[j+1][ID(j+i-R[j][0],nex)]+=cnt[j][ID(i,x)];
				}
				if(R[j][1]<i) {
					int nex=(prefix<<(i-R[j][1])) | (x&((1<<(i-R[j][1]))-1));
					cnt[j+1][ID(j+i-R[j][1],nex)]+=cnt[j][ID(i,x)];
				}
			}
			
			if(cnt[i][ID(i,x)]>=K) {
				FOR(j,i) cout<<((x>>(i-1-j))&1);
				cout<<endl;
				return;
			}
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
