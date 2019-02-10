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


class UnreliableRover {
	public:
	long long getArea(string direction, vector <int> minSteps, vector <int> maxSteps) {
		ll XW=1,YW=1,S=0;
		vector<int> V;
		int i;
		FOR(i,direction.size()) {
			if(direction[i]=='?') {
				V.push_back(maxSteps[i]);
				S+=maxSteps[i];
			}
			if(direction[i]=='N' || direction[i]=='S') YW+=maxSteps[i]-minSteps[i];
			if(direction[i]=='W' || direction[i]=='E') XW+=maxSteps[i]-minSteps[i];
		}
		
		ll ret=XW*YW+2*(XW+YW)*S;
		
		vector<ll> Vs;
		for(int mask=0;mask<1<<V.size();mask++) {
			ll s=0;
			FOR(i,V.size()) if(mask&(1<<i)) s+=V[i];
			Vs.push_back(s);
		}
		sort(ALL(Vs));
		FOR(i,Vs.size()) if(i) ret+=(Vs[i]-Vs[i-1])*(S-Vs[i])*4;
		
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "N"; int Arr1[] = {3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 3LL; verify_case(0, Arg3, getArea(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "NE"; int Arr1[] = {3,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {5,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 9LL; verify_case(1, Arg3, getArea(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "?"; int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 9LL; verify_case(2, Arg3, getArea(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "??N?"; int Arr1[] = {0, 0, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 0, 0, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 1LL; verify_case(3, Arg3, getArea(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "??E?"; int Arr1[] = {0, 0, 3, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 3, 4, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 120LL; verify_case(4, Arg3, getArea(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  UnreliableRover ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

