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

int N;
int D[1010];
vector<int> E[1010];

ll upper[1010];
ll up[1010][2];
ll down[1010][2];
ll cl[1010],dl[1010];

ll mo=1000000007;

class DengklekGaneshAndTree {
	public:
	int getCount(string labels, vector <int> parents) {
		
		int i;
		N=parents.size()+1;
		FOR(i,N) {
			E[i].clear();
			dl[i]=1;
		}
		FOR(i,N-1) {
			D[i+1]=D[parents[i]]+1;
			E[parents[i]].push_back(i+1);
		}
		
		for(i=N-1;i>=0;i--) {
			down[i][0]=down[i][1]=1;
			FORR(e,E[i]) {
				if(labels[i]==labels[e]) {
					(down[i][0]*=down[e][0])%=mo;
					(down[i][1]*=down[e][1])%=mo;
				}
				else {
					(down[i][0]*=down[e][0]+down[e][1])%=mo;
					(down[i][1]*=down[e][0]+down[e][1])%=mo;
				}
			}
			(dl[D[i]]*=down[i][0])%=mo;
		}
		
		ll ret=down[0][0]+down[0][1];
		ZERO(upper);
		
		int lv;
		FOR(lv,N) {
			ZERO(up);
			
			int ok=0;
			FOR(i,N) if(D[i]==lv) up[i][0]=ok=1;
			if(ok==0) break;
			
			FOR(i,N) cl[i]=1;
			for(i=N-1;i>=0;i--) if(D[i]<lv) {
				up[i][0]=up[i][1]=1;
				FORR(e,E[i]) {
					if(labels[i]==labels[e]) {
						(up[i][0]*=up[e][0])%=mo;
						(up[i][1]*=up[e][1])%=mo;
					}
					else {
						(up[i][0]*=up[e][0]+up[e][1])%=mo;
						(up[i][1]*=up[e][0]+up[e][1])%=mo;
					}
				}
				(cl[D[i]]*=up[i][0])%=mo;
			}
			
			upper[lv]=(up[0][0]+up[0][1])%mo;
			for(i=lv-1;i>=0;i--) (upper[lv]+=mo-cl[i]*upper[i]%mo)%=mo;
			(ret += mo-upper[lv]*dl[lv]%mo)%=mo;
		}
		
		return (ret%mo+mo)%mo;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "seems"; int Arr1[] = {0, 1, 0, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(0, Arg2, getCount(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "like"; int Arr1[] = {0, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; verify_case(1, Arg2, getCount(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "a"; int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(2, Arg2, getCount(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "coincidence"; int Arr1[] = {0, 1, 2, 0, 2, 1, 4, 7, 7, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 218; verify_case(3, Arg2, getCount(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "topcoderopenroundtwobgoodluckhavefun"; int Arr1[] = {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 147418098; verify_case(4, Arg2, getCount(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  DengklekGaneshAndTree ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

