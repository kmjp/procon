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

class OccupiedAirplane {
	public:
	long long seat(int R, vector <int> groups, int seed) {
		int i,j;
		FOR(i,7) S[i].clear(),C[i].clear();
		int lef=R*6;
		FOR(i,R) {
			avail[i]=(1<<6)-1;
			for(j=1;j<=6;j++) S[j].insert(i);
			FOR(j,3) C[j].insert(i);
		}
		ll state=seed;
		FOR(i,600001) {
			 state = (state * 1103515245 + 12345)%(1LL<<31);
			 int g = ((state >> 10)%6) + 1;
			 groups.push_back(g);
		}
			 
		ll num=1;
		ll ret=0;
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
						avail[row]^=1<<j;
						ret+=num*(row*6+j);
						num++;
						break;
					}
				}
				else {
					row=*S[a].begin();
					FOR(i,6) if(a&&(avail[row]&(1<<i))) {
						a--;
						avail[row]^=1<<i;
						ret+=num*(row*6+i);
						num++;
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
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arr1[] = {1, 1, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 47; long long Arg3 = 60LL; verify_case(0, Arg3, seat(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 46; long long Arg3 = 2LL; verify_case(1, Arg3, seat(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1; int Arr1[] = {1, 1, 1, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 46; long long Arg3 = 59LL; verify_case(2, Arg3, seat(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 2; int Arr1[] = {1, 1, 1, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 46; long long Arg3 = 519LL; verify_case(3, Arg3, seat(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 2; int Arr1[] = {1, 1, 1, 1, 1, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 46; long long Arg3 = 342LL; verify_case(4, Arg3, seat(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  OccupiedAirplane ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

