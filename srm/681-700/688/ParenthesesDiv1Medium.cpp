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


class ParenthesesDiv1Medium {
	public:
	pair<int,int> dodo(string& S,int L,int R) {
		int H[2020]={};
		int i;
		string T;
		for(i=L;i<=R;i++) if(S[i]!='*') T+=S[i],S[i]='*';
		FOR(i,T.size()) H[i+1]=H[i]+((T[i]=='(')?1:-1);
		int up=0,down=0,cur=0;
		FOR(i,T.size()) {
			if(T[i]==')') {
				if(cur==0) up++,cur++;
				else cur--;
			}
			else {
				if(cur+1>T.size()-i-1) down++,cur--;
				else cur++;
			}
		}
		return {up,down};
	}
	
	int minSwaps(string s, vector <int> L, vector <int> R) {
		vector<int> RR[2020];
		vector<pair<int,int>> req;
		int I[2020] = {};
		int Q=L.size();
		int N=s.size();
		int i,j,x;
		
		FOR(i,N) RR[i].clear();
		FOR(i,Q) RR[L[i]].push_back(R[i]);
		FOR(i,N) if(RR[i].size()) {
			sort(RR[i].begin(),RR[i].end());
			RR[i].erase(unique(RR[i].begin(),RR[i].end()),RR[i].end());
			
			for(j=1;j<RR[i].size();j++) RR[RR[i][j-1]+1].push_back(RR[i][j]);
			RR[i].resize(1);
			x=RR[i][0];
			for(j=N-1;j>i;j--) if(RR[j].size() && RR[j].back()>=RR[i][0]) x=min(x,j-1);
			if(x<RR[i][0]) {
				RR[x+1].push_back(RR[i][0]);
				RR[i][0]=x;
			}
			req.push_back({RR[i][0]-i,i});
			for(j=i;j<=RR[i][0];j++) I[j]=1;
		}
		
		int fu=0,fd=0;
		FOR(i,N) if(I[i]==0) ((s[i]=='(')?fu:fd)+=1;
		
		int up=0,down=0;
		sort(req.begin(),req.end());
		FORR(e,req) {
			if((e.first % 2) == 0) return -1;
			x = e.second;
			auto ret=dodo(s,x,RR[x][0]);
			up+=ret.first;
			down+=ret.second;
		}
		
		if(up>=down) return (fu>=up-down) ? up : -1;
		else return (fd>=down-up) ? down : -1;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = ")("; int Arr1[] = {0,0,0,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,1,1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(0, Arg3, minSwaps(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "(())"; int Arr1[] = {0,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(1, Arg3, minSwaps(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "(((())"; int Arr1[] = {0,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(2, Arg3, minSwaps(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "((((((((("; int Arr1[] = {0,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(3, Arg3, minSwaps(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "()()()()"; int Arr1[] = {0,0,0,0,2,2,2,4,4,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,3,5,7,3,5,7,5,7,7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(4, Arg3, minSwaps(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arg0 = ")()(()()((())()()()()()()))(()())()()()("; int Arr1[] = {3,5,17,25,35}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {12,10,30,30,38}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(5, Arg3, minSwaps(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ParenthesesDiv1Medium ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
