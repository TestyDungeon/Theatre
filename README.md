# Theatre

A service for buying tickets for various types of theatres:
Opera Theatre;
Drama Theatre;
Movie Theatre;

Every one of them inherits a base class of "Theatre".

Each theatre has a few properties, including a vector of all the "sessions", tickets for which are availible for purchase.

Sessions also have their own class hierarchy, for example: "HorrorMovie" inherits from class "Movie", which inherits from the base class "Session".
Every session like a "Play", a "Choir", etc, will inherit from the base class.

Polymorphism lies in how different types Theatres have different logic in terms of which types of tickets and how many can a single user order, which depends on some conditions. Another one lies in calculating the price of the order, based on how much different ticket types cost, and what extras the user chose.

I "tried" to make it modular and scalable, to my best ability.

Client navigates through this service by selecting the type of theatre, then the specific session he is interested in, and ordering a ticket.
