#include <stdio.h>

int main() {
   FILE *fp;
   char filename[100];
   char ch;

   printf("Enter the filename: ");
   scanf("%s", filename);

   fp = fopen(filename, "w");
   printf("Enter data to be written into the file: ");
   while ((ch = getchar()) != EOF) {
      putc(ch, fp);
   }
   fclose(fp);

   fp = fopen(filename, "r");
   printf("\nContents of the file: ");
   while ((ch = getc(fp)) != EOF) {
      printf("%c", ch);
   }
   fclose(fp);

   printf("\nDo you want to delete the file (y/n)? ");
   scanf("%s", &ch);
   if (ch == 'y' || ch == 'Y') {
      if (remove(filename) == 0) {
         printf("File deleted successfully.\n");
      } else {
         printf("Unable to delete the file.\n");
      }
   }

   return 0;
}
