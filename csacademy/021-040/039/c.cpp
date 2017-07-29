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

ll S;
int D;
int C[20];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	ll ret=1;
	ll v=S;
	while(v) D++,v/=10;
	FOR(i,D-1) {
		cin>>C[i];
		if(C[i]==0) {
			if(S%10==9 && i && C[i-1]==1) {
				ret=0;
				break;
			}
			v=S%10;
			S=S/10;
			ret *= (v+1);
		}
		else {
			if(S%10==9 && i && C[i-1]==1) {
				v=S%10;
				S=S/10;
				ret *= (v+1);
			}
			else {
				if(S<10) {
					ret=0;
				}
				else {
					v=10+(S%10);
					S=S/10-1;
					ret *= 9-(v-10);
				}
			}
		}
	}
	ret *= S+1;
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
