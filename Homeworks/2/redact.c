/*
 * Redact.c
 *
 * Redacts words from a given text.
 *
 * Command Line Arguments:
 * Using -c when running this program will ignore capitalization when
 * 	redacting text.
 * Using -p when running this program will redact words that begin with
 * 	an uppercase letter.
 *
 *
 * @author Sarah Strickman sxs4599
 * 
 * Tthis lab made me want to kill myself. I actually want to crawl 
 * in a hole and die
 */ 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_INPUT 2048	// The maximum length of any input that the program takes

// int toStar(char * ch, int len) {
	// changes all of the characters in a string to the * character
	// return 0 if successful, 1 if not
	//
	// :param ch: a pointer to the first character that is being changed
	// :param len: the amount of characters that are being changed

// }


int redact(char text[], char words[]) {
	// Redacts specified words from a given text and replaces 
	// them with asterisks.
	//
	// :param text: the text that words are being redacted from
	// :param words: the words that are beinng redacted from the text

	bool isBeg = true;		// are you at the beginning of a word in text[]?
	int wordBeg = 0;		// used to mark where the beginning of a word is
	int tindex = 0;			// used to mark where in text[] you are
	int i = 0;				// marks what word n words[] you are looking at
	bool areSame = false;	// are the words being compared the same?

	// While the end of the text hasn't been reached, 
	// look for the word to redact 
	while (text[tindex] != '\0') {
		// if you read a space or if you are at the beginning of the text,
		// mark that you are at the beginning of a word
		if (tindex == 0) {
			isBeg = true;
		}
		else if (text[tindex - 1] == ' ') {
			isBeg = true;
		}
		else {
			isBeg = false;
		}

		// if the first character of the word matches in the strings,
		// check to see if the rest of the characters match
		if ((words[i] == text[tindex]) && (isBeg == true)) {
			wordBeg = tindex;
			areSame = true;
			while ((words[i] != '\0') && areSame) {
				if (text[tindex] == words[i]) {
					tindex++;
					i++;
				}
				else {
					areSame = false;
				}
			}
			i = 0;

			// If the two strings don't match, continue searching from 
			// where you left off
			if (!areSame && (text[tindex] != '\0')) {
				tindex = wordBeg + 1;
			}
			else if (!areSame && (text[tindex] == '\0')) {
				return 1;
			}
			else if (areSame && (((text[tindex] != ' ')) &&
					(text[tindex] != '\0'))) {
				areSame = false;
				tindex = wordBeg + 1;
			}

			//if they DO match, replace the segment of the string with stars
			else {
				while (wordBeg < tindex) {
					text[wordBeg] = '*';
					wordBeg++;
				}
				return 0;
			}
		}
		// if you haven't entered a special case, just keep going
		tindex++;			
	}
	return 1;
}

int redactParanoid(char text[], char words[]) {
	// Redacts specified words as well as words that 
	// begin with an uppercase letter from a given text 
	// and replaces them with asterisks.
	//
	// :param text: the text that words are being redacted from
	// :param words: the words that are being redacted from the text
    bool isBeg = true;          // are you at the beginning of a word in text[]?
    int wordBeg = 0;            // used to mark where the beginning of a word is
    int tindex = 0;             // used to mark where in text[] you are
    int i = 0;                  // marks what word n words[] you are looking at
    bool areSame = false;   	// are the words being compared the same?
	bool isUpper = false;		// does the word contain an uppercase letter?

    // While the end of the text hasn't been reached, 
    // look for the word to redact 
    while (text[tindex] != '\0') {
        // if you read a space or if you are at the beginning of the text,
        // mark that you are at the beginning of a word
        if (tindex == 0) {
           	isBeg = true;
        }
        else if (text[tindex - 1] == ' ') {
            isBeg = true;
			isUpper = false;
        }
        else {
           	isBeg = false;
        }

		if ((text[tindex] >= 'A') && (text[tindex] <= 'Z')) {
			isUpper = true;
		}

        // if the first character of the word matches in the strings,
		// or if there is a capital letter,
        // check to see if the rest of the characters match
        if ((isBeg && (words[i] == text[tindex])) || isUpper) {
           	wordBeg = tindex;
           	areSame = true;
            while ((words[i] != '\0') && (areSame)) {
                if ((text[tindex] == words[i]) || isUpper) {
                   	tindex++;
                	i++;
               	}
                else {
                	areSame = false;
            	}
            }
            i = 0;

            // If the two strings don't match, continue searching from 
            // where you left off
            if (!areSame && (text[tindex] != '\0')) {
            	tindex = wordBeg + 1;
            }
            else if (!areSame && (text[tindex] == '\0')) {
            	return 1;
            }
            else if (areSame && (((text[tindex] != ' ')) &&
                (text[tindex] != '\0'))) {
                areSame = false;
            	tindex = wordBeg + 1;
            }

            //if they DO match, replace the segment of the string with stars
            else {
                while (wordBeg < tindex) {
                    text[wordBeg] = '*';
                	wordBeg++;
            	}
    	    	return 0;
			}
        }
        // if you haven't entered a special case, just keep going
        tindex++;
    }
    return 1;
}



