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
int V[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int ret=0;
	int L=-1,R=-1;
	FOR(i,N) {
		cin>>x;
		if(L==-1) {
			L=R=x;
			ret++;
		}
		else if(L==R || R==x) {
			R=x;
		}
		else {
			if(L<R) {
				if(x<R) {
					L=R=x;
					ret++;
				}
				else {
					R=x;
				}
			}
			else {
				if(x<R) {
					R=x;
				}
				else {
					L=R=x;
					ret++;
				}
			}
		}
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
