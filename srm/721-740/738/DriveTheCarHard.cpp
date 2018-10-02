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

int from[30303];
int to[30303];

class DriveTheCarHard {
	public:
	int findMinimumFuel(int total_time, int distance) {
		int i;
		if(total_time>=300) {
			
			for(i=1;;i++) {
				distance -= total_time;
				if(distance<=0) return i;
				total_time--;
			}
		}
		FOR(i,30300) from[i]=1LL<<30;
		from[distance]=0;
		while(total_time>1) {
			for(int d=1;d<=distance;d++) if(from[d]<1LL<<30) {
				for(int ac=1;;ac++) {
					int dd=min(d,ac*total_time);
					if(from[d-dd]<=from[d]+ac*ac-50) break;
					from[d-dd]=min(from[d-dd], from[d]+ac*ac);
					if(dd==d) break;
				}
			}
			
			total_time--;
		}
		int ret=1LL<<30;
		FOR(i,distance+1) ret=min(ret,from[i]+i*i);
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 10; int Arg2 = 4; verify_case(0, Arg2, findMinimumFuel(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 33; int Arg2 = 21; verify_case(1, Arg2, findMinimumFuel(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 30000; int Arg2 = 900000000; verify_case(2, Arg2, findMinimumFuel(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 228; int Arg1 = 29595; int Arg2 = 242; verify_case(3, Arg2, findMinimumFuel(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  DriveTheCarHard ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

