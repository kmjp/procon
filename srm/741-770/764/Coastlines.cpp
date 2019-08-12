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

template<int um> class UF {
	public:
	vector<int> par,rank;
	UF() {rank=vector<int>(um,0); for(int i=0;i<um;i++) par.push_back(i);}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};

class Coastlines {
	public:
	int longest(vector <string> M) {
		UF<2500> uf;
		int H=M.size();
		int W=M[0].size();
		int C[2500]={};
		int y,x;
		FOR(y,H) FOR(x,W) {
			if(y && M[y][x]==M[y-1][x]) uf(y*W+x,y*W+x-W);
			if(x && M[y][x]==M[y][x-1]) uf(y*W+x,y*W+x-1);
		}
		int ma=0;
		FOR(y,H) FOR(x,W) if(M[y][x]=='X') {
			int cnt=0;
			if(y==0 || M[y-1][x]=='.') cnt++;
			if(y==H-1 || M[y+1][x]=='.') cnt++;
			if(x==0 || M[y][x-1]=='.') cnt++;
			if(x==W-1 || M[y][x+1]=='.') cnt++;
			C[uf[y*W+x]]+=cnt;
			ma=max(ma,C[uf[y*W+x]]);
		}
		return ma;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"...",
 ".X.",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, longest(Arg0)); }
	void test_case_1() { string Arr0[] = {".XX",
 ".X.",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(1, Arg1, longest(Arg0)); }
	void test_case_2() { string Arr0[] = {"."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, longest(Arg0)); }
	void test_case_3() { string Arr0[] = {".XX...",
 "XX...X",
 "X...XX",
 "......",
 ".XXXX."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(3, Arg1, longest(Arg0)); }
	void test_case_4() { string Arr0[] = {"XXX",
 "X.X",
 "XXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(4, Arg1, longest(Arg0)); }
	void test_case_5() { string Arr0[] = {"XXXXX",
 "X...X",
 "X.X.X",
 "X...X",
 "XXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 32; verify_case(5, Arg1, longest(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Coastlines ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

