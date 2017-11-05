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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K>>N;
	
	if(K%2==0) {
		FOR(i,N) {
			_P("%d%c",(i==0)?(K/2):K,(i==N-1)?'\n':' ');
		}
		return;
	}
	
	vector<int> V;
	FOR(i,N) V.push_back(K/2+1);
	FOR(i,N/2) {
		if(V.back()==1) V.pop_back();
		else {
			V.back()--;
			while(V.size()<N) V.push_back(K);
		}
	}
	
	FORR(c,V) cout<<c<<" ";
	cout<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
