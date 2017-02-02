#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<string.h>

int main(void)
{
	int msgid,rcv;
	struct message
	{
		long int m_types; /* message type */ 
		char msg[50];     /* message to be sent/receive*/
	}m1;

	msgid=msgget((key_t)1234,0666|IPC_CREAT); /* This will create a message queue using 1234 as key */
	if(msgid<0) perror("msg");

	rcv=msgrcv(msgid,(void *)&m1,50,0,0); /* receiving latest message from messagqueue.*/
	//rcv=msgrcv(msgid,(void *)&m1,50,mtype,0); /* receiving particular message with mtype from messagqueue.*/
	if(rcv<0) perror("rcv");
		
	printf("\nReceived message is: %s\n",m1.msg);
	return 0;
}