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

string S[101];
map<int,int> M[101];
set<int> T;

class ContestScoreboard {
	public:
	vector <int> findWinner(vector <string> scores) {
		int N=scores.size();
		int i;
		
		T.clear();
		T.insert(0);
		FOR(i,N) {
			int x,y;
			string del;
			FORR(r,scores[i]) if(r=='/') r=' ';
			stringstream ss(scores[i]);
			ss>>S[i];
			M[i].clear();
			while(ss>>x>>y) M[i][y] += x, T.insert(y);
			
		}
		vector<int> ret(N);
		vector<ll> sc(N);
		FORR(r,T) {
			int win=0;
			FOR(i,N) {
				sc[i] += M[i][r];
				if(sc[i]>sc[win] || (sc[i]==sc[win] && S[i]<S[win])) win=i;
			}
			ret[win]=1;
		}
		
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"TVG 1/1 1/2 1/3", "AJI 1/4 1/5 1/6"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, findWinner(Arg0)); }
	void test_case_1() { string Arr0[] = {"GLP 1/114 1/195 1/171 1/19 1/146 1/29","BKPF 1/57 1/187 1/277 1/21 1/223 1/35"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, findWinner(Arg0)); }
	void test_case_2() { string Arr0[] = {"AAA 248/2 495/5 993/7","BBB 244/6 493/7 990/10", "CCC 248/2 495/5 993/10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 0, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, findWinner(Arg0)); }
	void test_case_3() { string Arr0[] = {"UBA 10/2 30/4 25/3 999/1000", "UNC 1/3 3/20 40/50", "UNLP 2/2 3/3 4/4 100/100", "UNR 999/1000000 999/999999", "UNS 999/100000000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 0, 1, 1, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, findWinner(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ContestScoreboard ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
