struct node{
  
  node *next[26];
  int prefix_cnt,ending;
  
  node(){
    for(int i=0;i<26;i++)next[i]=NULL;
    prefix_cnt=ending=0;
  }
  
  bool containsKey(char ch){
    return next[ch-'a']!=NULL;
  }
  
  void put(char ch,node *curr){
    next[ch-'a']=curr;
  }
  
  node* get(char ch){
    return next[ch-'a'];
  }
  
  
};


struct trie{
  node *root;
  
  trie(){
    root=new node();
  }
  
  void insertString(string s){
    node *curr=root;
    for(auto it:s){
      
      if(!curr->containsKey(it)){
        curr->put(it,new node());
      }
      curr=curr->get(it);
      curr->prefix_cnt++;
    }
    curr->ending++;
  }
  
  bool searchString(string s){
    node *curr=root;
    for(auto it:s){
      if(!curr->containsKey(it))return false;
      curr=curr->get(it);
    }
    return curr->ending>0;
  }
  
  void deleteString(string s){
    if(!searchString(s))return;
    
    node *curr=root;
    for(auto it:s){
      curr=curr->get(it);
      curr->prefix_cnt--;
    }
    curr->ending--;
  }
  
  int countString(string s){
    node *curr=root;
    for(auto it:s){
      if(!curr->containsKey(it))return 0;
      curr=curr->get(it);
    }
    return curr->ending;
  }
  
  bool containsPrefix(string s){
    node *curr=root;
    for(auto it:s){
       if(!curr->containsKey(it))return false;
      curr=curr->get(it);
    }
    return curr->prefix_cnt>0;
  }
  
  int prefixCount(string s){
    node *curr=root;
    for(auto it:s){
      if(!curr->containsKey(it))return 0;
      curr=curr->get(it);
    }
    return curr->prefix_cnt;
  }
  
  bool containsAllPrefix(string s){
    // checks whether the current prefix of s exists as a separate string
    node *curr=root;
    for(auto it:s){
      if(!curr->containsKey(it))return false;
      curr=curr->get(it);
      if(!curr->ending)return false;
    }
    return true;
  }
};
