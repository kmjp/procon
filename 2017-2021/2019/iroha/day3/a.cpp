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

int A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z;

ll perf[]={6,28,496,8128,33550336,8589869056LL,137438691328LL};



void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>A>>B>>C>>D>>E>>F>>G>>H>>I>>J>>K>>L>>M>>N>>O>>P>>Q>>R>>S>>T>>U>>V>>W>>X>>Y>>Z;
	cout<<(A-B)<<endl;
	cout<<(C+D)<<endl;
	cout<<max(0,F-E+1)<<endl;
	cout<<(G+H+I)/3+1<<endl;
	
	string st[]={"a","aa","aaa","aaai","aaaji","aabaji","agabaji","dagabaji"};
	cout<<st[J-1]<<endl;
	
	FOR(i,59*61) if(i%59==K&&i%61==L) break;
	ll A1=i+(M-1)*59*61;
	ll A2=0;
	FOR(i,6) if(abs(perf[i]-A1)>=N) {
		A2=perf[i];
		break;
	}
	cout<<min(A1,A2)<<endl;
	cout<<max(A1,A2)<<endl;
	
	cout<<1LL*(O+P+Q)*(R+S+T)*(U+V+W)*(X+Y+Z)%9973<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
