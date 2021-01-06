
#include <iostream>
#include "Rules.h"


int main()
{
    
    Rules obj;

    bool ID;
    
   for (int y = 0; y < 8; y++) 
    {
        for (int x = 0; x < 8; x++) {

            // if (obj.IsSquareInDanger(x, y)) {cout << "- "; }
            // else { cout << "+ "; }
            ID = obj.IsSquareInDanger(x, y);
        }
    } 

   cout << endl << endl;
   cout << obj.IdentifyTurn(4, 1) << endl;
   cout << obj.ScanGetValueGeneral(4, 1) << endl;
    return 0;
}
