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

class Farmville {
	public:
	int N;
	
	int minTime(vector <string> s, vector <int> time, vector <int> cost, int budget) {
		int x,y,z,i;
		N=s.size();
		
		FOR(y,N) s[y]+="0";
		s.push_back(string(N,'1')+"0");
		
		time.push_back(0);
		cost.push_back(0);
		
		N++;
		
		int vis[100]={};
		FOR(y,N) FORR(r,s[y]) r-='0', vis[y]+=r;
		
		vector<int> T;
		FOR(i,52) {
			FOR(x,N) if(vis[x]==0) {
				T.push_back(x);
				FOR(y,N) if(vis[y]>0 && s[y][x]) vis[y]--;
				vis[x]=-1;
			}
		}
		
		ll ct[52];
		FOR(i,25*52) {
			ll dep[52]={}, co[52]={};
			FOR(x,N) {
				int r=T[x];
				
				ct[r]=0;
				FOR(y,N) if(s[r][y]) {
					if(ct[y]==ct[r]) dep[r] |= dep[y];
					else if(ct[y]>ct[r]) {
						ct[r]=ct[y];
						dep[r]=dep[y];
					}
				}
				co[r]=0;
				FOR(y,N) if(dep[r] & (1LL<<y)) co[r] += cost[y];
				
				if(time[r] && ((cost[r]<co[r]) || dep[r]==0)) {
					dep[r] = 1LL<<r;
					co[r]=cost[r];
				}
				else if(dep[r]==0) {
					co[r]=1LL<<40;
				}
				
				ct[r]+=time[r];
			}
			
			if(co[N-1]>budget || dep[N-1]==0) break;
			budget-=co[N-1];
			FOR(y,N) if(dep[N-1] & (1LL<<y)) time[y]--;
		}
		
		return ct[N-1];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"000",
 "000",
 "000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {25,15,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 50; int Arg4 = 6; verify_case(0, Arg4, minTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arr0[] = {"0000",
 "1000",
 "0100",
 "0010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {25,25,25,25}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {100,200,300,400}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2800; int Arg4 = 74; verify_case(1, Arg4, minTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arr0[] = {"01110",
 "00010",
 "00000",
 "00000",
 "10000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {25,10,23,12,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {123,456,789,1011,1213}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1000000000; int Arg4 = 0; verify_case(2, Arg4, minTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arr0[] = {"00",
 "00"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {25,25}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1000000000,1000000000}	; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1000000000; int Arg4 = 25; verify_case(3, Arg4, minTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { string Arr0[] = {"0000000000000000",
 "1000000000000000",
 "1000000000000000",
 "0100000000000000",
 "0110000000000000",
 "0010000000000000",
 "0001000000000000",
 "0001100000000000",
 "0000110000000000",
 "0000010000000000",
 "0000001100000000",
 "0000000110000000",
 "0000000011000000",
 "0000000000110000",
 "0000000000011000",
 "0000000000000110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {24,25,23,25,23,24,25,24,23,22,25,24,23,25,23,25}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {82912,129482,235934,3294812,523942,460492,349281,592384,
109248,2305923,340945,2304934,582396,548935,767872,423981}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 87654321; int Arg4 = 49; verify_case(4, Arg4, minTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { string Arr0[] = {"000","100","110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,18,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {242949,8471,54403957}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 53867; int Arg4 = 16; verify_case(5, Arg4, minTime(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Farmville ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
