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
    long long countVowels(string word) {
		ll ret=0;
		int y;
		ll N=word.size();
		FOR(y,N) {
			if(word[y]!='a'&&word[y]!='i'&&word[y]!='u'&&word[y]!='e'&&word[y]!='o') continue;
			ret+=1LL*(y+1)*(N-y);
		}
        return ret;
    }
};
