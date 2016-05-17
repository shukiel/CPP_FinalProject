Changed all members to m_XXXXXXX form
Added Musician, Actor and Dancer Classes
Show is now an abstract class! 
Changed a few methods in Show to be virtual

TODO :: make operators work both ways (like A + B <==> B + A)

TODO :: Actor.cpp method makeDrama()  DONE
TODO :: Musician.cpp method makeSolo()    DONE
TODO :: Dancer.cpp method makeAcrobatics()   DONE

Show holds all participants, so I changed TheaterShow, MusicShow and DanceShow.
TODO :: MusicShow.cpp methods encore() and drinkBeerAndSmokeCiggarettes() //DONE
TODO :: before dancer running the method makeShow() we need to check if the dancer has been injured - there is a isShowPossible //DONE added a check in Show::makeShow -> is the show is not possible it throws an exception!
TODO :: Musical.cpp a lot of duplications // Enosh - What We should do with that???? //DONE

Show::getCost() now using Employee::calcSalary()
TheaterShow, MusicShow and DanceShow now using Show::getCost() to calculate the salaries


9/5/2016 evening:
added Crew::MAX_NUM_OF_BEERS (the num of beers that define too drunk)
added Participator::EGO_TRESHOLD (ego is defined as float between 0->1 that define the ego level, ego treshold is a value between 0->1)
added Actor:: CHANCE_TO_DRAMA 
added Participator::ADDITTION_TO_EGO 
added Crew::CHANCE_TO_DRINK_BEER


Actor::doPartInShow is no longer const (can affect Ego level)
Dancer::doPartInShow is no longer const (can affect Ego level and isInjured)
Musician::doPartInShow is no longer const (can affect Ego level and isInjured)


TODO::Make a random function that returns a value between 0->1  !!!!DONE in each class !!!
Should implement Show::doShow to avoid redunduncy in code.      !!!!DONE 

added bool Paticipator::isCanPerform() // Also done for Dancer
added bool Crew::isTooDrunk()


TODO :: Need to add a place where the Crew drinks, maybe in makeShow()? //DONE
TODO :: Fix Musical... I have no Idea what to do there... //DONE
TODO :: TicketOffice.CPP   (Enosh - Hopefully i'll get that later today....)
TODO :: Main !!!!
