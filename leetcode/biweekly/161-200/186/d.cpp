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


int N1,N2,N3;
const ll mo=1000000007;

ll from[101][101];
ll to[101][101];


class Solution {
public:
    int interleaveCharacters(string word1, string word2, string target) {
		N1=word1.size();
		N2=word2.size();
		N3=target.size();
		
		int i,j,x,p1,p2;;
		ZERO(from);
		from[0][0]=1;
		
		FOR(x,N3) {
			ZERO(to);
			FOR(i,N1+1) {
				ll sum=0;
				FOR(j,N2) {
					(sum+=from[i][j])%=mo;
					if(target[x]==word2[j]) (to[i][j+1]+=sum)%=mo;
				}
			}
			FOR(i,N2+1) {
				ll sum=0;
				FOR(j,N1) {
					(sum+=from[j][i])%=mo;
					if(target[x]==word1[j]) (to[j+1][i]+=sum)%=mo;
				}
			}
			swap(from,to);
		}
		ll ret=0;
		FOR(i,N1+1) FOR(j,N2+1) if(i&&j) ret+=from[i][j];
		return ret%mo;
		
        
    }
};

