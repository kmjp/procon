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

int from[51][26][18][3][3];

class ThreeProgrammers {
	public:
	string validCodeHistory(string code) {
		int i;
		int a=0,b=0,c=0;
		
		
		FORR(r,code) {
			if(r=='A') a++;
			if(r=='B') b++;
			if(r=='C') c++;
		}
		if(b>25 || c>17) return "impossible";
		
		MINUS(from);
		from[a][b][c][0][0]=0;
		int x,y,z,p,p2;
		for(z=c;z>=0;z--) for(y=b;y>=0;y--) for(x=a;x>=0;x--)
		FOR(p,3) FOR(p2,3) if(from[x][y][z][p][p2]>=0) {
			if(x) from[x-1][y][z][0][p] = p2;
			if(y && p!=1) from[x][y-1][z][1][p] = p2;
			if(z && p!=2 && p2!=2) from[x][y][z-1][2][p] = p2;
		}
		
		FOR(p,3) FOR(p2,3) if(from[0][0][0][p][p2]>=0) {
			string S;
			x=y=z=0;
			while(x!=a || y!=b || z!=c) {
				i = from[x][y][z][p][p2];
				S += 'A'+p;
				if(p==0) x++;
				if(p==1) y++;
				if(p==2) z++;
				p=p2;
				p2=i;
			}
			reverse(S.begin(),S.end());
			return S;
		}
		
		
		
		return "impossible";
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "CAB"; string Arg1 = "BCA"; verify_case(0, Arg1, validCodeHistory(Arg0)); }
	void test_case_1() { string Arg0 = "CBB"; string Arg1 = "BCB"; verify_case(1, Arg1, validCodeHistory(Arg0)); }
	void test_case_2() { string Arg0 = "BB"; string Arg1 = "impossible"; verify_case(2, Arg1, validCodeHistory(Arg0)); }
	void test_case_3() { string Arg0 = "BBA"; string Arg1 = "BAB"; verify_case(3, Arg1, validCodeHistory(Arg0)); }
	void test_case_4() { string Arg0 = "CAC"; string Arg1 = "impossible"; verify_case(4, Arg1, validCodeHistory(Arg0)); }
	void test_case_5() { string Arg0 = "ACAC"; string Arg1 = "CAAC"; verify_case(5, Arg1, validCodeHistory(Arg0)); }
	void test_case_6() { string Arg0 = "ACABC"; string Arg1 = "ACABC"; verify_case(6, Arg1, validCodeHistory(Arg0)); }
	void test_case_7() { string Arg0 = "BAABCABBCCACBAACABAABABBCCAACABCCAACCABCACACCBABAB"; string Arg1 = "BACBABCAACBACABCBACBACABCBACBACABCABCAACBACAACABCA"; verify_case(7, Arg1, validCodeHistory(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ThreeProgrammers ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
