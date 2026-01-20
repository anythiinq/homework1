#include "DoomscrollerMap.h"
#include <cassert>
#include <iostream>

/*
note for next time: PRETTY MUCH DONE, BUT CHECK HOW THOROUGH THIS TEST CLASS IS WITH CHAT
 */

int main()
{
    DoomscrollerMap d1;
    
    d1.addDoomscroller("Mary");
    d1.addDoomscroller("Jacob");
    d1.addDoomscroller("Esther");
    d1.addDoomscroller("Mary"); // shouldn't add because it's a duplicate
    assert(d1.numDoomscrollers() == 3);
    
    d1.doomscroll("Mary", 2);
    d1.doomscroll("Jacob", -1); // shouldn't change hours because it's < 0
    assert(d1.hoursSpent("Mary") == 2 && d1.hoursSpent("Jacob") == 0);
    assert(d1.doomscroll("Betty", 0) == false); // shouldn't add because it's not part of the doomscroller map
}
