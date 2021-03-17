# Monopoly

#### Team Members:
- Lam Kam Chung, Sam (UID:3035788118)
- Leung Sin Wai, Jeffrey (UID:3035821544)

#### Game Description & Game rules

Monopoly is one of the most famous board games in the world. It is popular because of its easy-to-learn rules. We are trying to build monopoly game in C/C++ based on text. So that it can run by Linux and via SSH. In case you do not know what is monopoly, players roll dice to move across the game board in order to trade properties.players will be given a certain amount of money when they pass through the starting point.once players land on other players' property, players have to pay rent to the owner.random events such as tax squares,Chance and Community Chest cards is also presented in this game.player may gain or loose their money though the random events generated by drawing the Chance and Community Chest cards or loose money when they land on a tax squares.the game runs until players go bankrupt in order to select the remaining winner.


#### Features
1. Rolling of dice
    - the rolling of dice is generated by a random function(element1)
2. The total money amount of players
    - using dynamic memory management to update the current situation.(element2,3)
3. Record the game status
    - game status is output to a file for recording (element4)
4. Chance and Community Chest cards
    - drawing random events from a list(element1)
5. Contains different functions to different files (element5)
6. Records and reading the users location 
    - using vector to store the users location and using dynamic memory management update immediately(element2,3)
7. Jail
    - players will go to jail when the 'jail card' is drawed from the Chance and Community Chest cards list. Player will be skipped for 3 turns. User status is updated by vector and using dynamic memory management update immediately(element2,3)
