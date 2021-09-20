#include <stdlib.h>

/*Return true(non zero) if c is a whitspace character
('\t' or ' '). */
int space_char(char c)
{
  if( c == '\t' || c == ' ')
    {
      return true;
    }
  return false;

}

/*Return true (non-zero) if c is a non-whitspace
character (non tab or space).*/
int non_space_char(char c)
{
  if(  c == ' ' || c == '\t' )
    {
      return 0;
    }
  
  return 1;
}


/* Returns a pointer to the first character of the next 
   space-separated word in zero-terminated str.  Return a zero pointer if 
   str does not contain any words. */
char *word_start(char *str)
{
  if(count_words(str) > 0) 

}
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

/*
char *copy_str(char *inStr, short len);
{
 
}
*/


