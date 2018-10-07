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
int X[1010],Y[1010],H[1010];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>X[i]>>Y[i]>>H[i];
	
	for(x=0;x<=100;x++) {
		for(y=0;y<=100;y++) {
			
			ll R;
			FOR(i,N) if(H[i]>0) {
				R=H[i]+abs(x-X[i])+abs(y-Y[i]);
				break;
			}
			
			FOR(i,N) if(H[i]!=max(0LL,R-abs(x-X[i])-abs(y-Y[i]))) break;
			if(i==N) {
				cout<<x<<" "<<y<<" "<<R<<endl;
				return;
			}
			
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
