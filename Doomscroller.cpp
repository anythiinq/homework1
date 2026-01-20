#include "DoomscrollerMap.h"
#include "Map.h"

#include <string>
#include <iostream>

DoomscrollerMap::DoomscrollerMap()
: doomscrollers()
{
}

// If a person with the specified name is not currently in the map,
// and there is room in the map, add an entry for that person
// recording that they have spent 0 hours doomscrolling, and return
// true.  Otherwise, make no change to the map and return false.
bool DoomscrollerMap::addDoomscroller(std::string name)
{
    if (doomscrollers.contains(name))
        return false;
    
    doomscrollers.insert(name, 0);
    return true;
}

// If a person with the specified name is in the map, return how
// many hours they have spent doomscrolling; otherwise, return -1.
double DoomscrollerMap::hoursSpent(std::string name) const
{
    double hoursSpent;
    if (doomscrollers.get(name, hoursSpent))
        return hoursSpent;
    
    return -1;
}

// If no person with the specified name is in the map or if hours
// is negative, make no change to the map and return false.
// Otherwise, increase by the hours parameter the number of hours
// the indicated person has spent doomscrolling and return true.
bool DoomscrollerMap::doomscroll(std::string name, double hours)
{
    if (!(doomscrollers.contains(name)) || hours < 0)
        return false;
    
    double newHours = hoursSpent(name) + hours;
    doomscrollers.update(name, newHours);
    
    return true;
}

// Return the number of people in the DoomscrollerMap.
int DoomscrollerMap::numDoomscrollers() const
{
    return doomscrollers.size();
}

// Write to cout one line for every person in the map.  Each line
// consists of the person's name, followed by one space, followed by
// the number of hours that person has spent doomscrolling.  Write
// no other text.  The lines need not be in any particular order.
void DoomscrollerMap::print() const
{
    std::string currName;
    double numHrs;
    for (int i = 0; i < doomscrollers.size(); i++)
    {
        doomscrollers.get(i, currName, numHrs);
        std::cout << currName << " " << numHrs << std::endl;
    }
}
