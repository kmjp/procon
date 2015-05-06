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


class Mutalisk {
	public:
	int minimalAttacks(vector <int> X) {
		set<int> T[61];
		int N=X.size();
		int i,x,y,z;
		int thr=93;
		
		for(i=1;i<=60;i++) {
			for(x=0;x*9<=i+8;x++) {
				for(y=0;y==0 || x*9+y*3<=i+2;y++) {
					z = max(0,i-x*9-y*3);
					if(x+y+z<=thr) T[i].insert(x*10000+y*100+z);
				}
			}
		}
		
		map<int,int> S;
		S[0]=0;
		
		FOR(i,N) {
			map<int,int> S2;
			FORR(r2,T[X[i]]) {
				int x2=r2/10000, y2=r2/100%100, z2=r2%100;
				FORR(r,S) {
					int x=x2+r.first/10000;
					int y=y2+r.first/100%100;
					int z=z2+r.first%100;
					if(x>thr || y>thr || z>thr) continue;
					int tar=x*10000+y*100+z;
					if(S2.count(tar)==0) S2[tar]=10000;
					S2[tar]=min(S2[tar],max(x2+y2+z2,r.second));
				}
			}
			S.clear();
			FORR(r,S2) {
				int x2=r.first/10000, y2=r.first/100%100, z2=r.first%100;
				if(x2 && S2.count(r.first-10000)) continue;
				if(y2 && S2.count(r.first-100)) continue;
				if(z2 && S2.count(r.first-1)) continue;
				if(x2&&y2&&S2.count(r.first-10100)) continue;
				if(x2&&z2&&S2.count(r.first-10001)) continue;
				if(y2&&z2&&S2.count(r.first-101)) continue;
				S.insert(r);
			}
		}
		
		int mi=100;
		FORR(r,S) mi=min(mi,max(r.first/10000,max(r.first/100%100,max(r.first%100,r.second))));
		
		return mi;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {12,10,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, minimalAttacks(Arg0)); }
	void test_case_1() { int Arr0[] = {54,18,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(1, Arg1, minimalAttacks(Arg0)); }
	void test_case_2() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, minimalAttacks(Arg0)); }
	void test_case_3() { int Arr0[] = {55,60,53}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(3, Arg1, minimalAttacks(Arg0)); }
	void test_case_4() { int Arr0[] = {60}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(4, Arg1, minimalAttacks(Arg0)); }
	void test_case_5() { int Arr0[] = {60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 93; verify_case(5, Arg1, minimalAttacks(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Mutalisk ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
