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

int H,N;
int W[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>N;
	FOR(i,N-1) cin>>W[i];
	W[N-1]=H;
	sort(W,W+N);
	reverse(W,W+N);
	
	FOR(i,N) if(W[i]==H) {
		int x=i+1;
		if(x%10==1) cout<<x<<"st"<<endl;
		else if(x%10==2) cout<<x<<"nd"<<endl;
		else if(x%10==3) cout<<x<<"rd"<<endl;
		else cout<<x<<"th"<<endl;
		return;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
