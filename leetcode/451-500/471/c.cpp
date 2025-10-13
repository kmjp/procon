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

class Solution {
public:
    int longestBalanced(string s) {
		int ret=0;
		pair<int,int> cur={0,0};
		int i,j;
		map<pair<int,int>,int> M;
		M[cur]=0;
		//3•¶Žš
		FOR(i,s.size()) {
			if(s[i]=='a') {
				cur.first--;
				cur.second--;
			}
			else if(s[i]=='b') {
				cur.first++;
			}
			else if(s[i]=='c') {
				cur.second++;
			}
			if(M.count(cur)) {
				ret=max(ret,i+1-M[cur]);
			}
			else {
				M[cur]=i+1;
			}
		}
		
		//1•¶Žš
		FOR(j,3) {
			int pre=0;
			FOR(i,s.size()) {
				if(s[i]=='a'+j) ret=max(ret,i+1-pre);
				else pre=i+1;
			}
		}
		//2•¶Žš
		FOR(j,3) {
			int a='a'+j,b='a'+(j+1)%3,c='a'+(j+2)%3;
			int cur=0;
			map<int,int> M;
			M[0]=0;
			FOR(i,s.size()) {
				if(s[i]==c) {
					M.clear();
					cur=0;
					M[cur]=i+1;
				}
				else {
					if(s[i]==a) {
						cur++;
					}
					else {
						cur--;
					}
					if(M.count(cur)) {
						ret=max(ret,i+1-M[cur]);
					}
					else {
						M[cur]=i+1;
					}
				}
			}
		}
		
		
		
		
		
		return ret;
        
    }
};


