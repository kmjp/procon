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
ll ret[101010];

int ask(int a,int b,int c) {
	int x;
	_P("Q %d %d %d\n",a+1,b+1,c+1);
	fflush(stdout);
	scanf("%d",&x);
	return x;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	scanf("%d",&N);
	if(N<5) return _P("A -1\n");
	
	map<vector<int>,int> M;
	vector<vector<int>> V={{0,1,2},{0,1,3},{0,1,4},{0,2,3},{0,2,4},
	                       {0,3,4},{1,2,3},{1,2,4},{1,3,4},{2,3,4}};
	int mi=2000000000,ma=0;
	FORR(r,V) {
		x = ask(r[0],r[1],r[2]);
		M[{r[0],r[1],r[2]}]=x;
		M[{r[0],r[2],r[1]}]=x;
		M[{r[1],r[0],r[2]}]=x;
		M[{r[1],r[2],r[0]}]=x;
		M[{r[2],r[0],r[1]}]=x;
		M[{r[2],r[1],r[0]}]=x;
		mi=min(mi,x);
		ma=max(ma,x);
	}
	
	vector<int> O={0,1,2,3,4};
	int A,B,C;
	do {
		if(M[{O[0],O[1],O[2]}]!=mi) continue;
		if(M[{O[2],O[3],O[4]}]!=ma) continue;
		if(M[{O[0],O[1],O[2]}]>=M[{O[0],O[1],O[3]}]) continue;
		if(M[{O[0],O[1],O[3]}]>=M[{O[0],O[1],O[4]}]) continue;
		if(M[{O[0],O[2],O[3]}]>=M[{O[1],O[2],O[3]}]) continue;
		if(M[{O[1],O[2],O[3]}]>=M[{O[1],O[2],O[4]}]) continue;
		if(M[{O[1],O[2],O[4]}]>=M[{O[2],O[3],O[4]}]) continue;
		if(M[{O[1],O[3],O[4]}]>=M[{O[2],O[3],O[4]}]) continue;
		
		A=O[0];
		B=O[2];
		C=O[4];
		ret[A]=(M[{O[0],O[1],O[2]}]+M[{O[0],O[2],O[4]}]-M[{O[2],O[3],O[4]}])/2;
		ret[B]=(M[{O[0],O[1],O[2]}]+M[{O[2],O[3],O[4]}]-M[{O[0],O[2],O[4]}])/2;
		ret[C]=(M[{O[2],O[3],O[4]}]+M[{O[0],O[2],O[4]}]-M[{O[0],O[1],O[2]}])/2;
		ret[O[1]]=M[{O[1],O[2],O[4]}]-ret[C];
		ret[O[3]]=M[{O[0],O[1],O[3]}]-ret[A];
		
		break;
		
	} while(next_permutation(ALL(O)));
	
	FOR(i,N) if(ret[i]==0) {
		x = ask(A,B,i);
		if(x==ret[A]+ret[B]) {
			x = ask(B,C,i);
			if(x<ret[B]+ret[C]) {
				ret[i]=x-ret[C];
			}
			else {
				ret[i]=x-ret[B];
			}
			
			if(ret[i]-ret[A]<ret[B]-ret[i]) B=i;
			else A=i;
			
		}
		else if(x<ret[A]+ret[B]) {
			ret[i]=x-ret[B];
		}
		else {
			ret[i]=x-ret[A];
		}
	}
	
	_P("A");
	FOR(i,N) _P(" %lld",ret[i]);
	_P("\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
