struct node{
  
  node *next[2];
  
  node(){
    next[0]=next[1]=NULL;
  }
  
  bool containsKey(int bit){
    return next[bit]!=NULL;
  }
  
  node* get(int bit){
    return next[bit];
  }
  
  void put(int bit,node *curr){
    next[bit]=curr;
  }
  
};

struct trie{
  
  node *root;
  
  trie(){
    root=new node();
  }
  
  void insertNumber(int n){
    node *curr=root;
    for(int i=31;i>=0;i--){
      int b=(n>>i)&1;
      if(!curr->containsKey(b)){
        curr->put(b,new node());
      }
      curr=curr->get(b);
    }
  }
  
   int find_max_xor(int x){
      int mx=0;
      node *curr=root;
      for(int i=31;i>=0;i--){
          int b=((x>>i)&1);
          if(curr->containsKey(1-b)){
              mx+=(1<<i);
              curr=curr->get(1-b);
          }
          else
             curr=curr->get(b);
      }
            return mx;
   }
  
};
