#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"


int main ()
{
  List *history = init_history();// initialize the linked list, allocating memory for it,
                                 // and creating the root node.

  char word[100];   // limit of word that user can input.


  do{

    printf ("Input a string to tokenize it or !<nums> for a special number, !h for full history, q to quit:\n");


    // get user input
    fgets (word, 100, stdin);


    // !<nums> - special num
    if (word[0] == 'q'){
      free_history(history);
      goto done;
    }
    
    if (word[0] == '!'){       
      int val = atoi (word + 1); //convert string argument to an integer
      if (val > 0 ){
      printf ("H[%d] %s\n", val,  get_history (history, val));
      }
      else
      {
      print_history(history);
    }
   }

    
    // Tokenize string

    else
      {

      char **tokens = tokenize (word);

      print_tokens(tokens);  // using function print_tokens.

      free_tokens(tokens); // using function free_tokens.


      // Add to history

      add_history (history, word);  // using function add_history.

    }

  }while (1);   //end of do while loop.

done:
  return 0;
}
