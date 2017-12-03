#include "Testbed.h"
#include <iostream>


int
main()
{
   std::cout << "=========================================================================" << std::endl;
   int reps = 1;
   while (reps > 0)
   {
      if (!RunTests()) {
         cout << "====== ERROR ======" << endl;
         break;
      }
      reps--;
   }

   return 0;
}
