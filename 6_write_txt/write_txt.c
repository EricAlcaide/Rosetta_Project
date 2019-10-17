/*
 * Program written for ROSETTA_STONE
 * How to Execute:
 * You will need a compiler, best one is GCC
 * In your preferred CLI type gcc write_txt.c -o output
 * If you don't see any errors or warnings, your program compiled perfectly
 * Run your program by ./output
 * Any issues, reach me on Github @mayurdw
*/

// Include the required header files
#include <stdio.h>      // Required for input output operations
#include <string.h>    // Required for string comparisons 

//function declarations
int ReadFirstLine( void );
int ReadLastLine( void );
void WriteLine( char *pszLine );

// Preprocessor defines for ease in understanding
#define BUFFER_SIZE  1024
#define NEW_LINE       "\n"
#define DATA_FILE       "data.txt"
#define OUTPUT_FILE "write_c.txt"

void main()
{
   int iReturn = 0;
   int iReturn2 = 0;

   iReturn = ReadFirstLine();
   if ( iReturn != 0 )
   {
      //Reading & writing first line  successful
      iReturn2 = ReadLastLine();
   }

   if ( !iReturn || !iReturn2 )
   {
      printf( "Operation failed!!\nReturn values of first line and second line are %i %i", iReturn, iReturn2 );
   }

   return;
}

int ReadFirstLine()
{
   FILE *pDataFile = NULL;
   char szFirstLine[ BUFFER_SIZE + 1] = { 0, };
   char *pszFirstSentenceEnd = NULL;

   pDataFile = fopen( DATA_FILE, "r" );

   if ( pDataFile == NULL )
   {
      //error opening file, exit early
      return 0;
   }
   // file exists
   // fgets will stop reading as soon as it reaches a NEW_LINE char
   fgets( szFirstLine, BUFFER_SIZE, ( FILE *) pDataFile );

   pszFirstSentenceEnd = strstr( szFirstLine, NEW_LINE );

   if ( pszFirstSentenceEnd )
   {
      // we have the first line now write it to the output file
      WriteLine( szFirstLine );
   }

   fclose( pDataFile );
   return 1;
}

void WriteLine( char *pszLine )
{
   FILE *OutputFile = NULL;
   
   if ( pszLine == NULL )
   return;

   OutputFile = fopen( OUTPUT_FILE, "a");

   if ( OutputFile == NULL )
      return;
   
   fputs( pszLine, OutputFile );
   fputs( NEW_LINE, OutputFile );

   fclose( OutputFile );
   return;
}

int ReadLastLine()
{
   FILE *pDataFile = NULL;
   char szLastLine[BUFFER_SIZE + 1] = { 0, };
   char *pszSentenceEnd = NULL;

   pDataFile = fopen( DATA_FILE, "r" );

   if( pDataFile == NULL )
   {
      //Error opening file
      return 0;
   }

   //We have to keep reading till we reach End of file where there is no NEW_LINE character
   do 
   {
      fgets( szLastLine, BUFFER_SIZE, ( FILE * )pDataFile );
      pszSentenceEnd = strstr( szLastLine, NEW_LINE );
   } while( pszSentenceEnd != NULL );

   // we have reached the last line, make sure we have something
   if ( strlen( szLastLine ) > 0 )
   {
      WriteLine( szLastLine );
   }

   fclose( pDataFile );
   return 1;
}
