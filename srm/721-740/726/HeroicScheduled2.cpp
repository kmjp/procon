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

class HeroicScheduled2 {
	public:
	long long getcount(vector <int> start, vector <int> finish) {
		vector<int> E[16];
		int i,j,mask;
		FOR(i,start.size()) E[start[i]].push_back(finish[i]);
		
		vector<int> V;
		map<vector<int>,ll> M;
		M[V]=1;
		FOR(i,16) {
			FORR(e,E[i]) {
				map<vector<int>,ll> M2=M;
				FORR(m,M) {
					vector<int> v=m.first;
					if(v.size()<16-i) {
						v.push_back(e);
						sort(ALL(v));
						M2[v]+=m.second;
					}
				}
				swap(M,M2);
			}
			map<vector<int>,ll> M3;
			FORR(m,M) {
				vector<int> v=m.first;
				if(v.empty()) {
					M3[v]+=m.second;
				}
				else if(v[0]>=i) {
					v.erase(v.begin());
					M3[v]+=m.second;
				}
			}
			
			swap(M,M3);
		}
		
		
		
		
		return M[V];
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 4LL; verify_case(0, Arg2, getcount(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {14,14,14}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {15,15,15}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 7LL; verify_case(1, Arg2, getcount(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0,0,1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1,2,3,4,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 63LL; verify_case(2, Arg2, getcount(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0,1,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,2,2,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 12LL; verify_case(3, Arg2, getcount(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {0,0,0,2,2,2,3,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,3,4,5,3,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 427LL; verify_case(4, Arg2, getcount(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {14,14,14,14,14,14,14,14,14,14,14,14,14,
14,14,14,14,14,14,14,14,14,14,14,14,14,14,
14,14,14,14,14,14,14,14,14,14,14,14,14,14,
14,14,14,14,14,14,14,14}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 2645651289030LL; verify_case(5, Arg2, getcount(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  HeroicScheduled2 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

