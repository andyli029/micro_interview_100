
#include <iostream>
#include <cstring>

char * string_levorotation( char * const string, int pos, int length )
{
   int start = 0;
   int end = start + pos - 1;
   char ch;

   if( 1 == length || 0 == pos )
   {
      return string;
   }

   // reverse substring from 0 to pos-1
   while( start < end )
   {
      ch = string[start];
      string[start] = string[end];
      string[end] = ch;
      start ++;
      end --;
   }

   // reverse substring from pos to the last
   start = pos;
   end = length - 1;
   while( start < end )
   {
      ch = string[start];
      string[start] = string[end];
      string[end] = ch;
      start ++;
      end --;
   }

   // reverse the whole string
   start = 0;
   end = length - 1;
   while( start < end )
   {
      ch = string[start];
      string[start] = string[end];
      string[end] = ch;
      start ++;
      end --;
   }
   return string;
}

int main( int argc, char ** argv )
{
   char string[] = "abcdef";
   char * pResult = string_levorotation( string, 2, strlen(string) );
   std::cout << pResult << std::endl;
   return 0;
}

