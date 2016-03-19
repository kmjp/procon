#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int D[21][200];

class DoubleWeights {
	public:
	int minimalCost(vector <string> W1, vector <string> W2) {
		int N=W1.size();
		int i;
		memset(D,0x3f,sizeof(D));
		D[0][0]=0;
		priority_queue<pair<int,int>> Q;
		Q.push({0,0});
		
		while(Q.size()) {
			auto r=Q.top();
			Q.pop();
			int cost=-r.first;
			int cur=r.second/1000;
			int w1=r.second%1000;
			if(D[cur][w1]!=cost) continue;
			
			FOR(i,N) if(W1[cur][i]!='.') {
				int nc1=w1+W1[cur][i]-'0';
				int nc2=cost+W2[cur][i]-'0';
				if(D[i][nc1]>nc2 && nc1<180) {
					D[i][nc1]=nc2;
					Q.push({-nc2,i*1000+nc1});
				}
			}
		}
		
		int mi=1<<30;
		FOR(i,200) if(i&&D[1][i]<300) mi=min(mi,i*D[1][i]);
		if(mi==1<<30) mi=-1;
		return mi;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"..14",
 "..94",
 "19..",
 "44.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"..94",
 "..14",
 "91..",
 "44.."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 64; verify_case(0, Arg2, minimalCost(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"..14",
 "..14",
 "11..",
 "44.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"..94",
 "..94",
 "99..",
 "44.."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 36; verify_case(1, Arg2, minimalCost(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"..",
 ".."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"..",
 ".."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = -1; verify_case(2, Arg2, minimalCost(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {".....9",
 "..9...",
 ".9.9..",
 "..9.9.",
 "...9.9",
 "9...9."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".....9",
 "..9...",
 ".9.9..",
 "..9.9.",
 "...9.9",
 "9...9."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2025; verify_case(3, Arg2, minimalCost(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {".4...1",
 "4.1...",
 ".1.1..",
 "..1.1.",
 "...1.1",
 "1...1."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {".4...1",
 "4.1...",
 ".1.1..",
 "..1.1.",
 "...1.1",
 "1...1."}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 16; verify_case(4, Arg2, minimalCost(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  DoubleWeights ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
