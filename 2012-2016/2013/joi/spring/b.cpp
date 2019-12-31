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

int N,Q;
int R[1<<20],C[1<<20];
int Rs[21][1<<20],RSS[21];
int Cs[21][1<<20],CSS[21];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	ll all=0;
	for(i=1;i<=N;i++) {
		RSS[i]=1<<(N-i);
		CSS[i]=1<<(N-i);
		all+=1LL*RSS[i]*CSS[i];
	}
	
	while(Q--) {
		
		cin>>i>>x;
		x--;
		if(i==0) {
			R[x]^=1;
			r=R[x];
			for(j=1;j<=N;j++) {
				x>>=1;
				RSS[j]-=(Rs[j][x]==0 || Rs[j][x]==1<<j);
				if(r==0) Rs[j][x]--;
				else Rs[j][x]++;
				RSS[j]+=(Rs[j][x]==0 || Rs[j][x]==1<<j);
			}
		}
		else {
			C[x]^=1;
			r=C[x];
			for(j=1;j<=N;j++) {
				x>>=1;
				CSS[j]-=(Cs[j][x]==0 || Cs[j][x]==1<<j);
				if(r==0) Cs[j][x]--;
				else Cs[j][x]++;
				CSS[j]+=(Cs[j][x]==0 || Cs[j][x]==1<<j);
			}
		}
		
		ll same=0;
		for(i=1;i<=N;i++) {
			same+=1LL*RSS[i]*CSS[i];
		}
		cout<<(all-same)*4+1<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
