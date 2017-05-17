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
string S;

int cnt[256][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K>>S;
	N=S.size();
	FORR(c,S) c-='a';
	
	int ma=0;
	x=0;
	FOR(i,N) {
		while(x<N) {
			int ma[2]={},sum[2]={};
			cnt[S[x]][x%2]++;
			FOR(j,26) sum[0]+=cnt[j][0], ma[0]=max(ma[0],cnt[j][0]);
			FOR(j,26) sum[1]+=cnt[j][1], ma[1]=max(ma[1],cnt[j][1]);
			int dif=max(0,sum[0]-ma[0])+max(0,sum[1]-ma[1]);
			if(dif>K) {
				cnt[S[x]][x%2]--;
				break;
			}
			x++;
		}
		ma=max(ma,x-i);
		
		cnt[S[i]][i%2]--;
	}
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
