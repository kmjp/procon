#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int resid[2][5000001];
int res[2][5000001];

class Sortish {
	public:
	int mat[20][20],E;
	int cid;
	int calcsort(vector <int>& seq,int shift) {
		int x,y,s=0;
		FOR(x,seq.size()) for(y=x+1;y<seq.size();y++) s+=seq[x]<seq[y];
		FOR(x,seq.size()) s+=mat[seq[x]][x+shift];
		return s;
	}
	
	vector<int> enumall(vector<int>& V,int shift,int id) {
		int ret=0,x;
		vector<int> r;
		do {
			x=calcsort(V,shift);
			if(resid[id&1][x]!=id) {
				resid[id&1][x]=id;
				res[id&1][x]=0;
				r.push_back(x);
			}
			res[id&1][x]++;
		} while(next_permutation(V.begin(),V.end()));
		return r;
	}
	
	long long ways(int sortedness, vector <int> seq) {
		int N=seq.size(),i,j,x,y;
		int vis[2001];
		vector<int> emp,V;
		
		E=0;
		emp.clear();
		V.clear();
		ZERO(vis);
		FOR(i,N) if(seq[i]==0) emp.push_back(i), E++;
		FOR(i,N) vis[seq[i]]++;
		FOR(i,N) if(vis[i+1]==0) V.push_back(i+1);
		FOR(i,N) for(j=i+1;j<N;j++) if(seq[i] && seq[j] && seq[i]<seq[j]) sortedness--;
		
		FOR(i,E) FOR(j,E) {
			mat[i][j]=0;
			FOR(x,N) if(seq[x]) mat[i][j]+=!((x<emp[j])^(seq[x]<V[i]));
		}
		FOR(i,E) V[i]=i;
		if(sortedness>N*N) return 0;
		
		MINUS(resid);
		if(E<=7) {
			enumall(V,0,0);
			return (resid[0][sortedness]==0)?res[0][sortedness]:0;
		}
		ll ret=0;
		for(int mask=0;mask<1<<E;mask++) if(__builtin_popcount(mask)==7) {
			vector<int> V[2];
			vector<int> M[2];
			FOR(i,E) V[(mask>>i)&1].push_back(i);
			
			M[1]=enumall(V[1],0,mask*2+1);
			M[0]=enumall(V[0],7,mask*2);
			int s=0;
			FOR(x,V[1].size()) FOR(y,V[0].size()) s+=(V[1][x]<V[0][y]);
			ITR(it,M[1]) {
				x=sortedness-s-*it;
				if(x>=0 && resid[0][x]==mask*2) ret+=1LL*res[1][*it]*res[0][x];
			}
		}
		
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arr1[] = {4, 0, 0, 2, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 2LL; verify_case(0, Arg2, ways(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; int Arr1[] = {0, 0, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 5LL; verify_case(1, Arg2, ways(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; int Arr1[] = {1, 3, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 1LL; verify_case(2, Arg2, ways(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 3; int Arr1[] = {0, 0, 2, 0, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 4LL; verify_case(3, Arg2, ways(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 87; int Arr1[] = {2,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 0LL; verify_case(4, Arg2, ways(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 30; int Arr1[] = {0, 6, 3, 0, 0, 2, 10, 0, 0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 34LL; verify_case(5, Arg2, ways(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 100; int Arr1[] = {0, 13, 0, 0, 12, 0, 0, 0, 2, 0, 0, 10, 5, 0, 0, 0, 0, 0, 0, 7, 15, 16, 20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 53447326LL; verify_case(6, Arg2, ways(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Sortish ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
