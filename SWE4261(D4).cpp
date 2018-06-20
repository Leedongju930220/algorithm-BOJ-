#include<cstdio>
#include<string.h>
 
int main(){
    int testcase; 
    char num[1001];
    char input[1001];
    int word_lim = 0;
    int total_count = 0;
    int flag = 0;
    scanf("%d", &testcase);
 
    for (int i = 1; i <= testcase; i++){
        total_count = 0;
        scanf("%s %d", &num, &word_lim);
        int num_len = strlen(num);
 
        for (int j = 0; j < word_lim; j++){
             
 
            scanf("%s", &input);
            int word_len = strlen(input);
 
            if (num_len == word_len){
 
                for (int k = 0; k < word_len; k++){
                    char dia = 0;
                    if (input[k] >= 'a' && input[k] <= 'c') dia = '2';
                    else if (input[k] >= 'd' && input[k] <= 'f') dia = '3';
                    else if (input[k] >= 'g' && input[k] <= 'i') dia = '4';
                    else if (input[k] >= 'j' && input[k] <= 'l') dia = '5';
                    else if (input[k] >= 'm' && input[k] <= 'o') dia = '6';
                    else if (input[k] >= 'p' && input[k] <= 's') dia = '7';
                    else if (input[k] >= 't' && input[k] <= 'v') dia = '8';
                    else if (input[k] >= 'w' && input[k] <= 'z') dia = '9';
                     
                    if (dia != num[k]){
                        break;
                        flag = 0;
                    }
                    else flag = 1;
                }
            }
            if (flag == 1){
                total_count++;
                flag = 0;
            }
        }
        printf("#%d %d\n", i, total_count);
    }
 
 
    return 0;
}
