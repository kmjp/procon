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

ll G1,G2,P1,P2;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>G1>>P1>>G2>>P2;
	
	ll mi=101010,cur=0;
	ll ret=0;
	FOR(i,G1+1) {
		if(i*100LL/G1==P1) {
			while((cur+1+i)*100/G2<=P2) {
				cur++;
				if(cur<=G2-G1 && (cur+i)*100/G2==P2) ret=max(ret,cur);
			}
			while((cur+i)*100/G2>P2) cur--;
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
