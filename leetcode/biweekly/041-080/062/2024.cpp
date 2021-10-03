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
    int maxConsecutiveAnswers(string answerKey, int k) {
		int ma=0;
		int L,R;
		int N=answerKey.size();
		int ret=0;
		int cur=0;
		int i;
		FOR(i,2) {
			for(L=R=0;L<N;L++) {
				while(R<N&&(answerKey[R]=='F'||cur<k)) {
					if(answerKey[R]=='T') cur++;
					R++;
				}
				ma=max(ma,R-L);
				if(answerKey[L]=='T') cur--;
			}
			FORR(c,answerKey) c='T'+'F'-c;
		}
		return ma;
        
    }
};
