#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<stdio.h>
#include<string.h>

struct message
{
	long int m_types; /* message type */
	char msg[50];  /* message to be sent/receive*/
};

int main(void)
{
	int msgid,send;
	struct message m1;
	
	msgid=msgget((key_t)1234,0666|IPC_CREAT); /* This will create a message queue using 1234 as key */
	if(msgid<0) perror("msg");

	printf("\nEnter the message: ");
	scanf("%[^\n]s",m1.msg);
	//	m1.m_types=3; /* to send message with particular message type*/
	send=msgsnd(msgid,(void *)&m1,50,0); /* receiving message from messagqueue.*/
	if(send<0) perror("send");

	return 0;
}
