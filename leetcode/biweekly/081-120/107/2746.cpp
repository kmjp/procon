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

int from[26][26];
int to[26][26];

class Solution {
public:
    int minimizeConcatenatedLength(vector<string>& words) {
		int x,y;
		FOR(x,26) FOR(y,26) from[x][y]=1<<30;
		from[words[0][0]-'a'][words[0].back()-'a']=words[0].size();
		
		int i;
		for(i=1;i<words.size();i++) {
			int a=words[i][0]-'a';
			int b=words[i].back()-'a';
			int l=words[i].size();
			FOR(x,26) FOR(y,26) to[x][y]=1<<30;
			FOR(x,26) FOR(y,26) {
				to[x][b]=min(to[x][b],from[x][y]+l-(y==a));
				to[a][y]=min(to[a][y],from[x][y]+l-(b==x));
			}
			
			swap(from,to);
		}
		int ret=1<<30;
		FOR(x,26) FOR(y,26) ret=min(ret,from[x][y]);
        return ret;
    }
};