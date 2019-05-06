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

class CrazyCrazy {
	public:
	string possible(string song) {
		int N=song.size();
		
		int mask;
		set<string> S;
		int i;
		
		FOR(mask,1<<(N/2)) {
			queue<char> Q;
			FOR(i,N/2) {
				if(mask&(1<<i)) {
					Q.push(song[i]);
				}
				else {
					if(Q.empty()) break;
					if(Q.front()!=song[i]) break;
					Q.pop();
				}
			}
			if(i==N/2) {
				string s;
				while(Q.size()) s.push_back(Q.front()),Q.pop();
				S.insert(s);
			}
		}
		reverse(ALL(song));
		FOR(mask,1<<(N/2)) {
			queue<char> Q;
			FOR(i,N/2) {
				if(mask&(1<<i)) {
					Q.push(song[i]);
				}
				else {
					if(Q.empty()) break;
					if(Q.front()!=song[i]) break;
					Q.pop();
				}
			}
			if(i==N/2) {
				string s;
				while(Q.size()) s.push_back(Q.front()),Q.pop();
				reverse(ALL(s));
				if(S.count(s)) return "possible";
			}
		}
		return "impossible";
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "aabb" ; string Arg1 = "possible"; verify_case(0, Arg1, possible(Arg0)); }
	void test_case_1() { string Arg0 = "abba" ; string Arg1 = "impossible"; verify_case(1, Arg1, possible(Arg0)); }
	void test_case_2() { string Arg0 = "verylazyverylazy" ; string Arg1 = "possible"; verify_case(2, Arg1, possible(Arg0)); }
	void test_case_3() { string Arg0 = "arqmpfvvbtltlhufznkldkurrazmgebfxeamrewn" ; string Arg1 = "impossible"; verify_case(3, Arg1, possible(Arg0)); }
	void test_case_4() { string Arg0 = "aacfcfqqsmksimkoioeertbrtbhphnpnggddjjll" ; string Arg1 = "possible"; verify_case(4, Arg1, possible(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  CrazyCrazy ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

