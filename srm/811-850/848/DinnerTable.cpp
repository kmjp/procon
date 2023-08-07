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

class DinnerTable {
	public:
	long long count(int R, int C, int L, int N) {
		map<int,vector<int>> Rs;
		map<int,vector<int>> Cs;
		ll ret=1LL*R*max(C-L+1,0)+1LL*C*max(R-L+1,0);
		int i;
		FOR(i,N) {
			ll r=(4LL*i*i+7*i)%R;
			ll c=(1LL*i*i*i+8*i+13)%C;
			Rs[r].push_back(c);
			Cs[c].push_back(r);
		}
		FORR(rs,Rs) {
			ret-=max(C-L+1,0);
			vector<int> A=rs.second;
			A.push_back(-1);
			A.push_back(C);
			sort(ALL(A));
			FOR(i,A.size()-1) {
				int len=A[i+1]-A[i]-1;
				if(len>=L) ret+=len-L+1;
			}
		}
		FORR(rs,Cs) {
			ret-=max(R-L+1,0);
			vector<int> A=rs.second;
			A.push_back(-1);
			A.push_back(R);
			sort(ALL(A));
			FOR(i,A.size()-1) {
				int len=A[i+1]-A[i]-1;
				if(len>=L) ret+=len-L+1;
			}
		}
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 6; int Arg2 = 6; int Arg3 = 0; long long Arg4 = 5LL; verify_case(0, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 6; int Arg2 = 5; int Arg3 = 0; long long Arg4 = 16LL; verify_case(1, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 5; int Arg1 = 6; int Arg2 = 7; int Arg3 = 0; long long Arg4 = 0LL; verify_case(2, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 6; int Arg2 = 4; int Arg3 = 2; long long Arg4 = 20LL; verify_case(3, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 5; int Arg1 = 6; int Arg2 = 4; int Arg3 = 3; long long Arg4 = 20LL; verify_case(4, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 5; int Arg1 = 6; int Arg2 = 4; int Arg3 = 5; long long Arg4 = 16LL; verify_case(5, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { int Arg0 = 100000; int Arg1 = 100000; int Arg2 = 10000; int Arg3 = 20000; long long Arg4 = 17666220715LL; verify_case(6, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_7() { int Arg0 = 4; int Arg1 = 1; int Arg2 = 2; int Arg3 = 100000; long long Arg4 = 0LL; verify_case(7, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  DinnerTable ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

