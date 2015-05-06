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

class OddEvenTreeHard {
	public:
	
	bool valid(vector <string>& E) {
		int N=E.size();
		int x,y,z;
		
		bool up=true;
		while(up) {
			up=false;
			FOR(x,N) FOR(y,N) FOR(z,N) if(E[x][y]==-100 && E[y][z]+E[z][x]>=0) E[x][y]=E[y][z]^E[z][x], up=true;
		}
		
		FOR(x,N) FOR(y,N) FOR(z,N) if(E[x][y]+E[y][z]+E[z][x]>=0 && (E[x][y]^E[y][z]^E[z][x])==1) return false;
		return true;
	}
	
	vector <int> getTree(vector <string> E) {
		vector<int> invalid(1,-1);
		int x,y,z,i;
		int N=E.size();
		
		FOR(x,N) FOR(y,N) E[x][y]=(E[x][y]=='O')?1:((E[x][y]=='E')?0:-100);
		if(!valid(E)) return invalid;
		
		while(1) {
			int sx=-1,sy=-1;
			FOR(x,N) FOR(y,N) if(E[x][y]==-100 && sx==-1) sx=x,sy=y;
			if(sx==-1) break;
			
			vector<string> E2=E, E3=E;
			E2[sx][sy]=1;
			E3[sx][sy]=0;
			if(valid(E2)) E=E2;
			else if(valid(E3)) E=E3;
			else return invalid;
		}
		
		int odd=-1;
		vector<int> EE;
		FOR(i,N) if(E[0][i]==1) odd=i, EE.push_back(0),EE.push_back(i);
		if(odd==-1) return invalid;
		for(i=1;i<N;i++) if(E[0][i]==0) EE.push_back(odd),EE.push_back(i);
		
		return EE;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"???EO", "??OOE", "??EE?", "EOE?O", "O??O?"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 2, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getTree(Arg0)); }
	void test_case_02() { string Arr0[] = {"EOE",
 "OEO",
 "EOE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 2, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getTree(Arg0)); }
	void test_case_1() { string Arr0[] = {"????",
 "????",
 "????",
 "????"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 0, 3, 2, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getTree(Arg0)); }
	void test_case_2() { string Arr0[] = {"????",
 "????",
 "??O?",
 "????"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getTree(Arg0)); }
	void test_case_3() { string Arr0[] = {"??O?",
 "????",
 "E???",
 "????"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, getTree(Arg0)); }
	void test_case_4() { string Arr0[] = {"?O??",
 "??O?",
 "???O",
 "????"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 0, 3, 2, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, getTree(Arg0)); }
	void test_case_5() { string Arr0[] = {"?E??",
 "??E?",
 "???E",
 "????"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, getTree(Arg0)); }
	void test_case_6() { string Arr0[] = {"?????????????","??????????OE?","?????????????","?????????????","?????????????","?????????????","?????????????","???????E?????","???????E?????",
"?????????????","???????????O?","???????????E?","????????????E"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 0, 3, 0, 5, 0, 7, 0, 8, 0, 11, 0, 12, 2, 1, 4, 1, 6, 1, 9, 1, 10, 1 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(6, Arg1, getTree(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  OddEvenTreeHard ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
