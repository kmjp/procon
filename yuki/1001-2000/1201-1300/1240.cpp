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

int N,X,A;
int C[18][1<<18][18][2];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N>>X;
	ll ret=0;
	FOR(i,N) {
		cin>>A;
		
		int T[18][2]={};
		
		int V=0;
		if(X==1<<18) {
			FOR(j,18) {
				T[j][0]+=C[17][0][j][0]+C[17][(1<<17)][j][0];
				T[j][1]+=C[17][0][j][1]+C[17][(1<<17)][j][1];
			}
		}
		else {
			
			for(j=17;j>=0;j--) {
				if(A&(1<<j)) {
					if(X&(1<<j)) {
						V|=1<<j;
						FOR(x,18) {
							T[x][0]+=C[j][V][x][0];
							T[x][1]+=C[j][V][x][1];
						}
						V^=1<<j;
					}
					else {
						V^=1<<j;
					}
				}
				else {
					if(X&(1<<j)) {
						FOR(x,18) {
							T[x][0]+=C[j][V][x][0];
							T[x][1]+=C[j][V][x][1];
						}
						V^=1<<j;
					}
				}
			}
		}
		
		FOR(j,18) {
			if(A&(1<<j)) {
				ret+=(T[j][0]+T[j][1])*1LL<<j;
			}
			else {
				ret+=(T[j][1])*1LL<<j;
			}
		}
		
		V=A;
		FOR(j,18) {
			V>>=j;
			V<<=j;
			FOR(x,18) C[j][V][x][(A>>x)&1]++;
		}
	}
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
