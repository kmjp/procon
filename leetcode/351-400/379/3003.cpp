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

int L[20202];
int R[20202];
int RM[20202];

class Solution {
public:
    int maxPartitionsAfterOperations(string s, int k) {
		
		int N=s.size();
		int cur=0;
		int m=0;
		int i;
		FORR(c,s) c-='a';
		if(k==1) {
			int add=0;
			int p=0;
			FOR(i,N) {
				int a=0;
				if(i&&s[i]==s[i-1]) a++;
				if(i+1<N&&s[i]==s[i+1]) a++;
				add=max(add,a);
				if(i==0||s[i]!=s[i-1]) p++;
			}
			return p+add;
		}
		if(N==1||k==26) return 1;
		
		
		R[N]=RM[N]=0;
		for(i=N-1;i>=0;i--) {
			if(m==0) cur++;
			m|=1<<s[i];
			if(__builtin_popcount(m)>k) {
				m=1<<s[i];
				cur++;
			}
			R[i]=cur;
			RM[i]=m;
		}
		int ma=cur;
		cur=0,m=0;
		FOR(i,N) {
			int a=1<<s[i];
			
			if(i==0) {
				if(__builtin_popcount(RM[i+1])==k) ma=max(ma,R[i+1]+1);
			}
			else if(i==N-1) {
				if(__builtin_popcount(m)==k) ma=max(ma,cur+1);
			}
			else {
				int j;
				FOR(j,26) {
					int tar=m|RM[i+1]|(1<<j);
					if(__builtin_popcount(m)<=k&&__builtin_popcount(m|(1<<j))>k) {
						if(__builtin_popcount(RM[i+1]|(1<<j))>k) ma=max(ma,cur+R[i+1]+1);
					}
					else if(__builtin_popcount(tar)>k) ma=max(ma,cur+R[i+1]);
				}
			}
			m|=a;
			if(i==0||__builtin_popcount(m)>k) {
				m=a;
				cur++;
			}
			
		}
		return ma;
        
    }
};
