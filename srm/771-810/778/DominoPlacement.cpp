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

ll from[1<<17];
ll to[1<<17];
const ll mo=1000000007;

int A[303];

class DominoPlacement {
	public:
	int countWays(vector <string> T) {
		int H=T.size();
		int W=T[0].size();
		ZERO(A);
		
		int y,x,mask;
		if(W>H) {
			FOR(y,H) FOR(x,W) if(T[y][x]=='#') A[x] |= 1<<y;
			swap(H,W);
		}
		else {
			FOR(y,H) FOR(x,W) if(T[y][x]=='#') A[y] |= 1<<x;
		}
		
		ZERO(from);
		from[0]=1;
		FOR(y,H) {
			
			ZERO(to);
			FOR(mask,1<<W) {
				if(mask&1) continue;
				int cmask=mask|(mask>>1);
				if(A[y]&cmask) continue;
				//cout<<y<<" "<<mask<<endl;
				int cand=((1<<W)-1)^(A[y]|cmask);
				for(int sub=cand;sub>=0;sub--) {
					sub&=cand;
					(to[cand]+=from[sub])%=mo;
				}
				to[cand]%=mo;
			}
			

			swap(from,to);
			FOR(x,W) FOR(mask,1<<W) if((mask&(1<<x))==0) (from[mask]+=from[mask^(1<<x)])%=mo;
		}
		
		return from[0];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, countWays(Arg0)); }
	void test_case_1() { string Arr0[] = {".#",
 ".."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, countWays(Arg0)); }
	void test_case_2() { string Arr0[] = {".#.",
 "#..",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; verify_case(2, Arg1, countWays(Arg0)); }
	void test_case_3() { string Arr0[] = {"#######.#####",
 "...#....#....",
 "...#....#....",
 "...#....#....",
 "...#....#####"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 426089093; verify_case(3, Arg1, countWays(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  DominoPlacement ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

