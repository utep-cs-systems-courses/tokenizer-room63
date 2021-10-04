#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"
#include <ctype.h>  // To use isdigit();
#include <string.h>

int main ()

{

  List *history = init_history();// initialize the linked list, allocating memory for it,
                                 //and creating the root node.

  char word[100];   //limit of word that user can input.


  do{

    printf ("Input a string to tokenize it or !<nums> for a special number, !h for full history, !q to quit:\n");


    // get user input

    fgets (word, 100, stdin);


    // !<nums> - special num

    if (word[0] == '!' && isdigit(word[1])){

      int val = atoi (word + 1);

      printf ("H[%d] %s\n", val,  get_history (history, val));

    }

    // !h show all history

    else if (strcmp (word, "!h\n") == 0){

      print_history(history);

    }

    // To quite the program using !q

    else if (strcmp (word, "!q\n") == 0){

      free_history(history); 

      goto done;

    }

    // Tokenize string

    else {

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