int redactCaseInsensitive(char text[], char words[]) {
	// Redacts specified words from a given text and replaces them
	// with asterisks, regardless of the casing of the words in the
	// text or the casing of the specified words.
	//
	// :param text: the text that words are being removed from
	// :param words: the words that are being redacted from the text
	bool isBeg = true; 			// are you at the beginning of a word in text[]?
    int wordBeg = 0;			// used to mark where the beginning of a word is
    int tindex = 0;				// used to mark where in text[] you are
    int i = 0;					// marks what word n words[] you are looking at
    bool areSame = false;  		// are the words being compared the same?
	bool isUpper = false;		// is the letter being read uppercase?
	bool isLower = false;		// is the letter being read lowercase?

    // While the end of the text hasn't been reached, 
    // look for the word to redact 
    while (text[tindex] != '\0') {

        // if you read a space or if you are at the beginning of the text,
        // mark that you are at the beginning of a word
        if (tindex == 0) {
        	isBeg = true;
        }
        else if (text[tindex - 1] == ' ') {
        	isBeg = true;
        }
        else {
	        isBeg = false;
        }
		
		// is the letter being read uppercase, lowercase, or neither?
		if ((text[tindex] >= 'A') && (text[tindex] <= 'Z')) {
			isUpper = true;
			isLower = false;
		}
		else if ((text[tindex] >= 'a') && (text[tindex] <= 'z')) {
			isLower = true;
			isUpper = false;
		}
		else {
			isUpper = false;
			isLower = false;
		}

        // if the first character of the word matches in the strings,
        // check to see if the rest of the characters match
		if (isBeg && ((words[i] == text[tindex]) || 
				(isUpper && (words[i] == (text[tindex] + 32))) ||
				(isLower && (words[i] == (text[tindex] - 32))))) {
			wordBeg = tindex;
			areSame = true;

			while ((words[i] != '\0') && areSame) {
				if ((text[tindex] == words[i]) ||
						(isUpper && (words[i] == (text[tindex] + 32))) ||
						(isLower && (words[i] == (text[tindex] - 32)))) {
                	tindex++;
                    i++;
                }
                else {
   			        areSame = false;
                }
			}
            i = 0;

			// If the two strings don't match, continue searching from 
            // where you left off
          	if (!areSame && (text[tindex] != '\0')) {
	            tindex = wordBeg + 1;
            }
            else if (!areSame && (text[tindex] == '\0')) {
    	        return 1;
            }
			else if (areSame && (((text[tindex] != ' ')) &&
					(text[tindex] != '\0'))) {
				areSame = false;
				tindex = wordBeg + 1;
			}

			//if they DO match, replace the segment of the string with stars
            else {
            	while (wordBeg < tindex) {
                	text[wordBeg] = '*';
                    wordBeg++;
                }
                return 0;
            }
		}
        // if you haven't entered a special case, just keep going
        tindex++;
	}
    return 1;
}


