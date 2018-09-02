 #include <iostream>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#include<sys/ioctl.h>
#include<linux/spi/spidev.h>
#include<fcntl.h>
#include<cstring>

#define ip "192.168.1.51"
#define port 1234
using namespace std;

int fd;

int bufferlen=100;

void  injectPacket(unsigned char);

int main()
{
        unsigned int speed= 1000000;
        fd=open("/dev/spidev0.0",O_RDWR);
        ioctl(fd,SPI_IOC_WR_MAX_SPEED_HZ,&speed);
        char fvalue;
        struct sockaddr_in thiss, that;
        int mysocket,recv_len;

        mysocket=socket(AF_INET,SOCK_DGRAM,0);
        int slen=sizeof(thiss);

        char buffer[bufferlen];

        memset((char*) &that,0,sizeof(that));


         thiss.sin_family=AF_INET;
        thiss.sin_port=htons(port);
        thiss.sin_addr.s_addr=INADDR_ANY;

        if(bind(mysocket,(struct sockaddr*)&thiss,sizeof(thiss))<0)
        {
                cout<<"\nBinding Error";
                return 0;
        }
        else
        cout<<"\nBinded properly";
        cout<<"Test";
        cout<<"\nAbove while";
        while(1)
        {       for(int k=0;k<100;k++)
                {buffer[k]='\0';}
                recv_len=recvfrom(mysocket,(char *)buffer,bufferlen,0,(sockaddr*)$
                puts(buffer);
                //fvalue=buffer;
 //      injectPacket(fvalue);
                /*cout<<"Server:";
                // gets(buffer);
                cin.getline(buffer,bufferlen);
                if(sendto(mysocket,buffer,bufferlen,0,(struct sockaddr*)&thiss,sl$
                cout<<"\nSending Error";*/
        }
        //close(mysocket);

        return 0;
}
