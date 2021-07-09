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

ll P[2][2];
double Q[2][2];


class TellBagsApart {
	public:
	string whichBagIsSmaller(vector <int> records) {
		int x[2]={4,20};
		int i;
		FOR(i,2) {
			P[i][0]=x[i]*(x[i]-1);
			P[i][1]=x[i]*x[i];
			Q[i][0]=2*P[i][0]*1.0/(P[i][0]+P[i][0]+P[i][1]+P[i][1]);
			Q[i][1]=2*P[i][1]*1.0/(P[i][0]+P[i][0]+P[i][1]+P[i][1]);
		}
		
		string R;
		FOR(i,records.size()/8) {
			int A[2][2]={
				{records[i*8]+records[i*8+3],records[i*8+1]+records[i*8+2]},
				{records[i*8+4]+records[i*8+7],records[i*8+5]+records[i*8+6]},
			};
			int tar=A[0][0]+A[0][1]<A[1][0]+A[1][1];
			
			double same=1.0*A[tar][0]/(A[tar][0]+A[tar][1]);
			if(abs(Q[0][0]-same)>abs(Q[1][0]-same)) tar^=1;
			R+='1'+tar;
		}
		
		
		return R;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {262, 371, 340, 277, 303, 304, 333, 310,
 296, 326, 370, 275, 312, 329, 284, 308,
 265, 402, 372, 279, 279, 317, 307, 279,
 112, 160, 121, 102, 497, 497, 505, 506}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "1111"; verify_case(0, Arg1, whichBagIsSmaller(Arg0)); }
	void test_case_1() { int Arr0[] = {401, 405, 345, 358, 203, 295, 284, 209,
 348, 380, 396, 361, 221, 274, 307, 213,
 361, 347, 410, 347, 246, 287, 298, 204,
 301, 389, 412, 304, 253, 289, 280, 272,
 303, 450, 388, 290, 270, 286, 246, 267,
 328, 354, 326, 362, 254, 305, 309, 262,
 290, 362, 391, 296, 285, 282, 313, 281,
 338, 335, 345, 335, 220, 338, 335, 254,
 309, 356, 348, 323, 239, 344, 343, 238,
 264, 368, 365, 258, 301, 312, 328, 304,
 256, 368, 343, 295, 296, 323, 319, 300,
 275, 318, 383, 258, 320, 340, 306, 300,
 275, 301, 323, 309, 273, 372, 366, 281,
 263, 331, 290, 309, 277, 358, 395, 277,
 261, 310, 291, 259, 301, 407, 379, 292,
 256, 318, 297, 257, 325, 358, 366, 323,
 284, 287, 274, 286, 294, 406, 358, 311,
 266, 271, 282, 256, 282, 395, 429, 319,
 270, 274, 278, 268, 308, 396, 404, 302,
 203, 283, 299, 229, 368, 401, 377, 340}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "22211212211122212221"; verify_case(1, Arg1, whichBagIsSmaller(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TellBagsApart ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

