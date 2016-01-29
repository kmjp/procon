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

int is[1010][1010];

class BearSpans {
	public:
	vector <int> findAnyGraph(int n, int m, int k) {
		int x,y,i;
		if(k>10 || n<1<<k) return {-1};
		
		ZERO(is);
		
		vector<int> R;
		vector<pair<int,int>> V;
		FOR(i,1<<(k-1)) V.push_back({i*2+1,i*2+2});
		V.back().second=n;
		
		FORR(r,V) for(x=r.first;x<r.second;x++) R.push_back(x),R.push_back(x+1), is[x][x+1]++, m--;
		
		while(V.size()>1) {
			vector<pair<int,int>> V2;
			FOR(i,V.size()/2) {
				R.push_back(V[i*2].first);
				R.push_back(V[i*2+1].first);
				m--;
				is[V[i*2].first][V[i*2+1].first]++;
				V2.push_back({V[i*2].first,V[i*2+1].second});
			}
			swap(V,V2);
		}
		FOR(y,n) FOR(x,y) if(is[x+1][y+1]==0 && m) m--, R.push_back(x+1),R.push_back(y+1);
		return R;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 17; int Arg1 = 22; int Arg2 = 1; int Arr3[] = {1, 2, 1, 3, 1, 4, 1, 5, 1, 6, 1, 7, 1, 8, 1, 9, 1, 10, 1, 11, 1, 12, 1, 13, 1, 14, 1, 15, 1, 16, 1, 17, 2, 3, 2, 8, 3, 9, 8, 9, 10, 12, 12, 14 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, findAnyGraph(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 9; int Arg1 = 12; int Arg2 = 3; int Arr3[] = {6, 5, 7, 6, 1, 2, 3, 4, 8, 9, 3, 5, 7, 4, 1, 9, 6, 2, 6, 1, 1, 8, 4, 5 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, findAnyGraph(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 9; int Arg1 = 12; int Arg2 = 7; int Arr3[] = {-1 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, findAnyGraph(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1000; int Arg1 = 999; int Arg2 = 970; int Arr3[] = {-1 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, findAnyGraph(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 1; int Arr3[] = {1, 2 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(4, Arg3, findAnyGraph(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 1; int Arr3[] = {1, 2, 1, 3 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(5, Arg3, findAnyGraph(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 2; int Arr3[] = {-1 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(6, Arg3, findAnyGraph(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BearSpans ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
