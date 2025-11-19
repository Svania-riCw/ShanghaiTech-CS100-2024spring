#include<stdio.h>

long unsigned int shift(long unsigned int x , int n){
    return x<<n | x>>(32-n);
}

int can_change(int n1,int p[1000],int n){
    for(int i=0;i<n;++i){
        
        if(p[n1]==n1) return 0 ;
        else{
            p[n1] = p[p[n1]];
            }
    }
    return 1;
}


int main(void){
    int n=0,Q=0;
    long unsigned int  s[1000];
    int p[1000];
    scanf("%d%d",&n,&Q);
   
    for(int i=0;i<n;++i){
        scanf("%d",&s[i]);
    }
    
    for(int i=0;i<n;++i){
        p[i]=i;
    }

    for(int i=0;i<Q;++i){
        int n1=0,n2=0;
        scanf("%d%d",&n1,&n2);
    

        int change ;
        change = can_change(n1,p,n);
        if(change)  p[n1]=n2;     
        int turn = 0;
        int i = n1,j = n2;
        while(change){
            ++turn;
            if(p[i]==i) break;
            else{
                s[j] = s[j] ^ shift(s[i],turn);
                i = j;
                j = p[j];
            }
            
        } 
    }
    int min = 0;
    long unsigned int s_min =s[0];
    for(int i =1;i<n;++i){
        if(s[i]<s_min){
            s_min = s[i];
            min = i;
        }
    }
    printf("%d\n",min);
    printf("%lu\n",s_min);

}