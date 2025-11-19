#include<stdio.h>

int add(unsigned int a, unsigned int b){
    a += b;
    return a;
}

int sub(unsigned int a, unsigned int b){
    a -= b;
    return a;
}

int mul(unsigned int a, unsigned int b){
    a *= b;
    return a;
}

int div(unsigned int a, unsigned int b){
    if(b!=0)a /= b;
    return a;
}



void print(int x,unsigned int a){
    switch (x){
        case 0:
            printf("x0 = %u\n",a);break;
        case 1:
            printf("x1 = %u\n",a);break;
        case 2:
            printf("x2 = %u\n",a);break;
        case 3:
            printf("x3 = %u\n",a);break;
        case 4:
            printf("x4 = %u\n",a);break;
        case 5:
            printf("x5 = %u\n",a);break;
    }
}

unsigned int id_instruction(int x){
    int num = 0;
    num = (x >> 13) & 0x7;
    return num;
}

unsigned int id_r1(int x){
    int num = 0;
    num = (x>>10) & 0x7;
    return num;
}
   
unsigned int id_r2(int x){
    int num = 0;
    num = (x>>7) & 0x7;
    return num;
}

unsigned int st_imm(int x){
    int num = 0;
    num = x & 0x7F ;
    return num;
}

int main(void){
    unsigned int n,x1=0,x2=0,x3=0,x4=0,x5=0,r2 = 0,imm = 0;
    const unsigned int x0 = 0;
    scanf("%u",&n);
    unsigned int m[1000];
    for(unsigned int i = 0;i<n;++i){
        scanf("%x",&m[i]);
        
        if(id_instruction(m[i]) == 0){
            if (id_r2(m[i]) == 0) r2 = x0;
            if (id_r2(m[i]) == 1) r2 = x1;
            if (id_r2(m[i]) == 2) r2 = x2;
            if (id_r2(m[i]) == 3) r2 = x3;
            if (id_r2(m[i]) == 4) r2 = x4;
            if (id_r2(m[i]) == 5) r2 = x5;


            
            if (id_r1(m[i]) == 1) x1 = add(x1,r2);
            if (id_r1(m[i]) == 2) x2 = add(x2,r2);
            if (id_r1(m[i]) == 3) x3 = add(x3,r2);
            if (id_r1(m[i]) == 4) x4 = add(x4,r2);
            if (id_r1(m[i]) == 5) x5 = add(x5,r2);
        }

        if(id_instruction(m[i])==1){
            if (id_r2(m[i]) == 0) r2 = x0;
            if (id_r2(m[i]) == 1) r2 = x1;
            if (id_r2(m[i]) == 2) r2 = x2;
            if (id_r2(m[i]) == 3) r2 = x3;
            if (id_r2(m[i]) == 4) r2 = x4;
            if (id_r2(m[i]) == 5) r2 = x5;


            
            if (id_r1(m[i]) == 1) x1 = sub(x1,r2);
            if (id_r1(m[i]) == 2) x2 = sub(x2,r2);
            if (id_r1(m[i]) == 3) x3 = sub(x3,r2);
            if (id_r1(m[i]) == 4) x4 = sub(x4,r2);
            if (id_r1(m[i]) == 5) x5 = sub(x5,r2);
        }

        if(id_instruction(m[i])==2){
            if (id_r2(m[i]) == 0) r2 = x0;
            if (id_r2(m[i]) == 1) r2 = x1;
            if (id_r2(m[i]) == 2) r2 = x2;
            if (id_r2(m[i]) == 3) r2 = x3;
            if (id_r2(m[i]) == 4) r2 = x4;
            if (id_r2(m[i]) == 5) r2 = x5;


            
            if (id_r1(m[i]) == 1) x1 = mul(x1,r2);
            if (id_r1(m[i]) == 2) x2 = mul(x2,r2);
            if (id_r1(m[i]) == 3) x3 = mul(x3,r2);
            if (id_r1(m[i]) == 4) x4 = mul(x4,r2);
            if (id_r1(m[i]) == 5) x5 = mul(x5,r2);
        }

        if(id_instruction(m[i])==3){
            if (id_r2(m[i]) == 0) r2 = x0;
            if (id_r2(m[i]) == 1) r2 = x1;
            if (id_r2(m[i]) == 2) r2 = x2;
            if (id_r2(m[i]) == 3) r2 = x3;
            if (id_r2(m[i]) == 4) r2 = x4;
            if (id_r2(m[i]) == 5) r2 = x5;


            
            if (id_r1(m[i]) == 1) x1 = div(x1,r2);
            if (id_r1(m[i]) == 2) x2 = div(x2,r2);
            if (id_r1(m[i]) == 3) x3 = div(x3,r2);
            if (id_r1(m[i]) == 4) x4 = div(x4,r2);
            if (id_r1(m[i]) == 5) x5 = div(x5,r2);
        }

        if(id_instruction(m[i]) == 4){
            imm = st_imm(m[i]);    

            if (id_r1(m[i]) == 1) x1 = imm;
            if (id_r1(m[i]) == 2) x2 = imm;
            if (id_r1(m[i]) == 3) x3 = imm;
            if (id_r1(m[i]) == 4) x4 = imm;
            if (id_r1(m[i]) == 5) x5 = imm;
           
        }

        if(id_instruction(m[i])==5){
            if(id_r1(m[i]) == 0) print(0,x0);
            if(id_r1(m[i]) == 1) print(1,x1);
            if(id_r1(m[i]) == 2) print(2,x2);
            if(id_r1(m[i]) == 3) print(3,x3);
            if(id_r1(m[i]) == 4) print(4,x4);
            if(id_r1(m[i]) == 5) print(5,x5);
        }

        
    }

}



