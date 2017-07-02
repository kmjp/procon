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

class ScoresSequence {
	public:
	int count(vector <int> s) {
		int N=s.size();
		sort(ALL(s));
		int i;
		int tot=N*(N+1)/2;
		vector<int> V;
		FOR(i,N) {
			s[i]-=i;
			if(s[i]>0) {
				while(s[i]&&V.size()&&V.back()<0) {
					if(V.size()==1) tot+=(i+V.back()+1)*(i+V.back()+2)/2;
					V.pop_back();
					s[i]--;
				}
				while(s[i]) V.push_back(i+1),s[i]--;
			}
			if(s[i]<0) {
				while(s[i]&&V.size()&&V.back()>0) {
					if(V.size()==1) tot+=(i-V.back()+1)*(i-V.back()+2)/2;
					V.pop_back();
					s[i]++;
				}
				while(s[i]) V.push_back(-(i+1)),s[i]++;
			}
		}
		
		return tot;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2, 0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { int Arr0[] = {1, 0, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { int Arr0[] = {1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { int Arr0[] = {0, 2, 8, 4, 3, 9, 1, 5, 7, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 55; verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { int Arr0[] = {22,20,14,13,17,15,12,18,23,15,21,26,33,5,19,9,37,0,25,28,4,12,35,32,25,7,31,6,2,29,10,33,36,27,39,28,40,3,8,38,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1422; verify_case(4, Arg1, count(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ScoresSequence ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

