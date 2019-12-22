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
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
		map<string,int> M;
		
		int i;
		int ma=0;
		FOR(i,s.size()-minSize+1) {
			string S=s.substr(i,minSize);
			int C[26]={};
			int num=0;
			FORR(c,S) {
				if(C[c-'a']++==0) num++;
			}
			if(num<=maxLetters) {
				M[S]++;
				ma=max(ma,M[S]);
			}
		}
        
        return ma;
    }
};

