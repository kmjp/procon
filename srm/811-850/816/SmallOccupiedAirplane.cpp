#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int avail[101010];
set<int> S[7];
set<int> C[7];

class SmallOccupiedAirplane {
	public:
	vector <string> seat(int R, vector <int> groups) {
		int i,j;
		FOR(i,7) S[i].clear(),C[i].clear();
		int lef=R*6;
		FOR(i,R) {
			avail[i]=(1<<6)-1;
			for(j=1;j<=6;j++) S[j].insert(i);
			FOR(j,3) C[j].insert(i);
		}
			 
		vector<string> ret;
		FORR(g,groups) {
			vector<int> G;
			if(g>lef) break;
			lef-=g;
			if(S[g].size()) {
				G.push_back(g);
			}
			else {
				while(g--) G.push_back(1);
			}
			FORR(a,G) {
				int row;
				if(a==1) {
					vector<int> O={0,2,1};
					FORR(i,O) if(C[i].size()) {
						row=*C[i].begin();
						j=i;
						if((avail[row]&(1<<j))==0) j=5-j;
						ret.push_back(to_string(row+1)+(char)('A'+j));
						avail[row]^=1<<j;
						break;
					}
				}
				else {
					row=*S[a].begin();
					FOR(i,6) if(a&&(avail[row]&(1<<i))) {
						a--;
						avail[row]^=1<<i;
						ret.push_back(to_string(row+1)+(char)('A'+i));
					}
				}
				
				FOR(j,7) S[j].erase(row),C[j].erase(row);
				for(j=1;j<=6;j++) if(__builtin_popcount(avail[row])>=j) S[j].insert(row);
				FOR(j,6) if(avail[row]&(1<<j)) C[min(j,5-j)].insert(row);
			}
		}
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 1; int Arr1[] = {1, 1, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1A", "1F", "1B", "1C", "1D", "1E" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, seat(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 10; int Arr1[] = {2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1A", "1B", "1F" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, seat(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arr1[] = {1, 1, 1, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1A", "1F", "1C", "1B", "1D", "1E" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, seat(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 2; int Arr1[] = {1, 1, 1, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1A", "1F", "2A", "2B", "2C", "2D", "2E", "2F" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, seat(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 2; int Arr1[] = {1, 1, 1, 1, 1, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1A", "1F", "2A", "2F", "1C", "1D", "2C", "2D", "1B", "1E" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, seat(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 3; int Arr1[] = {4, 4, 4, 1, 2, 1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1A", "1B", "1C", "1D", "2A", "2B", "2C", "2D", "3A", "3B", "3C", "3D", "1F", "2E", "2F", "3F", "1E", "3E" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, seat(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 12; int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = { }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(6, Arg2, seat(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SmallOccupiedAirplane ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

