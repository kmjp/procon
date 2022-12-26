#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int T;
string S;
int G[1010101];
int P[1010101];
int M[1010101];

int NG[1010101],NP[1010101];
int L;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	int mp=10000000;
	while(T--) {
		cin>>S;
		L=S.size();
		FOR(i,L+10) {
			NP[i]=(i)?NP[i-1]:0;
			M[i]=1010100;
			if(i+6>=L) P[i]=1010100;
			else {
				P[i]=0;
				FOR(x,7) if(S[i+x]!="problem"[x]) P[i]++;
				if(P[i]==0) NP[i]++;
			}
		}
		int mi=1010;
		for(i=L;i>=0;i--) M[i]=min(P[i],M[i+1]);
		FOR(i,L-4) {
			NG[i]=(i)?NG[i-1]:0;
			int cnt=0;
			FOR(x,4) if(S[i+x]!="good"[x]) cnt++;
			mi=min(mi,cnt+M[i+4]+((i>=4)?NG[i-4]:0)+((i>=7)?NP[i-7]:0));
			if(cnt==0) NG[i]++;
		}
		cout<<mi<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
