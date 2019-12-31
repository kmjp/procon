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
int from[6000];
int to[6000];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,6000) from[i]=-1<<30;
	from[3001]=0;
	
	cin>>N;
	while(N--) {
		memmove(to,from,sizeof(to));
		cin>>x>>y;
		x--;
		FOR(i,6000) {
			k=min(5999,max(0,i+x));
			to[k]=max(to[k],from[i]+y);
		}
		memmove(from,to,sizeof(to));
	}
	
	cout<<*max_element(from+3000,from+6000)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
