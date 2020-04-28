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

class DengklekGaneshAndChains {
	public:
	string getBestChains(vector <string> chains, vector <int> lengths) {
		int i;
		
		FORR(s,chains) {
			string t=s+s;
			FOR(i,s.size()) s=max(s,t.substr(i,s.size()));
		}
		
		string ret="";
		FORR(l,lengths) {
			string m="";
			FORR(c,chains) m=max(m,c.substr(0,l));
			ret += m;
			
			int id=-1;
			FOR(i,chains.size()) if(m==chains[i].substr(0,l)) {
				if(id==-1 || chains[i]<chains[id]) id=i;
			}
			chains.erase(chains.begin()+id);
		}
		
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"topc", "oder", "open", "twob"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "wotrod"; verify_case(0, Arg2, getBestChains(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"ssh", "she", "see", "sea"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 3, 2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "ssshesesee"; verify_case(1, Arg2, getBestChains(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"wri", "ter", "who", "are", "you"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "you"; verify_case(2, Arg2, getBestChains(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"harus", "imfyo"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "yoimfushar"; verify_case(3, Arg2, getBestChains(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  DengklekGaneshAndChains ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

