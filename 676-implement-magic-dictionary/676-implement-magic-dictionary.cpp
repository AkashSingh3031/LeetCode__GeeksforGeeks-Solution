class MagicDictionary {
public:

    unordered_set<string> set;
	
    MagicDictionary(){
    }
    
    void buildDict(vector<string> dictionary){
        for(string str: dictionary)
            set.insert(str);
    }
    
    bool search(string searchWord){
        for(string s: set){
            if(s.size()==searchWord.size()){
                int cnt=0;
                for(int i=0;i<s.size();i++){
                    if(s[i]!=searchWord[i]) cnt++;
                }
                if(cnt==1) return true;
            }
        }
        return false;
    }
	
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */