const int N=1e6;
vector<bool>primee(N+1,1);
void sieve(){
	primee[0]=primee[1]=0;
	for(int i=2;i*i<=N;i++){
		if(!primee[i])continue;
		for(int j=i*i;j<=N;j+=i){
			primee[j]=0;
		}
	}
}

bool check_prime(int n){
	
	for(int i=2;i*i<=n;i++){
		if(n%i==0)return 0;
	}

	return n>1;
}