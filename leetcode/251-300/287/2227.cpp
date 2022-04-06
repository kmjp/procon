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



string to[256];
map<string,int> M;
vector<vector<int>> D;

class Encrypter {
public:
	
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        int i;
        
        M.clear();
        FOR(i,keys.size()) {
			to[keys[i]]=values[i];
			M[values[i]] |= 1<<(keys[i]-'a');
		}
        
        D.clear();
        FORR(d,dictionary) {
			vector<int> A;
			FORR(c,d) A.push_back(1<<(c-'a'));
			D.push_back(A);
		}
        
    }
    
    string encrypt(string word1) {
        string S;
        FORR(c,word1) S+=to[c];
        return S;
    }
    
    int decrypt(string word2) {
        vector<int> V;
        int i;
        for(i=0;i<word2.size();i+=2) {
			int m=M[word2.substr(i,2)];
			V.push_back(m);
		}
		int ret=0;
		FORR(w,D) if(V.size()==w.size()) {
			FOR(i,V.size()) if((V[i]&w[i])==0) break;
			if(i==V.size()) ret++;
		}
		return ret;
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */
 