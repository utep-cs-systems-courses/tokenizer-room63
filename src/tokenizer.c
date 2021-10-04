#include <stdlib.h>
#include <stdio.h>

/*Return true(non zero) if c is a whitspace character
('\t' or ' '). */
int space_char(char c)
{
  if( c == '\t' || c == ' ')
    {
      return 1;
    }
  return 0;
  
}

/*Return true (non-zero) if c is a non-whitspace
character (non tab or space).*/
int non_space_char(char c)
{
  if(  c !=  ' ' && c != '\t' && c != '\0')
    {
      return 0;
    }
  
  return 1;
}


/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
int  count_words(char *str);
char *word_start(char *str)
{
  if (count_words(str) > 0) 

    {
int in_p = 0; // In charge of initialize pointer.
if(space_char(str[in_p]))
  str++;

while(space_char(str[in_p]))
  {
    in_p++;
  }
return (str++); //Return pointer to the first character of the next space-separeted word.
}

return str; //Return a zero pointer if str does not contain any words. 
}


/* Returns a pointer terminator char following *word */

char *word_terminator(char *word)
{
  
  while(non_space_char(*word) ) //Accesing the character.
    {
      word++;
    }
  return word;
}



/* Counts the number of words in the string argument. */

int count_words(char *str)
{
  int i = 0;
  int count = 0;

  while(str[i] != '\0')
    {
      if(non_space_char(str[i]) && space_char(str[i+1]))
	count++;
      i++;
      
}
  count += 1;

  if(space_char(str[i-2]))

    count--;

  return count;
}


/* Returns a fresly allocated new zero-terminated string 

   containing <len> chars from <inStr> */


char *copy_str(char *inStr, short len)
{
  char*  strCopy = NULL;
  char*  arrowP = inStr;

  
    
  strCopy= (char*) malloc ( (len+1)*sizeof(char)); 
    
    strCopy[len] = '\0';
    	

int i = 0;
 while( *arrowP != '\0'  )
   {
     strCopy[ i++] = *arrowP++;
   }
return  strCopy;
}

  
/* Returns a freshly allocated zero-terminated vector of freshly allocated 

   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:

     tokens[0] = "hello"

     tokens[1] = "world"

     tokens[2] = "string" 

     tokens[3] = 0

*/

char **tokenize(char* str)
{
  int sizeX = count_words( str );
    char **tokens = (char**) malloc((sizeX +1  ) * sizeof( char*));

  char* startS = str;
  char* endS = word_terminator(str);

  int i = 0;
  for(i = 0; i <sizeX; i++  )
    {
      if( i > 0){
	startS = word_start(endS);
	endS = word_terminator(startS);
	
      }

      int word_size = endS - startS;
      tokens[i] = malloc(word_size * sizeof(char));
      for(int j = 0; j< word_size; j++)
	{
	  tokens[i][j] = startS[j];
	  
	}
    }
  tokens[i] = 0;
  return tokens;
    
}


/* Prints all tokens. */

void print_tokens(char **tokens)
{
  int i;
  for(i = 0; tokens[i] != NULL; i++ )
    {
      printf ("Token number [%d]: %s\n", i, tokens[i] );
    }
  }


/* Frees all tokens and the vector containing themx. */

void free_tokens(char **tokens)
{
  int i;
  for( i = 0; tokens[i] != NULL; i++)
    {
      free(tokens[i]);
      
    }
  free(tokens);
}
