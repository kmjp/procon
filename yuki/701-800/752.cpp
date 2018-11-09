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

int P,Q;
int L,R;

ll A[1010100],S[1010100];
int nex[1010100];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>P>>Q;
	
	nex[0]=P+1;
	for(i=1;i<=1000001;i++) {
		A[i]=P%i;
		S[i]=S[i-1]+A[i];
		nex[i]=P/(i+1)+1;
	}
	
	while(Q--) {
		cin>>L>>R;
		ll ret=0;
		
		if(R<=1000000) {
			ret=S[R]-S[L-1];
		}
		else {
			if(L<=1000000) {
				ret+=S[1000000]-S[L-1];
				L=1000001;
			}
			x=P/L;
			y=P/R;
			while(x!=y) {
				int ne=nex[x-1]-1;
				ret+=1LL*P*(ne-L+1)-1LL*x*(ne+L)*(ne-L+1)/2;
				x--;
				L=nex[x];
			}
			ret+=1LL*P*(R-L+1)-1LL*y*(R+L)*(R-L+1)/2;
			
		}
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
