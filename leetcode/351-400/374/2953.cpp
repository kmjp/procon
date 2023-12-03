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


int S[27][101010];

class Solution {
public:
    int countCompleteSubstrings(string word, int k) {
		int N=word.size();
		int i,j,x;
		FOR(i,N) {
			FOR(j,27) S[j][i+1]=S[j][i];
			S[word[i]-'a'][i+1]++;
			if(i&&abs(word[i]-word[i-1])>2) S[26][i+1]++;
		}
		
		int ret=0;
		FOR(i,N) {
			for(j=1;j<=26;j++) {
				if(i+j*k>N) break;
				if(S[26][i+j*k]-S[26][i+1]) continue;
				FOR(x,26) {
					if(S[x][i+j*k]-S[x][i]!=0&&S[x][i+j*k]-S[x][i]!=k) break;
				}
				if(x==26) ret++;
			}
		}
		return ret;
        
    }
};
