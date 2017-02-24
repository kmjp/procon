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


class Softmatchd2 {
	public:
	int count(string S, string pattern) {
		vector<string> patterns;
		patterns.push_back(pattern);
		vector<pair<int,vector<int>>> from,to;
		int N=patterns.size();
		int i,st;
		
		from.clear();
		from.push_back({0,vector<int>()});
		FORR(c,S) {
			
			sort(ALL(from));
			from.erase(unique(ALL(from)),from.end());
			to.clear();
			
			FORR(r,from) {
				
				string pat[4]={"01","23","02","13"};
				FOR(st,2) {
					char c0=pat[st+(c-'a')*2][0];
					char c1=pat[st+(c-'a')*2][1];
					
					int cnt=r.first;
					vector<int> nex;
					
					FOR(i,N) if(patterns[i][0]==c0 || patterns[i][0]==c1) {
						if(patterns[i].size()==1) cnt++;
						else nex.push_back(i*100+1);
					}
					FORR(p,r.second) if(patterns[p/100][p%100]==c0 || patterns[p/100][p%100]==c1) {
						if(patterns[p/100].size()==p%100+1) cnt++;
						else nex.push_back(p+1);
					}
					
					to.push_back({cnt,nex});
				}
			}
			swap(from,to);
		}
		int ma=0;
		FORR(r,from) ma=max(ma,r.first);
		return ma;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aba"; string Arg1 = "13"; int Arg2 = 2; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "abbaa"; string Arg1 = "123"; int Arg2 = 2; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "aaaa"; string Arg1 = "1230"; int Arg2 = 1; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "ababbaaba"; string Arg1 = "0311"; int Arg2 = 3; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "aabbbabbbb"; string Arg1 = "332233"; int Arg2 = 2; verify_case(4, Arg2, count(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "aaaabbbababababababaaabaa"; string Arg1 = "02232"; int Arg2 = 9; verify_case(5, Arg2, count(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Softmatchd2 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

