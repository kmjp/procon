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

vector<int> S[2][26];
int mask[1<<25];
int rev[51];
int NB;

class ColorfulParentheses {
	public:
	int N;
	ll B;
	vector<int> C;
	
	void dfs(int cur,int cnt,int id,ll open,ll close) {
		if(cur==N) {
			S[id][cnt].push_back(open&((1<<NB)-1));
		}
		else {
			if(id==0) {
				int c=rev[C[cur]];
				if(!(close & (1LL<<c))) dfs(cur+1,cnt+1,id,open|(1<<c),close);
				if(!(open & (1LL<<c)) && cnt) dfs(cur+1,cnt-1,id,open,close|(1<<c));
			}
			else {
				int c=rev[C[2*N-1-cur]];
				if(!(open & (1LL<<c))) dfs(cur+1,cnt+1,id,open,close|(1<<c));
				if(!(close & (1LL<<c)) && cnt) dfs(cur+1,cnt-1,id,open|(1<<c),close);
			}
			
		}
	}
	
	long long count(vector <int> C) {
		int i,j;
		int cnt[2][52]={};
		
		this->C=C;
		N=C.size()/2;
		FOR(i,26) S[0][i].clear(), S[1][i].clear();
		
		FOR(i,N) cnt[0][C[i]]++, cnt[1][C[i+N]]++;
		
		B=0;
		NB=0;
		FOR(i,51) if(cnt[0][i] && cnt[1][i]) rev[i]=NB, NB++;
		int x=0,y=0;
		FOR(i,51) if(cnt[0][i] && cnt[1][i]==0) rev[i]=NB+x, x++;
		FOR(i,51) if(cnt[0][i]==0 && cnt[1][i]) rev[i]=NB+y, y++;
		
		B |= 1LL<<i, 
		dfs(0,0,0,0,0);
		dfs(0,0,1,0,0);
		
		ll ret=0;
		FOR(i,26) {
			FORR(r,S[0][i]) mask[r]++;
			FORR(r,S[1][i]) ret+=mask[r];
			FORR(r,S[0][i]) mask[r]--;
		}
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,0,1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 3LL; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { int Arr0[] = {0,1,2,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 5LL; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { int Arr0[] = {0,1,0,1,0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { int Arr0[] = {0,1,2,3,4,5,6,7,8,9,10,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { int Arr0[] = {0,1,3,3,4,5,6,7,1,9,10,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 7LL; verify_case(4, Arg1, count(Arg0)); }
	void test_case_5() { int Arr0[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 477638700LL; verify_case(5, Arg1, count(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ColorfulParentheses ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

