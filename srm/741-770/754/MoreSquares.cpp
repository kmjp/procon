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

class MoreSquares {
	public:
	int countLocations(int N, int SX, int SY, vector <int> X, vector <int> Y) {
		int i,j;
		set<pair<int,int>> S;
		for(i=X.size();i<N;i++) {
			X.push_back((X.back()*47+42)%SX);
			Y.push_back((Y.back()*47+42)%SY);
		}
		FOR(i,N) S.insert({X[i],Y[i]});
		
		
		set<pair<int,int>> ret;
		FOR(i,N) FOR(j,N) {
			if(X[i]==X[j] && Y[i]==Y[j]) continue;
			int x3=X[i]-(Y[j]-Y[i]);
			int y3=Y[i]+(X[j]-X[i]);
			int x4=X[j]+x3-X[i];
			int y4=Y[j]+y3-Y[i];
			
			if(S.count({x3,y3})==0) continue;
			if(S.count({x4,y4})) continue;
			ret.insert({x4,y4});
			
		}
		
		
		return ret.size();
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 100; int Arg2 = 100; int Arr3[] = {3, 0, 2}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {0, 1, 2}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 1; verify_case(0, Arg5, countLocations(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 100; int Arg2 = 100; int Arr3[] = {47, 47, 47, 47, 47}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {47, 47, 47, 47, 47}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 0; verify_case(1, Arg5, countLocations(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 23; int Arg1 = 11; int Arg2 = 13; int Arr3[] = {7}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arr4[] = {0}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arg5 = 5; verify_case(2, Arg5, countLocations(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MoreSquares ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

