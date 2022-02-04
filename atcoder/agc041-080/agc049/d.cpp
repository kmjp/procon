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

int N,M;
const int mo=1000000007;

int pat[502][101010];
int S[101010][502];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	
	pat[0][0]=1;
	for(int len=1;len<=450;len++) {
		FOR(x,100001) {
			pat[len][x]=pat[len-1][x];
			int add=len*(len+1)/2;
			if(x>=add) {
				pat[len][x]+=pat[len][x-add];
				if(pat[len][x]>=mo) pat[len][x]-=mo;
			}
		}
	}
	for(int len=1;len<=450;len++) {
		int add=len*(len+1)/2;
		for(x=100101;x>=0;x--) {
			if(x>=add) pat[len][x]=pat[len][x-add];
			else pat[len][x]=0;
		}
	}
	FOR(x,100101) {
		S[x][0]=pat[0][x];
		for(j=1;j<=450;j++) {
			S[x][j]=S[x][j-1]+pat[j][x];
			if(S[x][j]>=mo) S[x][j]-=mo;
		}
	}
	FOR(j,450) {
		for(x=N;x<=100100;x++) {
			S[x][j]=S[x][j]+S[x-N][j];
			if(S[x][j]>=mo) S[x][j]-=mo;
		}
	}
	
	ll ret=0;
	int lef=M;
	int L,R;
	for(x=0;x<=lef;x++) {
		for(R=0;R<min(500,N);R++) {
			if(R*(R+1)/2>lef) break;
			int y=min(449,N-(R+1));
			(ret+=1LL*S[lef-x][y]*pat[R][x])%=mo;
		}
	}
	
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
