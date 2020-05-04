#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define SIZE 5000
#define CODE 3
#define START 0
#define MIDDLE 1
#define END 2

//Function Prototypes

int amino(FILE *);
int base(FILE *);
void loopDecode(FILE *);
void decode(char *);
FILE * readFile(FILE *);

//Main Function (Start of Program)

int main(int argc, char * argv[]) {

    //Variables

   FILE * data;
   int baseNum;
   int aminoNum;
   char fileName[] = "data.txt";
   int status;

   //Input Data

   data = fopen(fileName, "w+");
   data = readFile(data);
   fclose(data);

   //Read Data

   data = fopen(fileName, "r");

   if (data == NULL) {

      printf("No Such File exists.\n");
      exit (1);

   }

   //Decode

   loopDecode(data);

   //Numbers

   baseNum = base(data);
   aminoNum = amino(data);

   //End

   printf("Total number of bases processed: %d\n", baseNum);
   printf("Total number of amino acids decoded: %d\n", aminoNum);
   fclose(data);

   status = remove(fileName);

   return 0;
}

//End Main

FILE * readFile(FILE * data) {

   if (feof(stdin)) {

      printf("stdin reach end of file.\n");
      exit (1);

   }

   void * content = malloc(sizeof(stdin));

   int read;

   while (read = fread(content, 1, sizeof(stdin), stdin)) {

      fwrite(content, 1, read, data);

   }

   if (ferror(stdin)) {

      printf("There was an error reading stdin.\n");
      exit (1);

   }

   free(content);

   return data;
}

void loopDecode(FILE * data) {

   //Variables

   char code[CODE];
   char ch;

   //Decode

   fseek(data, START, SEEK_SET);

   ch = fgetc(data);

   while(ch != EOF) {

      //Start

      if ((ch == 'A') || (ch == 'a') || (ch == 'C') || (ch == 'c') || (ch == 'G') || (ch == 'g') || (ch == 'T') || (ch == 't')) {

         code[START] = ch;

      }
      else {

         do {

            ch = fgetc(data);

            if (ch == EOF) {

               break;

            }

         } while ((ch != 'A') && (ch != 'a') && (ch != 'C') && (ch != 'c') && (ch != 'G') && (ch != 'g') && (ch != 'T') && (ch != 't'));

         if (ch == EOF) {

            break;

         }
         else {

            code[START] = ch;

         }
      }

      //Middle

      ch = fgetc(data);

      if (ch == EOF) {

         break;

      }
      else if ((ch == 'A') || (ch == 'a') || (ch == 'C') || (ch == 'c') || (ch == 'G') || (ch == 'g') || (ch == 'T') || (ch == 't')) {

         code[MIDDLE] = ch;

      }
      else {

         do {

            ch = fgetc(data);

            if (ch == EOF) {

               break;

            }

         } while ((ch != 'A') && (ch != 'a') && (ch != 'C') && (ch != 'c') && (ch != 'G') && (ch != 'g') && (ch != 'T') && (ch != 't'));

         if (ch == EOF) {

            break;

         }
         else {

            code[MIDDLE] = ch;

         }
      }

      //End

      ch = fgetc(data);

      if (ch == EOF) {

         break;

      }
      else if ((ch == 'A') || (ch == 'a') || (ch == 'C') || (ch == 'c') || (ch == 'G') || (ch == 'g') || (ch == 'T') || (ch == 't')) {

         code[END] = ch;

      }
      else {

         do {

            ch = fgetc(data);

            if (ch == EOF) {

               break;

            }

         } while ((ch != 'A') && (ch != 'a') && (ch != 'C') && (ch != 'c') && (ch != 'G') && (ch != 'g') && (ch != 'T') && (ch != 't'));

         if (ch == EOF) {

            break;

         }
         else {

            code[END] = ch;

         }
      }

      decode(code);

      ch = fgetc(data);

   }

   printf("\n");

   return;

}

//End loopDecode

int amino(FILE * data) {

   int aminoCount = 0;
   int triple = 0;
   char ch;

   fseek(data, START, SEEK_SET);

   while(ch = fgetc(data)) {

      if (ch == EOF) {

         break;

      }
      else if ((ch == 'A') || (ch == 'a') || (ch == 'C') || (ch == 'c') || (ch == 'G') || (ch == 'g') || (ch == 'T') || (ch == 't')) {

         triple++;

         if (triple == 3) {

            aminoCount++;
            triple = 0;

         }
      }
   }

   return aminoCount;

}

//End amino

int base(FILE * data) {

   int baseCount = 0;
   char ch;

   fseek(data, START, SEEK_SET);

   while(ch = fgetc(data)) {

      if (ch == EOF) {

         break;

      }

      else if ((ch == 'A') || (ch == 'a') || (ch == 'C') || (ch == 'c') || (ch == 'G') || (ch == 'g') || (ch == 'T') || (ch == 't')) {

         baseCount++;

      }
   }

   return baseCount;

}

