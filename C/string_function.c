#include<stdio.h>
#include <stddef.h> 

int hw3_islower(int ch){
    return (ch >= 'a' && ch<= 'z');

}

int hw3_isupper(int ch){
    return (ch >= 'A' && ch<= 'Z');
}

int hw3_isalpha(int ch){
    return (ch >= 'a' && ch<= 'z') || (ch >= 'A' && ch<= 'Z');
}

int hw3_isdigit(int ch){
    return (ch >= '0' && ch<= '9');
}

int hw3_tolower(int ch){
    return (hw3_islower(ch)? ch: ch + ('a'-'A'));
}

int hw3_toupper(int ch){
    return(hw3_isupper(ch)? ch : ch + ('A'-'a'));
}

size_t hw3_strlen(const char *str){
    int sum = 0;
    for(int i = 0; str[i]!= '\0' ; ++i){
        ++sum;
    }
    return sizeof(char)*sum;
}

char *hw3_strchr(const char *str, int ch){
    for(int i = 0 ; str[i] != '\0' ; ++i){
        if(str[i] == ch) return (char*)&str[i] ;
    }
    return NULL;
}

char *hw3_strcpy(char *dest, const char *src){
    int i = 0;
    while(1){
        if(src[i] == '\0'){
            dest[i] = '\0';
            return dest;
            break;
        }
        dest[i] = src[i];
        ++i;
    }
}

char *hw3_strcat(char *dest, const char *src){
    int i = 0;
    int len = hw3_strlen(dest);
    while(1){
        if(src[i] == '\0'){
            dest[len + i] = '\0';
            return dest;
            break;
        }
        dest[len+i] = src[i];
        ++i;
    }
}

int hw3_strcmp(const char *lhs, const char *rhs){
    int i = 0;
    while(1){
        if(lhs[i] < rhs[i]){
            return -1;
            break;
        }
        else if(lhs[i] > rhs[i]){
            return 1;
            break;
        }
        else {
            if(lhs[i] == '\0' || rhs[i]=='\0') {
                return 0;

                break;

            }
            else ++i;
        }
    }
}