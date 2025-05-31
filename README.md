# Theatre

A service for buying tickets for various types of theatres:
Opera Theatre;
Drama Theatre;
Ballet Theatre;
Movie Theatre;

Every one of them inherits a base class of "Theatre".

Each theatre has a few properties, including a vector of all the "sessions", tickets for which are availible for purchase.

Sessions also have their own class hierarchy, for example: "HorrorMovie" inherits from class "Movie", which inherits from the base class "Session".
Every session like a "Play", a "Ballet", a "Choir", etc, will inherit from the base class.

Sessions have different properties, which are informative to the potential client, like the name of the performance/movie, duration, cost, seats left for purchase, age restrictions and so on.

Client navigates through this service by selecting the type of theatre, then the specific session he is interested in, and ordering a ticket.
After ordering, a client will see important information about the session, like, when it is, what is the address of the theatre, etc.



The project will be implemented in c++ using QT for GUI.
