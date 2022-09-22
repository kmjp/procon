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

int num[101][101010];
int from[101][101010];


class FlippingCoinSum {
	public:
	vector <int> flip(vector <int> faceUp, vector <int> faceDown, int goal) {
		int i,j;
		
		FOR(i,101) FOR(j,101000) num[i][j]=1<<30;
		
		num[0][0]=0;
		FOR(i,faceUp.size()) {
			int f=faceUp[i];
			FOR(j,100001) if(num[i][j]<1<<30) {
				if(num[i+1][j]>num[i][j]+1) {
					num[i+1][j]=num[i][j]+1;
					from[i+1][j]=j;
				}
				if(num[i+1][j+f]>num[i][j]) {
					num[i+1][j+f]=num[i][j];
					from[i+1][j+f]=j;
				}
			}
		}
		int k;
		FOR(k,faceDown.size()) {
			int f=faceDown[k];
			i=faceUp.size()+k;
			FOR(j,100001) if(num[i][j]<1<<30) {
				if(num[i+1][j]>num[i][j]) {
					num[i+1][j]=num[i][j];
					from[i+1][j]=j;
				}
				if(num[i+1][j+f]>num[i][j]+1) {
					num[i+1][j+f]=num[i][j]+1;
					from[i+1][j+f]=j;
				}
			}
		}
		
		if(num[faceUp.size()+faceDown.size()][goal]>=1<<30) return {-123456789};
		vector<int> V;
		for(i=faceUp.size()+faceDown.size();i>0;i--) {
			if(i<=faceUp.size()&&from[i][goal]==goal) V.push_back(-faceUp[i-1]);
			if(i>faceUp.size()&&from[i][goal]!=goal) V.push_back(faceDown[i-faceUp.size()-1]);
			goal=from[i][goal];
		}
		return V;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {2, 2, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; int Arr3[] = { }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(0, Arg3, flip(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {2, 2, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 14; int Arr3[] = {-5, 10 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(1, Arg3, flip(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {2, 2, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arr3[] = {-123456789 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(2, Arg3, flip(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1, 1, 1, 1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 1, 1, 1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; int Arr3[] = {1, 1, 1 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(3, Arg3, flip(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {1, 1, 2, 2, 2, 3, 3, 3, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3, 4, 5, 6, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arr3[] = {-1, -1, -2, -2, -2, -3, -3, -3, -3 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(4, Arg3, flip(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {5, 5, 5, 5, 47, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {42, 80, 174}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 147; int Arr3[] = {-100, 80 }; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); verify_case(5, Arg3, flip(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  FlippingCoinSum ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

