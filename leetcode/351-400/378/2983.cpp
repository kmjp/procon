#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int same[50505];
int dpA[26][50505];
int dpB[26][50505];

int N;
string A;
string B;
class Solution {
public:
	bool hoge(int a,int b,int c,int d) {
		int i;
		FOR(i,26) if(dpA[i][N]!=dpB[i][N]) return 0;
		cout<<a<<b<<c<<d<<endl;
		if(b<=c||d<=a) {
			//Œð‚í‚ç‚È‚¢
			if(a>c) {
				swap(a,c);
				swap(b,d);
			}
			if(same[a]!=a) return 0;
			if(same[c]-same[b]!=c-b) return 0;
			if(same[N]-same[d]!=N-d) return 0;
			FOR(i,26) if(dpA[i][b]-dpA[i][a]!=dpB[i][b]-dpB[i][a]) return 0;
			FOR(i,26) if(dpA[i][d]-dpA[i][c]!=dpB[i][d]-dpB[i][c]) return 0;
		}
		else {
			if(a<=c&&b>=d || c<=a&&d>=b) {
				a=min(a,c);
				b=max(b,d);
				if(same[a]!=a) return 0;
				if(same[N]-same[b]!=N-b) return 0;
				FOR(i,26) if(dpA[i][b]-dpA[i][a]!=dpB[i][b]-dpB[i][a]) return 0;
			}
			else if(a<c) {
				assert(b<d);
				if(same[a]!=a) return 0;
				if(same[N]-same[d]!=N-d) return 0;
				FOR(i,26) if(dpA[i][b]-dpA[i][a]<dpB[i][c]-dpB[i][a]) return 0;
				FOR(i,26) if(dpB[i][d]-dpB[i][c]<dpA[i][d]-dpA[i][b]) return 0;
			}
			else {
				assert(d<b);
				if(same[c]!=c) return 0;
				if(same[N]-same[b]!=N-b) return 0;
				FOR(i,26) if(dpA[i][a]-dpA[i][c]>dpB[i][d]-dpB[i][c]) return 0;
				FOR(i,26) if(dpB[i][d]-dpB[i][b]>dpA[i][d]-dpA[i][a]) return 0;
			}
				
			
		}
		return 1;
		
		
	}
    vector<bool> canMakePalindromeQueries(string s, vector<vector<int>>& queries) {
        reverse(ALL(B));
        
		N=s.size()/2;
		A=s.substr(0,N);
		B=s.substr(N);
		reverse(ALL(B));
		cout<<A<<" "<<B<<endl;
        int i,j;
        FOR(i,N) {
			same[i+1]=same[i]+(A[i]==B[i]);
			FOR(j,26) {
				dpA[j][i+1]=dpA[j][i]+(A[i]==('a'+j));
				dpB[j][i+1]=dpB[j][i]+(B[i]==('a'+j));
			}
		}
		vector<bool> ret;
		FORR(q,queries) {
			ret.push_back(hoge(q[0],q[1]+1,2*N-1-q[3],2*N-q[2]));
		}
		return ret;
        
    }
};


