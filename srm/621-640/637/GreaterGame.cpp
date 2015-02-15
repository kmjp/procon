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

class GreaterGame {
	public:
	double calc(vector <int> hand, vector <int> sothe) {
		int N=hand.size();
		double w=0;
		int i,j,vis[101];
		vector<int> H,S,S2;
		ZERO(vis);
		
		FOR(i,N) vis[hand[i]]=1;
		FOR(i,N) if(sothe[i]!=-1) vis[sothe[i]]=1,S.push_back(sothe[i]);
		for(i=1;i<=2*N;i++) if(vis[i]==0) S2.push_back(i);
		H=hand;
		sort(H.begin(),H.end());
		sort(S.begin(),S.end());
		
		FOR(i,S.size()) {
			int ok=0;
			FOR(j,H.size()) if(H[j]>S[i]) {
				w+=1;
				ok=1;
				H.erase(H.begin()+j);
				break;
			}
			if(ok==0) H.erase(H.begin());
		}
		FOR(i,H.size()) FOR(j,S2.size()) if(H[i]>S2[j]) w += 1.0/H.size();
		
		return w;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {4,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.5; verify_case(0, Arg2, calc(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {4,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 2.0; verify_case(1, Arg2, calc(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(2, Arg2, calc(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,3,5,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8,-1,4,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 2.5; verify_case(3, Arg2, calc(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {6,12,17,14,20,8,16,7,2,15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1,4,-1,11,3,13,-1,-1,18}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 8.0; verify_case(4, Arg2, calc(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  GreaterGame ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
