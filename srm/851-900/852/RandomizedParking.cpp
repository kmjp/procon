#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

double pat[1<<20];
class RandomizedParking {
	public:
	double solve(string start, int K) {
		int mat=0;
		int N=start.size();
		int i,x,y;
		FOR(i,N) if(start[i]=='X') mat|=1<<i;
		double sum=0;
		int mask;
		FOR(mask,1<<N) pat[mask]=0;
		pat[mat]=1;
		FOR(mask,1<<N) if(pat[mask]) {
			
			FOR(x,N) {
				FOR(y,N) {
					if((mask&(1<<((x+y)%N)))==0) {
						if(__builtin_popcount(mask)==__builtin_popcount(mat)+K-1) {
							sum+=y*pat[mask]/N;
						}
						else {
							pat[mask|(1<<((x+y)%N))]+=pat[mask]/N;
						}
						break;
					}
				}
			}
			
		}
		
		return sum;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "....."; int Arg1 = 1; double Arg2 = 0.0; verify_case(0, Arg2, solve(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "X.X.X.X."; int Arg1 = 1; double Arg2 = 0.5; verify_case(1, Arg2, solve(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "X.X..XX."; int Arg1 = 4; double Arg2 = 3.5; verify_case(2, Arg2, solve(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "......."; int Arg1 = 2; double Arg2 = 0.14285714285714285; verify_case(3, Arg2, solve(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "X.X....X"; int Arg1 = 2; double Arg2 = 0.921875; verify_case(4, Arg2, solve(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  RandomizedParking ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

