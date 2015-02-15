#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

class JanuszTheBusinessman {
	public:
	
	int makeGuestsReturn(vector <int> A, vector <int> D) {
		int N=A.size();
		pair<int,int> P[51];
		
		int i,x,y;
		FOR(i,N) P[i]=make_pair(D[i],A[i]);
		sort(P,P+N);
		
		int ret=0;
		int vis[51]={};
		FOR(i,N) if(vis[i]==0) {
			int td=P[i].first;
			int mi=-1;
			ret++;
			FOR(x,N) if(P[x].second<=td && td<=P[x].first) {
				if(mi==-1 || P[mi].first<P[x].first) mi=x;
			}
			FOR(x,N) {
				if(min(P[mi].first,P[x].first)-max(P[mi].second,P[x].second)>=0) vis[x]=1;
			}
		}
		
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {2, 10, 6}	; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6, 11, 9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(0, Arg2, makeGuestsReturn(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {2, 10, 23, 34, 45, 123, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {25, 12, 40, 50, 48, 187, 365}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(1, Arg2, makeGuestsReturn(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {8, 12, 20, 30, 54, 54, 68, 75}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {13, 31, 30, 53, 55, 70, 80, 76}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(2, Arg2, makeGuestsReturn(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {124, 328, 135, 234, 347, 124, 39, 99, 116, 148}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {237, 335, 146, 246, 353, 213, 197, 215, 334, 223}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(3, Arg2, makeGuestsReturn(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {154, 1, 340, 111, 92, 237, 170, 113, 241, 91, 228, 134, 191, 86, 59, 115, 277, 328, 12, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {159, 4, 341, 118, 101, 244, 177, 123, 244, 96, 231, 136, 193, 95, 64, 118, 282, 330, 17, 13}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 14; verify_case(4, Arg2, makeGuestsReturn(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  JanuszTheBusinessman ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
