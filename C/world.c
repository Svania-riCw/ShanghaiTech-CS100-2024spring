#include<stdio.h>
unsigned int shift(unsigned int x , int n){
    return x<<n | x>>(32-n);
}



int main(void){
    int n=0,Q=0;
    unsigned int  s[1000];
    int p[1000];
    scanf("%d%d",&n,&Q);
   
    for(int i=0;i<n;++i){
        scanf("%u",&s[i]);
        p[i]=i;
    }
    
    

    for(int i=0;i<Q;++i){
        int n1=0,n2=0;
        scanf("%d%d",&n1,&n2);
        n1 = n1-1;
        n2 = n2-1;

        p[n1]=n2; 
        

            
        int turn = 0;
        int j = n2;
        
        while(1){
            ++turn;
            if(j==n1) break;
            
            else{
                s[j] = s[j] ^ shift(s[n1],turn);
                
                j = p[j];
                
            }
            if(p[j]==j)break;
            
        } 
    }
    int min = 0;
    unsigned int s_min =s[0];
    for(int i =1;i<n;++i){
        
        if(s[i]<s_min){
            
            s_min = s[i];
            min = i;
        }
    }
    printf("%d\n",min+1);
    printf("%u\n",s_min);

}




