
/**
 * You can modify this file.
 */

#include "matcher.h"
#include<stdio.h>

 /**
  * Your helper functions can go below this line
  */
//param: char *c the character for which we check is a dot
//return: 1 if it is a dot and 0 if it isn't
int hasDotOperator(char* c) {
    if (*c == '.') {
        return 1;
    }
    else {
        return 0;
    }
}
//param: char *c the character for which we chekc is a plus sign
//return: 1 if it is a plus sign and 0 if it isn't
int hasPlusOperator(char* c) {
    if (*c == '+') {
        return 1;
    }
    else {
        return 0;
    }
}
//param: char *c the character for which we check is a question mark
//return: 1 if it is a question mark and 0 if it isn't
int hasQuestionOperator(char* c) {
    if (*c == '?') {
        return 1;
    }
    else {
        return 0;
    }
}

//param: char *c the character for which we check is a slash
//return: 1 if it is a slash and 0 if not 
int hasSlashOperator(char* c) {
    if (*c == '\\') {
        return 1;
    }
    else {
        return 0;
    }
}


/**
 * Your helper functions can go above this line
 */


 /**
  * Returns true if partial_line matches pattern, starting from
  * the first char of partial_line.
  */
int matches_leading(char* partial_line, char* pattern) {
    // You can use this recommended helper function, or not.
     int tbr = 0;
    if (*pattern == '\0') {
        tbr =  1;
    }
   if(hasDotOperator(pattern)){
	   if(hasSlashOperator(pattern+1)){
		   if(hasDotOperator(pattern+2)|| hasSlashOperator(pattern +2)|| hasQuestionOperator(pattern+2) || hasPlusOperator(pattern+2)){
			   tbr = matches_leading(partial_line+1, pattern+2);
		   }
	   }
	   else{
		tbr = matches_leading(partial_line+1, pattern+1);
	   }
   } 
   else if(*partial_line == *pattern){
        if (hasDotOperator((pattern+1 )) && *(partial_line +1) != '\0' ) {
		
            tbr =  matches_leading(partial_line + 1, pattern + 1);
        }
	
	if(hasQuestionOperator(pattern+1)){
		if(*partial_line+1 == *pattern){
			tbr = matches_leading(partial_line +2, pattern+2);
		}
		else{
			tbr = matches_leading(partial_line +1, pattern+2);
		}
	}	
	else  if (hasPlusOperator((pattern +1))){
		int phold = 0;
		while(*pattern == *(partial_line +phold)){
			phold++;
		}
		tbr = matches_leading(partial_line +phold, pattern +2);
	}
	else if(hasSlashOperator(pattern+1)){
		if(hasDotOperator(pattern+2)|| hasSlashOperator(pattern+2) || hasQuestionOperator(pattern+2)|| hasPlusOperator(pattern+2)){
			tbr = matches_leading((partial_line+1),(pattern+2));
		}

	}
	else{
		tbr = matches_leading(partial_line +1, pattern +1);
		}
	
    }
   else if(*partial_line != *pattern){
	   if(hasQuestionOperator(pattern+1)){
		tbr = matches_leading(partial_line, pattern+2);
	   }

   }
    return tbr;
}

/**
 * Implementation of your matcher function, which
 * will be called by the main program.
 *
 * You may assume that both line and pattern point
 * to reasonably short, null-terminated strings.
 */
int rgrep_matches(char* line, char* pattern) {
    return matches_leading(line, pattern);
}
