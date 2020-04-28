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

class EllysRPS {
	public:
	int N,L;
	vector<string> SS[11];
	map<vector<int>,ll> hoge(vector <string> S,int L,int R) {
		char win[256];
		win['R']='P';
		win['P']='S';
		win['S']='R';
		
		int i,j;
		map<vector<int>,ll> ret;
		FORR(s,SS[R-L]) {
			vector<int> V(N,0);
			FOR(i,N) for(j=L;j<R;j++) {
				if(win[s[j-L]]==S[i][j]) V[i]++;
				else if(s[j-L]!=S[i][j]) V[i]--;
			}
			ret[V]++;
		}
		
		return ret;
	}
	
	long long getCount(vector <string> S) {
		N=S.size();
		L=S[0].size();
		
		int i,j;
		SS[0].clear();
		SS[0].push_back("");
		FOR(i,10) {
			SS[i+1].clear();
			FORR(s,SS[i]) {
				SS[i+1].push_back(s+"R");
				SS[i+1].push_back(s+"P");
				SS[i+1].push_back(s+"S");
			}
		}
		
		map<vector<int>,ll> A=hoge(S,0,L/2);
		map<vector<int>,ll> B=hoge(S,L/2,L);
		
		ll ret=0;
		FORR(r,A) {
			auto r2=r.first;
			FORR(e,r2) e=-e;
			ret += r.second*B[r2];
		}
		
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"SSRRRPRRSS", "PPRRSRRRSR", "SRPRPPSRSR", "PSSRRRPRRR", "PSRPSPRSSP", "RSRSRRRPRP"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 174LL; verify_case(0, Arg1, getCount(Arg0)); }
	void test_case_1() { string Arr0[] = {"R", "P", "S"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(1, Arg1, getCount(Arg0)); }
	void test_case_2() { string Arr0[] = {"R", "R", "R"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; verify_case(2, Arg1, getCount(Arg0)); }
	void test_case_3() { string Arr0[] = {"SRSRPSPSSPPSPR", "SRSPSSPSRRRPPR", "SRSRSSPSRPSSSS", "SSRSPPPPPPSSSS", "SSRPRSPPPPSSPP",
 "PSRSPPRRSPPSSS", "PRRRPPSRSPPSSP", "PPRRRRSRSSPPRP", "RSSRRSRPPSSRPP", "PRRRPPSRSPPSSP",
 "PRRRPPSRSPPSSP", "PSRSPPRRSPPSSS", "PRRRPPSRSPPSSP", "PSRSPPRRSPPSSS", "PSRSPPRRSPPSSS",
 "PSRSPPRRSPPSSS", "PRRRPPSRSPPSSP", "SSRPRSPPPPSSPP", "SSRPRSPPPPSSPP", "RSSRRSRPPSSRPP",
 "SRSRPSPSSPPSPR", "RSSRRSRPPSSRPP", "PSRSPPRRSPPSSS", "RSSRRSRPPSSRPP", "SSRPRSPPPPSSPP",
 "PSRSPPRRSPPSSS", "SRSRPSPSSPPSPR", "SRSRPSPSSPPSPR", "PSRSPPRRSPPSSS", "PSRSPPRRSPPSSS",
 "SSRPRSPPPPSSPP", "SRSRPSPSSPPSPR", "RSSRRSRPPSSRPP", "SRSRSSPSRPSSSS", "SSRPRSPPPPSSPP",
 "PSRSPPRRSPPSSS", "SRSRPSPSSPPSPR", "PSRSPPRRSPPSSS", "SSRPRSPPPPSSPP", "SRSRSSPSRPSSSS",
 "SRSRPSPSSPPSPR", "SRSRSSPSRPSSSS"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1014LL; verify_case(3, Arg1, getCount(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EllysRPS ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

