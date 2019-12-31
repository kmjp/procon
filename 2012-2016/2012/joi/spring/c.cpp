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

int K,N;
int X[1010],Y[1010],T[1010];

int num(int L,int R,int U,int D,int t) {
	int i;
	int ret=0;
	FOR(i,N) if(L<=X[i]&&X[i]<R&&U<=Y[i]&&Y[i]<D&&T[i]!=t) ret++;
	return ret;
}


ll hoge(int L,int R,int U,int D) {
	if(R-L<=1) return 0;
	int ret[2][2][4]={};
	int i;
	int M1=(L+R)/2,M2=(U+D)/2;
	FOR(i,N) if(L<=X[i]&&X[i]<R&&U<=Y[i]&&Y[i]<D) break;
	if(i==N) return 0;
	
	FOR(i,3) {
		ret[0][0][i]=num(L,M1,U,M2,i);
		ret[0][1][i]=num(L,M1,M2,D,i);
		ret[1][0][i]=num(M1,R,U,M2,i);
		ret[1][1][i]=num(M1,R,M2,D,i);
	}
	ret[0][0][3]=hoge(L,M1,U,M2);
	ret[0][1][3]=hoge(L,M1,M2,D);
	ret[1][0][3]=hoge(M1,R,U,M2);
	ret[1][1][3]=hoge(M1,R,M2,D);
	
	int mi=1<<30;
	vector<int> C={0,1,2,3};
	do {
		int tot=0;
		tot+=ret[0][0][C[0]];
		tot+=ret[0][1][C[1]];
		tot+=ret[1][0][C[2]];
		tot+=ret[1][1][C[3]];
		mi=min(mi,tot);
	} while(next_permutation(ALL(C)));
	
	return mi;
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i]>>s;
		T[i]=(s=="J")?0:(s=="O")?1:2;
	}
	
	cout<<hoge(1,(1<<K)+1,1,(1<<K)+1)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
