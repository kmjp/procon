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

class Subgraphs {
	public:
	vector <string> findGroups(int k) {
		vector<string> S;
		int i,j;
		FOR(i,2*k) {
			string T(2*k,'0');
			FOR(j,2*k-i) T[j]='1';
			T[i]='0';
			S.push_back(T);
		}
		
		FOR(i,k*(k-1)/2+1) S.push_back("");
		for(i=0;i<=k;i++) {
			for(j=0;j<k;j++) {
				string T(2*k,'N');
				int nk=i;
				if(i!=k) T[k+j]='Y', nk++;
				int x,y;
				FOR(x,i) T[k-1-x]='Y';
				for(x=2*k-1;x>=0;x--) {
					if(nk==k) break;
					if(T[x]=='N') T[x]='Y', nk++;
				}
				
				int num=0;
				FOR(y,2*k) FOR(x,y) if(T[x]=='Y' && T[y]=='Y' && S[x][y]=='1') num++;
				S[2*k+num]=T;
			}
		}
		return S;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 2; string Arr1[] = {"010", "100", "000", "NYY", "YYN" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, findGroups(Arg0)); }
	void test_case_1() { int Arg0 = 3; string Arr1[] = {"000000000000", "000000000000", "000000000000", "000010000000", "000100000000", "000000000000", "000000011000", "000000100000", "000000100000", "000000000011", "000000000101", "000000000110", "YYYNNNNNNNNN", "NNNYYYNNNNNN", "NNNNNNYYYNNN", "NNNNNNNNNYYY" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, findGroups(Arg0)); }
	void test_case_2() { int Arg0 = 4; string Arr1[] = {"01111000", "10111100", "11011110", "11101111", "11110000", "01110000", "00110000", "00010000", "YNNNNYYY", "YYNNNNYY", "YNYNNNYY", "YNYNNYYN", "YNYNYYNN", "YNYYNYNN", "YYYYNNNN" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, findGroups(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Subgraphs ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

