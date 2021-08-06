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

class OlympicShooting {
	public:
	int win(string A,string B) {
		int N=A.size()/25;
		int i;
		int C[2][10]={},D[2]={};
		FOR(i,A.size()) {
			C[0][i/25]+=A[i]=='1';
			C[1][i/25]+=B[i]=='1';
			C[0][N]+=A[i]=='1';
			C[1][N]+=B[i]=='1';
		}
		
		for(i=N;i>=0;i--) {
			if(C[0][i]>C[1][i]) return 1;
			if(C[1][i]>C[0][i]) return 0;
		}
		
		for(i=A.size()-1;i>=0;i--) {
			if(A[i]>B[i]) return 1;
			if(A[i]<B[i]) return 0;
			
		}
		return 0;
		
		
		
	}
	vector <int> sort(vector <string> results) {
		int vis[30]={};
		vector<int> ret;
		int i,j;
		int N=results.size();
		FOR(i,N) {
			int cur=-1;
			FOR(j,N) if(vis[j]==0) {
				if(cur==-1) cur=j;
				else if(win(results[j],results[cur])) cur=j;
			}
			ret.push_back(cur);
			vis[cur]=1;
		}
		
		return ret;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"1111111111101111111111111",
 "1111111111111111111111100",
 "1111111111111111111110111",
 "1111111111111111111111111",
 "1111111111111111111110111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 0, 2, 4, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, sort(Arg0)); }
	void test_case_1() { string Arr0[] = {"11111111111011111111111110000000000000000000010000",
 "11111111111111111111111000000000000000000000001000",
 "11111111111111111111101110000000000000000000000100",
 "11111111111111111111111110000000000000000000000010",
 "11111111111111111111101110000000000000000000000001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 4, 2, 0, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, sort(Arg0)); }
	void test_case_2() { string Arr0[] = {"11111111111011111111111110000000000000000000000100",
 "11111111111111111111111000000000000000000000011000",
 "11111111111111111111101110000000000000000000000100",
 "11111111111111111111111110000000000000000000000010",
 "11111111111111111111101110000000000000000000000001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 1, 4, 0, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, sort(Arg0)); }
	void test_case_3() { string Arr0[] = {"00000000000000000000000000000000000000000000000000",
 "00000000000000000000000000000000000000000000000000",
 "00000000000000000000000000000000000000000000000000",
 "00000000000000000000000000000000000000000000000000",
 "00000000000000000000000000000000000000000000000000",
 "00000000000000000000000000000000000000000000000000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 2, 3, 4, 5 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, sort(Arg0)); }
	void test_case_4() { string Arr0[] = {"10000000000000000000000000000000000000000000000000",
 "01000000000000000000000000000000000000000000000000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 0 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, sort(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  OlympicShooting ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

