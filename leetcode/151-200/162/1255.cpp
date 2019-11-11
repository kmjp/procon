typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
		int C[26]={};
		FORR(c,letters) C[c-'a']++;
		int N=words.size();
		int mask;
		int ma=0,i;
		FOR(mask,1<<N) {
			int D[26];
			FOR(i,26) D[i]=C[i];
			int ng=0;
			int sc=0;
			FOR(i,N) if(mask&(1<<i)) {
				FORR(c,words[i]) {
					D[c-'a']--;
					if(D[c-'a']<0) sc=-1000000;
					else sc+=score[c-'a'];
				}
			}
			ma=max(ma,sc);
		}
		return ma;
        
    }
};

