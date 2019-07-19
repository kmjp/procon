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

class TwoLadders {
	public:
	long long minSteps(int sx, int lx1, int lx2, vector <int> X, vector <int> Y) {
		map<ll,pair<ll,ll>> M;
		int i;
		FOR(i,X.size()) {
			if(M.count(Y[i])==0) {
				M[Y[i]]={(ll)X[i],(ll)X[i]};
			}
			else {
				M[Y[i]].first=min(M[Y[i]].first,(ll)X[i]);
				M[Y[i]].second=max(M[Y[i]].second,(ll)X[i]);
			}
		}
		
		if(M.size()==1 && M.begin()->first==0) {
			ll x1=M[0].first,x2=M[0].second;
			return min(abs(sx-x1)+abs(x2-x1),abs(sx-x2)+abs(x2-x1));
		}
		
		
		ll L,R;
		if(M.count(0)) {
			ll x1=M[0].first,x2=M[0].second;
			L=min(abs(sx-x1)+abs(x2-x1)+abs(x2-lx1),abs(sx-x2)+abs(x2-x1)+abs(x1-lx1));
			R=min(abs(sx-x1)+abs(x2-x1)+abs(x2-lx2),abs(sx-x2)+abs(x2-x1)+abs(x1-lx2));
		}
		else {
			L=abs(sx-lx1);
			R=abs(sx-lx2);
		}
		FORR(m,M) {
			if(m.first==0) continue;
			if(m.first==M.rbegin()->first) continue;
			ll x1=m.second.first,x2=m.second.second;
			ll PL=L,PR=R;
			L=min({PL+abs(x1-lx1)+abs(x2-x1)+abs(lx1-x2),PL+abs(x2-lx1)+abs(x2-x1)+abs(lx1-x1),PR+abs(x1-lx2)+abs(x2-x1)+abs(lx1-x2),PR+abs(x2-lx2)+abs(x2-x1)+abs(lx1-x1)});
			R=min({PL+abs(x1-lx1)+abs(x2-x1)+abs(lx2-x2),PL+abs(x2-lx1)+abs(x2-x1)+abs(lx2-x1),PR+abs(x1-lx2)+abs(x2-x1)+abs(lx2-x2),PR+abs(x2-lx2)+abs(x2-x1)+abs(lx2-x1)});
		}
		ll x1=M.rbegin()->second.first,x2=M.rbegin()->second.second;
		ll ret=min({L+abs(x1-lx1)+abs(x2-x1),L+abs(x2-lx1)+abs(x2-x1),R+abs(x1-lx2)+abs(x2-x1),R+abs(x2-lx2)+abs(x2-x1)});
		return ret+M.rbegin()->first;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 0; int Arg2 = 100; int Arr3[] = {47, 42}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {0, 0}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); long long Arg5 = 37LL; verify_case(0, Arg5, minSteps(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 8; int Arg2 = 11; int Arr3[] = {10, 12}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1, 1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); long long Arg5 = 5LL; verify_case(1, Arg5, minSteps(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 8; int Arg2 = 42; int Arr3[] = {10, 12}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1, 1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); long long Arg5 = 7LL; verify_case(2, Arg5, minSteps(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 8; int Arg2 = 42; int Arr3[] = {10, 100, 12}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1, 0, 1}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); long long Arg5 = 181LL; verify_case(3, Arg5, minSteps(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 500000000; int Arg1 = 1; int Arg2 = 999999999; int Arr3[] = {0, 1000000000, 0, 1000000000, 0, 1000000000, 0, 1000000000, 0, 1000000000, 0, 1000000000, 0, 1000000000}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {1, 1, 2, 2, 3, 3, 4, 4, 7, 7, 999999947, 999999947, 900000047, 900000047}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); long long Arg5 = 8499999959LL; verify_case(4, Arg5, minSteps(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TwoLadders ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

