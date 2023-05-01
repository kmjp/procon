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
    string smallestBeautifulString(string s, int k) {
		int N=s.size();
		int i,j;
		for(i=N-1;i>=0;i--) {
			int a=s[i]-'a';
			for(j=a+1;j<k;j++) {
				if(i&&s[i-1]-'a'==j) continue;
				if(i>=2&&s[i-2]-'a'==j) continue;
				s[i]='a'+j;
				for(j=i+1;j<N;j++) {
					FOR(i,k) {
						if(j&&s[j-1]-'a'==i) continue;
						if(j>=2&&s[j-2]-'a'==i) continue;
						s[j]=i+'a';
						break;
					}
				}
				return s;
			}
		}
		return "";
        
    }
};
