Changed all members to m_XXXXXXX form
Added Musician, Actor and Dancer Classes
Show is now an abstract class! 
Changed a few methods in Show to be virtual

TODO :: make operators work both ways (like A + B <==> B + A)

TODO :: Actor.cpp method makeDrama()
TODO :: Musician.cpp method makeSolo()
TODO :: Dancer.cpp method makeAcrobatics()

Show holds all participants, so I changed TheaterShow, MusicShow and DanceShow.
TODO :: MusicShow.cpp methods encore() and drinkBeerAndSmokeCiggarettes()
TODO :: before dancer running the method makeShow() we need to check if the dancer has been injured
TODO :: Musical.cpp a lot of duplications

Show::getCost() now using Employee::calcSalary()
TheaterShow, MusicShow and DanceShow now using Show::getCost() to calculate the salaries