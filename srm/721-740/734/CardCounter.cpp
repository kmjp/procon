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


double memo1[22][2][1<<16];
vector<double> memo2[22][2][1<<16];


class CardCounter {
	public:
	int deal;
	vector<int> D;
	vector<double> get_dealer(int sum,int ace,int mask) {
		vector<double> R(22,0);
		if(sum>21) {
			R[0]=1;
		}
		else if(sum+10*ace>=17 && sum+10*ace<=21) {
			R[sum+10*ace]=1;
		}
		else if(sum>=17 && sum<=21) {
			R[sum]=1;
		}
		else {
			if(memo2[sum][ace][mask].size()) return memo2[sum][ace][mask];
			int num=__builtin_popcount(mask);
			int i,j;
			FOR(i,D.size()) if(mask&(1<<i)) {
				auto R2=get_dealer(sum+D[i],ace|(D[i]==1),mask^(1<<i));
				FOR(j,22) R[j]+=R2[j]*1.0/num;
			}
			memo2[sum][ace][mask] = R;
		}
		int i;
		return R;
	}
	
	double hoge(int sum,int ace,int mask) {
		double end=0;
		if(sum>21) return 0;
		if(memo1[sum][ace][mask]<0) {
			vector<double> op=get_dealer(deal,deal==1,mask);
			int cur=sum;
			if(ace&&sum+10<=21) cur+=10;
			int i;
			FOR(i,cur) end+=op[i];
			
			double take=0;
			FOR(i,D.size()) if(mask&(1<<i)) take += hoge(sum+D[i],ace | (D[i]==1),mask^(1<<i));
			memo1[sum][ace][mask] = max(end,take/__builtin_popcount(mask));
		}

		return memo1[sum][ace][mask];
		
		
	}
	
	double winningChance(vector <int> deck, int dealer, vector <int> player) {
		deal = dealer;
		D.clear();
		int i,j,k;
		FOR(i,deck.size()) while(deck[i]--) D.push_back(i+1);
		
		FOR(i,22) FOR(j,2) FOR(k,1<<16) memo1[i][j][k]=-1,memo2[i][j][k].clear();
		
		return hoge(player[0]+player[1],(player[0]==1)|(player[1]==1),(1<<D.size())-1);
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,0,0,0,0,0,0,4,0,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; int Arr2[] = {9,9}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 0.5; verify_case(0, Arg3, winningChance(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0,0,0,0,0,0,0,4,0,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arr2[] = {5,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 0.2857142857142857; verify_case(1, Arg3, winningChance(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0,0,0,4,0,0,0,0,0,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arr2[] = {10,7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 0.5; verify_case(2, Arg3, winningChance(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {0,0,2,2,2,2,2,2,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arr2[] = {10,10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 0.7348901098901098; verify_case(3, Arg3, winningChance(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {0,0,0,0,0,0,0,4,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; int Arr2[] = {10,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); double Arg3 = 1.0; verify_case(4, Arg3, winningChance(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  CardCounter ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

