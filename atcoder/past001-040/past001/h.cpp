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

int N,Q;
int C[202020];
int D[202020];
multiset<int> O,E;
ll TE,TO;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>C[i];
		if(i%2==0) O.insert(C[i]);
		else E.insert(C[i]);
	}
	
	cin>>Q;
	ll ret=0;
	int a;
	while(Q--) {
		cin>>i;
		if(i==1) {
			cin>>x>>a;
			x--;
			if(x%2==0 && C[x]-TO>=a) {
				ret+=a;
				O.erase(O.find(C[x]));
				C[x]-=a;
				O.insert(C[x]);
			}
			else if(x%2 && C[x]-TE>=a) {
				ret+=a;
				E.erase(E.find(C[x]));
				C[x]-=a;
				E.insert(C[x]);
			}
		}
		else if(i==2) {
			cin>>a;
			if(*O.begin()>=TO+a) {
				TO+=a;
				ret+=1LL*((N+1)/2)*a;
			}
		}
		else {
			cin>>a;
			if((*O.begin()>=TO+a) && (N<2 || *E.begin()>=TE+a)) {
				TO+=a;
				TE+=a;
				ret+=1LL*N*a;
			}
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
