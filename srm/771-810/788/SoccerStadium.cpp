#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


int L[505],R[505];
int U[505],D[505];
int A[505];


template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit() {int i; FOR(i,um) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<1010> uf;

class SoccerStadium {
	public:
	
	void merge(int a,int b) {
		a=uf[a];
		b=uf[b];
		if(a!=b) {
			L[a]=L[b]=min(L[a],L[b]);
			R[a]=R[b]=max(R[a],R[b]);
			U[a]=U[b]=min(U[a],U[b]);
			D[a]=D[b]=max(D[a],D[b]);
			A[a]=A[b]=A[a]+A[b];
			uf(a,b);
		}
	}
	
	int maximumGames(int H, int W, vector <string> S) {
		uf.reinit();
		
		int y,x;
		FOR(y,H) FOR(x,W) L[y*W+x]=R[y*W+x]=x, U[y*W+x]=D[y*W+x]=y, A[y*W+x]=1;
		FOR(y,H) FOR(x,W) {
			if(x<W-1&&S[2*y+1][2*x+2]!='|') merge(y*W+x,y*W+x+1);
			if(y<H-1&&S[2*y+2][2*x+1]!='-') merge((y+1)*W+x,y*W+x);
		}
		
		int i,j;
		FOR(i,500) {
			FOR(j,H*W) if(uf[j]==j) {
				int ta=(R[j]-L[j]+1)*(D[j]-U[j]+1);
				if(ta!=A[j]) {
					for(y=U[j];y<=D[j];y++) {
						for(x=L[j];x<=R[j];x++) {
							if(x<R[j]) merge(y*W+x,y*W+x+1);
							if(y<D[j]) merge((y+1)*W+x,y*W+x);
						}
					}
				}
			}
		}
		
		int ret=0;
		FOR(j,H*W) if(uf[j]==j) ret++;
		return ret;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 4; string Arr2[] = { "+-+-+-+-+" ,
  "|.|.....|" ,
  "+.+-+-+-+" ,
  "|.|.|...|" ,
  "+-+-+.+.+" ,
  "|.|.|...|" ,
  "+-+.+.+-+" ,
  "|...|...|" ,
  "+-+-+-+-+" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5; verify_case(0, Arg3, maximumGames(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; string Arr2[] = { "+-+-+-+" ,
  "|.....|" ,
  "+-+-+.+" ,
  "|.|.|.|" ,
  "+-+-+-+" ,
  "|.|.|.|" ,
  "+-+-+-+" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(1, Arg3, maximumGames(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 3; string Arr2[] = { "+-+-+-+" ,
  "|.|...|" ,
  "+.+-+.+" ,
  "|.|.|.|" ,
  "+.+.+-+" ,
  "|.|...|" ,
  "+-+-+-+" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(2, Arg3, maximumGames(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 3; string Arr2[] = { "+-+-+-+" ,
  "|.....|" ,
  "+.+-+.+" ,
  "|.|.|.|" ,
  "+.+-+.+" ,
  "|.....|" ,
  "+-+-+-+" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(3, Arg3, maximumGames(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 3; int Arg1 = 4; string Arr2[] = { "+-+-+-+-+" ,
  "|.|.|...|" ,
  "+-+-+-+-+" ,
  "|.......|" ,
  "+.+-+-+.+" ,
  "|.......|" ,
  "+-+-+-+-+" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(4, Arg3, maximumGames(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 7; int Arg1 = 9; string Arr2[] = { "+-+-+-+-+-+-+-+-+-+" ,
  "|.|...|...|...|...|" ,
  "+.+-+-+-+-+-+-+-+-+" ,
  "|.|.|...|...|...|.|" ,
  "+-+.+-+-+-+-+-+-+.+" ,
  "|.|.|.|...|...|.|.|" ,
  "+.+-+.+-+-+-+-+.+-+" ,
  "|.|.|.|.|.|.|.|.|.|" ,
  "+-+.+-+.+.+-+.+-+.+" ,
  "|.|.|...|...|.|.|.|" ,
  "+.+-+-+-+-+-+-+.+-+" ,
  "|.|...|...|...|.|.|" ,
  "+-+-+-+-+-+-+-+-+.+" ,
  "|...|...|...|...|.|" ,
  "+-+-+-+-+-+-+-+-+-+" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 25; verify_case(5, Arg3, maximumGames(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SoccerStadium ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

