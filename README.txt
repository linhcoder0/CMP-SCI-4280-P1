Submission command

/accounts/classes/janikowc/submitProject/submit_cs4280s1_P1 SubmitFileOrDirectory

Requirement specifications

Implement a tokenizer/scanner for the provided lexical definitions, as a part of the front-end of the compiler project. The scanner will extract tokens from the input source and pass them along, one token at a time, upon request by the eventual parser.

The scanner should be embedded and thus it will return one token every time it is called. Since the parser is not available yet, we will use a tester testScanner() to test the produced tokens. You can have a container of tokens but you still must have the scanner() function to give one at a time.

The scanner could be implemented in multiple options

    Plain string reader, - read strings separated by spaces - easiest if assuming all tokens must be separated by WS  (-10 points). Relatively simple.
    Assisted by generative AI, yacc, or other tools. Different tokens dont have to be separated by WS. Relatively simple.
    Designed as DFSA, then mapped into a table, with a driver, following the discussion. Best option for most programming exercises, but more complex.

You must have the README.txt file with your submission (in the submission directory, spelled exactly as stated), starting with enumeration as shown below, and followed with any other needed comments

1. Which option you are using: 1 or 2 or 3.  For option 2, explain what and how you used it. For option 3, attach a picture Design (jpg,jpeg,pdf,png) file with your design and explain where in your code (source, line, etc) your table is.

2. Whether you process line numbers

3. Whether tokens must be separated by spaces ("x y" and "xy" are two different cases so space is required based on what token you want. "x=2" and "x = 2" are cases where space does not change the tokens, this is where there quostion is if spaces are requred)

Regardless of the option, remember that you must "own" the code, and anyone can be asked for a demonstration with explanations to get any credit.
If you receive an email before the submission deadline asking to demonstrate the submission, you must submit and visit me during office hours or at another agreed time, within 10 days, to demonstrate the project. A failure will result in a 0 score.

Getting the solution from other people is plagiarism.

Each token should have the group information (such as identifier or number), the instance (may not be needed for some tokens), and line number. 

Don't forget the EOFtk (end of file token) to be generated at the end of processing.

For testing purposes, the scanner will be tested using a testing driver implemented in the same scanner file or in a file with the basename "testScanner". You need to implement your own tester and include as a part of the project. This tester is a simple function:

    call the scanner, once for each single token, until it gets the EOFtk
    for each received token, display the token to the screen, one per line, including information (descriptive) on what token class, what token instance (if the token class includes more token instances) and what line (if processed).

Note that main() will process the arguments (as in P0, should be reused), then prepare anything as needed, then call testScanner() for testing. Main() would never call scanner() unless for some specific reason, it is testScanner() that will call scanner() to produce the outputs.

Here is a pseudocode for the tester

token=scanner(); // get first token after any necessary prep steps if any
while (true) {
  //print line number (if processing, space, descriptive token, space, token instance (string), \n
  if (token == EOFTk)
    break;
  token=scanner();
} 

Invocation

  P1 [file]

with exactly the same meaning, extension, and errors as P0. Wrong invocations will not be graded. 
Errors

Two possible kinds of errors should be thrown.

    Invocation errors - if the file cannot be opened
    Processing error - if a character is not in the alphabet or characters are in the alphabet but such a token does not exist

In both cases, your program should say "LEXICAL ERROR: " followed by a detailed message, and your program should exit.
Grading Rubric

10 points for architecture and coding style regardless of implementation method
5 points for stdin processing (or redirection) as in P0
5 points for handling errors 
5 points for reporting line numbers
10 points WS are not required to separate tokens when the tokens are different
65 points for properly recognizing/displaying tokens
+20 for option 3
Architecture

C or functional C++ must have (other languages appropriate differences)

    Implement the scanner in a separate file with basename "scanner", along with the tester
    scanner()
    testScanner()

    Keep the main() function, along with any helpers, in the file with the basename "main". Types including token type in token.h
    Use proper headers for your sources
    main never calls the scanner itself except for potential preparation