int main(int argc, char *argv[]) {
	/*
	 * does stuff i guess
	 *
	 * :param argc: the number of arguments passed into the program
	 * :param argv: the actual arguments
	 */

	bool isCaseInsensitive = false;	// is the program in -c mode?
	bool isParanoid = false;	// is the program in -p mode?
	bool isOpenQuote = false;
	
	char toRedact[argc + 1][MAX_INPUT + 1];	// array of words to redact
	
	int wc = 0;	// used to index toRedact 
	int rc = 0;	// used to index each word in toRedact

	int ac = 1;	// iterates through argv to process the arguments
	int cc = 0;	// used to index the characters of one argument
	
	// iterate though the arguments to process the list of things to be redacted.  
	while (ac < argc) {
		cc = 0;
		rc = 0;
		toRedact[wc + 1][0] = '\0';
		while ( (argv[ac][cc] != '\0') && (cc < MAX_INPUT) ) {
			if ((argv[ac][cc] == '-') && (cc == 0) && (strlen(argv[ac]) == 2)) {
				// will this argument alter the behavior of the program?
				// if so, don't process the '-' or the character after it
				if ( (argv[ac][cc + 1] == 'c') && (isCaseInsensitive == false)) {
					isCaseInsensitive = true;
					cc++;
					wc -= 1;
				}
				else if ( (argv[ac][cc + 1] == 'p') && (isParanoid == false)) {
					isParanoid = true;
					cc++;
					wc -= 1;
				}
				else {
					// if this is not changing the behavior of the program,
					// it will be redacted!
					toRedact[wc][rc] = argv[ac][cc];
					toRedact[wc][rc + 1] = '\0';
				}
			}
			else if ((argv[ac][cc] == 92) && (isOpenQuote == false)) { 
				// 92 is the '\' character.
				// concatenate the next word to the current one, with a
				// space in between! the program doesn't like me typing '\'
				toRedact[wc][rc] = ' ';
				toRedact[wc][rc + 1] = '\0';
				ac++;
			}
			
			else {
				// Put this character in toRedact
				toRedact[wc][rc] = argv[ac][cc];
				toRedact[wc][rc + 1] = '\0';
			}
			cc++;
			rc++;
		}
		wc++;
		ac++;
	}
	

	// Process the line of text that words will be redacted from
	char text[MAX_INPUT + 1];	// the array of text that will be redacted from
	int tindex = 0;	// used to index text[]

	char c; // used to index stdin
	c = getchar();
	while (c != EOF) {
		text[tindex] = c;
		text[tindex + 1] = '\0';
		tindex++;
		c = getchar();
	}

	
	////////////////////////////////
	// does the above code work? ///
	// Organized Print statements //
	////////////////////////////////
	int pronter = 0;
	int chonter = 0;
	
	while (toRedact[pronter][0] != '\0') {
		printf("Line %d: ", pronter + 1);
		chonter = 0;
		while (toRedact[pronter][chonter] != '\0') {
			printf("%c", toRedact[pronter][chonter]);
			chonter++;
		}
		pronter++;
		printf("\n");
	}
	printf("\n");
	/////////////////////////////////
	/////////////////////////////////

	
	
	////////////////////////////////
	///////// DO REDACTING /////////
	////////////////////////////////
	pronter = 0;
	if (isCaseInsensitive) {
			while (toRedact[pronter][0] != '\0') {
			redactCaseInsensitive(text, toRedact[pronter]);
			pronter++;
		}
	}

	pronter = 0;
	if (isParanoid) {
		while (toRedact[pronter][0] != '\0') {
			redactParanoid(text, toRedact[pronter]);
			pronter++;
		}
	}

	pronter = 0;
	while (toRedact[pronter][0] != '\0') {
		redact(text, toRedact[pronter]);
		pronter++;
	}
	///////////////////////////////
	///////////////////////////////


	
	//////////////////////////////////
	//// Print redacted statement ////
	//////////////////////////////////
	pronter = 0;
	while (text[pronter] != '\0') {
		printf("%c", text[pronter]);
		pronter++;
	}
	printf("\n\n");
	///////////////////////////////////
	///////////////////////////////////
}






























