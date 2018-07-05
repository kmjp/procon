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
int A[101010],L[101010];
int S[101010];

int ret;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>s;
		A[i]=s=="A";
		S[i+1]=S[i]+(A[i]?1:-1);
		cin>>s;
		L[i]=(s=="L");
	}
	
	int cur=0,nex;
	FOR(cur,N) if(L[cur]) break;
	int dif=S[cur+1];
	while(cur<N) {
		int ok=dif>=0;
		for(nex=cur+1;nex<N;nex++) if(L[nex]) break;
		
		if(nex==N) {
			dif+=S[N]-S[cur+1];
			if(dif>=0) ret++;
			break;
		}
		int best[2]={-100000,-100000};
		best[ok]=S[nex+1]-S[cur+1];
		while(cur<nex) {
			cur++;
			if(cur==nex) break;
			if(A[cur]) dif++;
			else dif--;
			best[dif>=0]=max(best[dif>=0],S[nex+1]-S[cur+1]);
		}
		
		if(best[1]>-100000) {
			ret++;
			dif=best[1];
		}
		else dif=best[0];
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}

