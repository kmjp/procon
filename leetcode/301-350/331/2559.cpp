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

int S[101010];
class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
		int N=words.size();
		int i;
		FOR(i,N) {
			int x=0;
			if(words[i][0]=='a') x++;
			if(words[i][0]=='i') x++;
			if(words[i][0]=='u') x++;
			if(words[i][0]=='e') x++;
			if(words[i][0]=='o') x++;
			if(words[i].back()=='a') x++;
			if(words[i].back()=='i') x++;
			if(words[i].back()=='u') x++;
			if(words[i].back()=='e') x++;
			if(words[i].back()=='o') x++;
			S[i+1]=S[i]+(x==2);
		}
        vector<int> R;
        FORR(q,queries) {
			R.push_back(S[q[1]+1]-S[q[0]]);
		}
		return R;
        
    }
};
