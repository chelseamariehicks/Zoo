# Zoo
Program for a one-player zoo tycoon game.

Create a zoo tycoon game that allows players to run a zoo business. When users begin they have a set amount of money and are required to purchase 1 or 2 of each animal available (tigers, penguins, and turtles) to start the game. Each animal costs a different amount, have different feeding costs, and return a different profit at the end of the day. 
Once the player starts the game, a random event occurs that causes either:
1. A random animal type to die and be removed from the zoo
2. A random bonus amount is added to the user’s money for each tiger in the zoo 
3. A random animal type gives birth (and the litter of each animal has a different
size, tiger -> 1, penguin -> 5, turtle -> 10) 
4. Nothing at all

At the end of the day, the user is given the option to buy another animal and all of the animal ages as well as the tracker for the number of days is incremented by 1. At the start of the next day, the user must pay to feed the animals and then again a random event occurs. This cycle will continue (feed animals, random event, buy animal option presented, next day in the game) until the user either elects to quit (option given at the same time the user is presented the option to buy an animal) or the user goes bankrupt.
