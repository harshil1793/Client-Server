# Client-Server

Exchange of information between two or more process via common message system queue. Each message is given an identification which can processes and select the appropriate message and it must share a common key to gain access to the queue in the first place.


Before a process can send or receive a message, the queue must be initialized Operations to send and receive messages are performed by the msgsnd() and msgrcv() functions, respectively.
