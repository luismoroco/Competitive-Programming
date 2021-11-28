#include <bits/stdc++.h>
using namespace std;

// https://www.beecrowd.com.br/judge/en/problems/view/1642

int main(int argc, char const *argv[])
{
    while(true){
        int keys;
        scanf("%d", &keys);
        getchar();
        if(keys != 0){
            char text[1000010];
            if(fgets(text, 1000010, stdin) != NULL){
                int text_size = strlen(text);
                int bigger_substring_size = 0;
                int substring_counter[128];
                int curr_start = 0, curr_end = keys-1;
                int keys_used = 0, counter_aux = 0;

                for (int i = 0; i < 128; ++i)
                    substring_counter[i] = 0;

                for (int i = 0; i < keys; ++i){
                    if(substring_counter[text[i]] == 0){
                        keys_used++;
                    }
                    substring_counter[text[i]]++;
                }

                while(curr_end < text_size-2){
                    while(keys_used <= keys && (curr_end < text_size-2))
                    {
                        curr_end++;
                        if(substring_counter[text[curr_end]] == 0){
                            keys_used++;
                        }
                        substring_counter[text[curr_end]]++;
                    }
                    if(keys_used > keys){
                        curr_start++;
                    }
                    if((curr_end - curr_start + 1) > bigger_substring_size){
                        bigger_substring_size = curr_end - curr_start + 1;
                    }
                    if(substring_counter[text[curr_start-1]] > 0){
                        substring_counter[text[curr_start-1]]--;
                        counter_aux = substring_counter[text[curr_start-1]];
                        if(counter_aux == 0){
                            keys_used--;
                        }
                    }
                }
                printf("%d\n", bigger_substring_size);
            }
        }
        else{
            break;
        }
    }
    return 0;
}
