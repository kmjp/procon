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

class SquareCutout {
	public:
	int verify(vector <string> C) {
		int H=C.size();
		int W=C[0].size();
		int L=100,R=-1,U=100,D=-1;
		int x,y;
		FOR(y,H) FOR(x,W) if(C[y][x]=='#') {
			L=min(L,x);
			R=max(R,x);
			U=min(U,y);
			D=max(D,y);
		}
		if(L==100) return 1;
		for(y=U;y<=D;y++) for(x=L;x<=R;x++) if(C[y][x]=='.') return 0;
		int w=R-L+1;
		int h=D-U+1;
		if((L==0)||(R==W-1)) w=max(w,h);
		if((U==0)||(D==H-1)) h=max(w,h);
		if((L==0)||(R==W-1)) w=max(w,h);
		if((U==0)||(D==H-1)) h=max(w,h);
		if(w!=h) return 0;
		return w;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".....",
 "..##.",
 "..##.",
 ".....",
 "....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, verify(Arg0)); }
	void test_case_1() { string Arr0[] = {"...",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, verify(Arg0)); }
	void test_case_2() { string Arr0[] = {".....",
 ".###.",
 ".#.#.",
 ".###.",
 "....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, verify(Arg0)); }
	void test_case_3() { string Arr0[] = {"..####",
 "..####",
 "......"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(3, Arg1, verify(Arg0)); }
	void test_case_4() { string Arr0[] = {"..#..",
 ".###.",
 "#####",
 ".###.",
 "..#.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(4, Arg1, verify(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SquareCutout ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

