# UNO

#### Team Members:
- Lam Kam Chung, sam,(UID:3035788118)
- Leung Sin Wai, Jeffrey (UID:3035821544)

#### Game Description & Game rules
UNO is one of the most famous card games in the world. It is popular because of its easy-to-learn rules. We are trying to build UNO game in C/C++ based on text. So that it can run by Linux and via SSH. In case you do not know what is Uno, there are 108 cards in the deck, generally divided by four colours: Red, Yellow, Green, Blue. For each colour, it contains one "0" card and two "1" through "9" cards. Other than normal cards, there are some function cards: two "Skip", "Reverse" and "Draw 2" cards for each colour. Finally, it consist of four "Wild" and four "Wild Draw 4". More in-depth function will be introduced in rules section.


monpoly is one of the most famous board games in the world. It is popular because of its easy-to-learn rules. We are trying to build monopoly game in C/C++ based on text. So that it can run by Linux and via SSH. In case you do not know what is monopoly, players roll dice to move across the game board in order to trade properties.players will be given a certain amount of money when they pass through the starting point.players pay rent to each other until they go bankrupt in order to select the remaining winner.random events such as tax squares,Chance and Community Chest cards is also presented in this game. More in-depth function will be introduced in rules section


###### features
1. Rolling of dice
   the rolling of dice is generated by a random function(element1)
2. The total money amount of players
   using dynamic memory management to update the current situation.(element2,3)
3. record the game status
   -game status is output to a file for recording (element4)
4. Chance and Community Chest cards
   -drawing random events from a list(element1)
5. contains different function to different file (element5)
6. Records and reading the users location (element2,3)
   -using vector to store the users location and using dynamic memory management update immediately(element2,3)
7.jail
   -players will go to jail when the 'jail card' is drawed from the Chance and Community Chest cards list.player will be skipped for 2 turns.user status is updated by vector and
   using dynamic memory management update immediately(element2,3)
