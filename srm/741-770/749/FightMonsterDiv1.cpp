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

class FightMonsterDiv1 {
	public:
	ll H,A,A2,D;
	
	__int128_t dam(__int128_t v) {
		if(v==1) return A;
		v--;
		__int128_t ret=v*A;
		ret+=A2*v*(v-1)/2;
		
		__int128_t du=min((__int128_t)D,v);
		__int128_t cur=A+(v-1)*A2;
		ret+=4*cur*du;
		ret-=A2*du*(du-1)/2*4;
		
		
		return ret;
	}
	
	long long fightTime(long long hp, long long attack, int level, long long duration) {
		H=hp;
		A=attack;
		A2=A*level/100;
		D=duration;
		
		ll ret=1LL<<40;
		for(int i=39;i>=0;i--) if(dam(ret-(1LL<<i))>=H) ret-=1LL<<i;
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 201LL; long long Arg1 = 100LL; int Arg2 = 10; long long Arg3 = 10LL; long long Arg4 = 2LL; verify_case(0, Arg4, fightTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { long long Arg0 = 74900LL; long long Arg1 = 100LL; int Arg2 = 0; long long Arg3 = 2LL; long long Arg4 = 742LL; verify_case(1, Arg4, fightTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { long long Arg0 = 1000000000000LL; long long Arg1 = 1000000000000LL; int Arg2 = 100; long long Arg3 = 1000000000000LL; long long Arg4 = 1LL; verify_case(2, Arg4, fightTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { long long Arg0 = 1338LL; long long Arg1 = 100LL; int Arg2 = 1; long long Arg3 = 2LL; long long Arg4 = 6LL; verify_case(3, Arg4, fightTime(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  FightMonsterDiv1 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

