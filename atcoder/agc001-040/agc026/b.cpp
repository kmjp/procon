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

int T;
ll A,B,C,D;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>A>>B>>C>>D;
		
		if(D<B || A<B) {
			cout<<"No"<<endl;
			continue;
		}
		if(C>=B-1) {
			cout<<"Yes"<<endl;
			continue;
		}
		
		D=__gcd(D,B);
		ll L=(((C+1)-A)%B+B)%B;
		ll R=(((B-1)-A)%B+B)%B;
		if(R>=L) {
			if(L/D == R/D && L%D) {
				cout<<"Yes"<<endl;
			}
			else {
				cout<<"No"<<endl;
			}
		}
		else {
			cout<<"No"<<endl;
		}
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
