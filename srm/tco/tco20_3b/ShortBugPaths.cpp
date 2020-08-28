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

ll from[102][52][52][27];
ll to[102][52][52][27];
int ok[31];
const ll mo=1000000007;

class ShortBugPaths {
	public:
	int count(int N, vector <int> D, int J) {
		ZERO(ok);
		ZERO(from);
		FORR(d,D) ok[d]=1;
		from[1][1][0][0]=1;
		int h,w,y,x,i,dy,dx;
		
		while(J--) {
			ZERO(to);
			for(h=1;h<=101;h++) for(w=1;w<=51;w++) {
				for(y=0;y*2<=h;y++) for(x=0;x*2<=w;x++) if(from[h][w][y][x]) {
					for(dy=-10;dy<=10;dy++) {
						for(dx=-10;dx<=10;dx++) if(ok[abs(dy)+abs(dx)]) {
							int th=h,tw=w;
							int ty=y+dy;
							int tx=x+dx;
							if(ty<0) th+=-ty, ty=0;
							if(ty>=th) th=ty+1;
							if(tx<0) tw+=-tx, tx=0;
							if(tx>=tw) tw=tx+1;
							if(th-1-ty<ty) ty=th-1-ty;
							if(tw-1-tx<tx) tx=tw-1-tx;
							if(tw>th) swap(th,tw),swap(ty,tx);
							
							(to[th][tw][ty][tx]+=from[h][w][y][x])%=mo;
							
							
						}
					}
					
				}
			}
			swap(from,to);
		}
		
		ll ret=0;
		for(h=1;h<=101;h++) for(w=1;w<=51;w++) {
			ll sum=0;
			for(y=0;y*2<=h;y++) for(x=0;x*2<=w;x++) sum+=from[h][w][y][x];
			sum%=mo;
			if(h>N) continue;
			if(w>N) continue;
			(ret+=1LL*(N+1-h)*(N+1-w)%mo*sum)%=mo;
		}
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 24; verify_case(0, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 123456789; int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 643499475; verify_case(1, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 5; int Arr1[] = {0, 10, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; int Arg3 = 38281; verify_case(2, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1000; int Arr1[] = {0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 4996000; verify_case(3, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 47; int Arr1[] = {3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; int Arg3 = 195354165; verify_case(4, Arg3, count(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ShortBugPaths ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

