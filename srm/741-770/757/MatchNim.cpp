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

string S[2]={"Zara","Yvonne"};
map<vector<int>,bool> memo;
class MatchNim {
	public:
	bool win(vector <int> P) {
		sort(ALL(P));
		if(memo.count(P)) return memo[P];
		if(P.empty()) return false;
		
		int N=P.size();
		if(P.back()>=N-1) return memo[P]=true;
		
		int i,j,k;
		int did[10]={};
		FOR(i,N) {
			if(did[P[i]]) continue;
			did[P[i]]=1;
			int mask;
			FOR(mask,1<<N) if((mask&(1<<i))==0 && __builtin_popcount(mask)<=P[i]) {
				vector<int> nex;
				FOR(k,N) {
					if(k!=i&&(mask&(1<<k))==0) {
						nex.push_back(P[k]);
					}
				}
				int tot=__builtin_popcount(mask);
				for(k=max(1,tot);k<=P[i];k++) {
					if(k<P[i]) nex.push_back(P[i]-k);
					
					if(win(nex)==0) return memo[P]=1;
					if(k<P[i]) nex.pop_back();
					
				}
			}
		}
		
		return memo[P]=0;
		
	}
	
	string whoWins(vector <int> P) {
		return S[win(P)];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Zara"; verify_case(0, Arg1, whoWins(Arg0)); }
	void test_case_1() { int Arr0[] = {2, 2, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Yvonne"; verify_case(1, Arg1, whoWins(Arg0)); }
	void test_case_2() { int Arr0[] = {3, 1, 3, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Zara"; verify_case(2, Arg1, whoWins(Arg0)); }
	void test_case_3() { int Arr0[] = {1, 3, 3, 3, 4, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Yvonne"; verify_case(3, Arg1, whoWins(Arg0)); }
	void test_case_4() { int Arr0[] = {23, 6, 1, 1, 4, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Yvonne"; verify_case(4, Arg1, whoWins(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MatchNim ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

