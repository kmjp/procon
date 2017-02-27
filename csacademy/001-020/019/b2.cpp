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
int L[101010],R[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>L[i]>>R[i];
	
	int mi=1<<30;
	FOR(x,2) {
		int cnt=x, pre=x;
		for(i=1;i<N;i++) {
			if(pre==0) {
				if(R[i-1]==L[i]) {
					pre=0;
				}
				else if(R[i-1]==R[i]) {
					pre=1;
					cnt++;
				}
				else {
					break;
				}
			}
			else {
				if(L[i-1]==L[i]) {
					pre=0;
				}
				else if(L[i-1]==R[i]) {
					pre=1;
					cnt++;
				}
				else {
					break;
				}
			}
		}
		if(i==N) mi=min(mi,cnt);
	}
	
	
	if(mi==1<<30) mi=-1;
	cout<<mi<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
