Changed all members to m_XXXXXXX form
Added Musician, Actor and Dancer Classes
Show is now an abstract class! 
Changed a few methods in Show to be virtual

TODO :: make operators work both ways (like A + B <==> B + A)

TODO :: Actor.cpp method makeDrama()

Show holds all participants, so I changed TheaterShow.
TODO :: MusicShow and DanceShow has to be change too.

Show::getCost() now using Employee::calcSalary()
TheaterShow, MusicShow and DanceShow now using Show::getCost() to calculate the salaries