//End base

void decode(char * code) {

   if ((code[START] == 'A') || (code[START] == 'a')) {

      if ((code[MIDDLE] == 'A') || (code[MIDDLE] == 'a')) {

         if ((code[END] == 'A') || (code[END] == 'a') || (code[END] == 'G') || (code[END] == 'g')) {

            printf("K");

         }

         else if ((code[END] == 'C') || (code[END] == 'c') || (code[END] == 'T') || (code[END] == 't')) {

            printf("N");

         }
      }
      else if ((code[MIDDLE] == 'C') || (code[MIDDLE] == 'c')) {

         printf("T");

      }
      else if ((code[MIDDLE] == 'G') || (code[MIDDLE] == 'g')) {

         if ((code[END] == 'A') || (code[END] == 'a') || (code[END] == 'G') || (code[END] == 'g')) {

            printf("R");

         }
         else if ((code[END] == 'C') || (code[END] == 'c') || (code[END] == 'T') || (code[END] == 't')) {

            printf("S");

         }
      }
      else if ((code[MIDDLE] == 'T') || (code[MIDDLE] == 't')) {

         if ((code[END] == 'A') || (code[END] == 'a') || (code[END] == 'C') || (code[END] == 'c') || (code[END] == 'T') || (code[END] == 't')) {

            printf("I");

         }
         else if ((code[END] == 'G') || (code[END] == 'g')) {

            printf("M");

         }
      }
   }
   else if ((code[START] == 'C') || (code[START] == 'c')) {

      if ((code[MIDDLE] == 'A') || (code[MIDDLE] == 'a')) {

         if ((code[END] == 'A') || (code[END] == 'a') || (code[END] == 'G') || (code[END] == 'g')) {

            printf("Q");

         }
         else if ((code[END] == 'C') || (code[END] == 'c') || (code[END] == 'T') || (code[END] == 't')) {

            printf("H");

         }
      }
      else if ((code[MIDDLE] == 'C') || (code[MIDDLE] == 'c')) {

         printf("P");

      }
      else if ((code[MIDDLE] == 'G') || (code[MIDDLE] == 'g')) {

         printf("R");

      }
      else if ((code[MIDDLE] == 'T') || (code[MIDDLE] == 't')) {

            printf("L");

      }
   }
   else if ((code[START] == 'G') || (code[START] == 'g')) {

      if ((code[MIDDLE] == 'A') || (code[MIDDLE] == 'a')) {

         if ((code[END] == 'A') || (code[END] == 'a') || (code[END] == 'G') || (code[END] == 'g')) {

            printf("E");

         }
         else if ((code[END] == 'C') || (code[END] == 'c') || (code[END] == 'T') || (code[END] == 't')) {

            printf("D");

         }
      }
      else if ((code[MIDDLE] == 'C') || (code[MIDDLE] == 'c')) {

         printf("A");

      }
      else if ((code[MIDDLE] == 'G') || (code[MIDDLE] == 'g')) {

         printf("G");

      }
      else if ((code[MIDDLE] == 'T') || (code[MIDDLE] == 't')) {

         printf("V");
      }
   }
   else if ((code[START] == 'T') || (code[START] == 't')) {

      if ((code[MIDDLE] == 'A') || (code[MIDDLE] == 'a')) {

         if ((code[END] == 'A') || (code[END] == 'a') || (code[END] == 'G') || (code[END] == 'g')) {

            printf("*");

         }
         else if ((code[END] == 'C') || (code[END] == 'c') || (code[END] == 'T') || (code[END] == 't')) {

            printf("Y");

         }
      }
      else if ((code[MIDDLE] == 'C') || (code[MIDDLE] == 'c')) {

         printf("S");

      }
      else if ((code[MIDDLE] == 'G') || (code[MIDDLE] == 'g')) {

         if ((code[END] == 'A') || (code[END] == 'a')) {

            printf("*");

         }
         else if ((code[END] == 'C') || (code[END] == 'c') || (code[END] == 'T') ||(code[END] == 't')) {

            printf("C");

         }
         else if ((code[END] == 'G') || (code[END] == 'g')) {

            printf("W");

         }
      }
      else if ((code[MIDDLE] == 'T') || (code[MIDDLE] == 't')) {

         if ((code[END] == 'A') || (code[END] == 'a') || (code[END] == 'G') || (code[END] == 'g')) {

            printf("L");

         }
         else if ((code[END] == 'C') || (code[END] == 'c') || (code[END] == 'T') || (code[END] == 't')) {

            printf("F");

         }
      }
   }

   return;

}

//End decode
