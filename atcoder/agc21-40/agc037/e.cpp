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


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>S;
	
	char mi=*min_element(ALL(S));
	
	string R="{";
	FOR(i,N) if(S[i]==mi) {
		int cnt=0;
		FOR(cnt,N) if(i+cnt==N || S[i+cnt]!=mi) break;
		
		string T=S.substr(i,cnt);
		if(i+cnt==N) {
			FOR(j,K) {
				T=T+T;
				if(T.size()>=N) break;
			}
			x=i-1;
			while(T.size()<N) {
				if(x>=0) T+=S[x];
				else T+=S[-x+1];
				x--;
			}
		}
		else {
			FOR(j,K-1) {
				T=T+T;
				if(T.size()>=N) break;
			}
			x=i+cnt;
			while(T.size()<N) {
				if(x<N) T+=S[x];
				else T+=S[2*N-1-x];
				x++;
			}
		}
		if(T.size()>N) T.resize(N);
		R=min(R,T);
		
	}
	
	
	
	cout<<R<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
