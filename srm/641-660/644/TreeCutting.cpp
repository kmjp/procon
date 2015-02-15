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

int mat[51][51];

class TreeCutting {
	public:
	int N;
	vector<int> P,num;
	bool ok(ll mask,int st) {
		int no=0;
		int i,j,t=0,nv=__builtin_popcountll(mask);
		int V[51],nev=0;
		
		FOR(i,N) if(mask&(1LL<<i)) {
			V[nev++]=i;
			if(num[i]>=0) t+=num[i], no++;
		}
		if(t!=nv) return false;
		if(no==1) return true;
		
		for(i=st;i<N-1;i++) {
			if((mask&(1LL<<(i+1)))==0) continue;
			if((mask&(1LL<<P[i]))==0) continue;
			
			ll mask2=0,mask3=0,n2=0,n2o=0,n3=0,n3o=0;
			FOR(j,nev) {
				if(mat[V[j]][i+1]<mat[V[j]][P[i]]) {
					mask2 |= 1LL<<V[j], n2++;
					if(num[V[j]]>=0) n2o++, n2-=num[V[j]];
				}
				else {
					mask3 |= 1LL<<V[j], n3++;
					if(num[V[j]]>=0) n3o++, n3-=num[V[j]];
				}
			}
			if(n2o<1 || n3o<1 || n2!=0 || n3!=0) continue;
			return ok(mask3,i+1) && ok(mask2,i+1);
		}
		return false;
	}
	
	string can(vector <int> par, vector <int> num) {
		int i,t=0,x,y;
		P=par;
		this->num=num;
		//FOR(i,65) M[i].clear();
		N=par.size()+1;
		
		FOR(x,N) FOR(y,N) mat[x][y]=1000;
		FOR(i,N-1) mat[par[i]][i+1]=mat[i+1][par[i]]=1;
		FOR(x,N) mat[x][x]=0;
		FOR(i,N) FOR(x,N) FOR(y,N) mat[x][y]=min(mat[x][y],mat[x][i]+mat[i][y]);
		
		if(ok((1LL<<N)-1,0)) return "POSSIBLE";
		return "IMPOSSIBLE";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,1,2,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,-1,-1,4,-1,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "POSSIBLE"; verify_case(0, Arg2, can(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0,1,2,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,-1,-1,3,-1,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "IMPOSSIBLE"; verify_case(1, Arg2, can(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0,1,2,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,-1,-1,3,-1,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "IMPOSSIBLE"; verify_case(2, Arg2, can(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0,1,2,2,1,5,2,6,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1,2,-1,1,3,-1,1,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "POSSIBLE"; verify_case(3, Arg2, can(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {0,1,2,2,1,5,2,6,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1,2,-1,1,-1,3,1,1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "IMPOSSIBLE"; verify_case(4, Arg2, can(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {0,0,0,0,1,1,2,3,3,3,4,4,4,5,9,9,14,14,14,16,20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,3,-1,-1,-1,-1,-1,1,1,-1,-1,-1,3,1,-1,1,8,-1,-1,4,-1,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "POSSIBLE"; verify_case(5, Arg2, can(Arg0, Arg1)); }
	void test_case_6() { int Arr0[] = {0,0,0,0,1,1,2,3,3,3,4,4,4,5,9,9,14,14,14,16,20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,2,-1,-1,-1,-1,-1,1,1,-1,-1,-1,3,1,-1,1,9,-1,-1,4,-1,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "IMPOSSIBLE"; verify_case(6, Arg2, can(Arg0, Arg1)); }
//	void test_case_7() { int Arr0[] = {0,0,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1,5,-1,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "POSSIBLE"; verify_case(7, Arg2, can(Arg0, Arg1)); }
	void test_case_7() { int Arr0[] = {0, 1, 0, 3, 1, 0, 1, 1, 1, 9, 9, 11, 11, 1, 7, 1, 16, 2, 3, 6, 11, 6, 10, 13, 9, 24, 20, 26, 14, 8, 15, 3, 2, 1, 34, 35, 11, 5, 22, 26, 16, 32, 22, 30, 13, 0, 34, 43, 14}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1, -1, -1, -1, 1, -1, 1, 1, 1, -1, -1, 2, 1, -1, 5, 1, 2, -1, 1, 1, 2, -1, 1, 1, 1, 3, 1, -1, 2, 1, 1, 1, -1, 1, 1, 1, 1, 1, -1, 1, 1, 1, 3, 1, 1, 2, 1, 1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "IMPOSSIBLE"; verify_case(7, Arg2, can(Arg0, Arg1)); }
// END CUT HERE

};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TreeCutting ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
