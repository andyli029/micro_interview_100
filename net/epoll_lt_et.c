/* 
 * need to ipmrove
 *url:http://www.cnblogs.com/yuuyuu/p/5103744.html
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/epoll.h>

/* ��󻺴�����С */
#define MAX_BUFFER_SIZE 5
/* epoll�������� */
#define MAX_EPOLL_EVENTS 20
/* LTģʽ */
#define EPOLL_LT 0
/* ETģʽ */
#define EPOLL_ET 1
/* �ļ��������������� */
#define FD_BLOCK 0
/* �ļ����������÷����� */
#define FD_NONBLOCK 1

/* �����ļ�Ϊ������ */
int set_nonblock(int fd)
{
    int old_flags = fcntl(fd, F_GETFL);
    fcntl(fd, F_SETFL, old_flags | O_NONBLOCK);
    return old_flags;
}

/* ע���ļ���������epoll�����������¼�ΪEPOLLIN(�ɶ��¼�) */
void addfd_to_epoll(int epoll_fd, int fd, int epoll_type, int block_type)
{
    struct epoll_event ep_event;
    ep_event.data.fd = fd;
    ep_event.events = EPOLLIN;

    /* �����ETģʽ������EPOLLET */
    if (epoll_type == EPOLL_ET)
        ep_event.events |= EPOLLET;

    /* �����Ƿ����� */
    if (block_type == FD_NONBLOCK)
        set_nonblock(fd);

    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fd, &ep_event);
}

/* LT�������� */
void epoll_lt(int sockfd)
{
    char buffer[MAX_BUFFER_SIZE];
    int ret;

    memset(buffer, 0, MAX_BUFFER_SIZE);
    printf("��ʼrecv()...\n");
    ret = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    printf("ret = %d\n", ret);
    if (ret > 0)
        printf("�յ���Ϣ:%s, ��%d���ֽ�\n", buffer, ret);
    else
    {
        if (ret == 0)
            printf("�ͻ��������رգ�����\n");
        close(sockfd);
    }

    printf("LT�������������\n");
}

/* ��ѭ����ET�������� */
void epoll_et_loop(int sockfd)
{
    char buffer[MAX_BUFFER_SIZE];
    int ret;

    printf("��ѭ����ET��ȡ���ݿ�ʼ...\n");
    while (1)
    {
        memset(buffer, 0, MAX_BUFFER_SIZE);
        ret = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
        if (ret == -1)
        {
            if (errno == EAGAIN || errno == EWOULDBLOCK)
            {
                printf("ѭ�������������ݣ�����\n");
                break;
            }
            close(sockfd);
            break;
        }
        else if (ret == 0)
        {
            printf("�ͻ��������ر����󣡣���\n");
            close(sockfd);
            break;
        }
        else
            printf("�յ���Ϣ:%s, ��%d���ֽ�\n", buffer, ret);
    }
    printf("��ѭ����ET�������������\n");
}


/* ����ѭ����ET�������̣���epoll_et_loop����һ��whileѭ�� */
void epoll_et_nonloop(int sockfd)
{
    char buffer[MAX_BUFFER_SIZE];
    int ret;

    printf("����ѭ����ETģʽ��ʼ��ȡ����...\n");
    memset(buffer, 0, MAX_BUFFER_SIZE);
    ret = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    if (ret > 0)
    {
        printf("�յ���Ϣ:%s, ��%d���ֽ�\n", buffer, ret);
    }
    else
    {
        if (ret == 0)
            printf("�ͻ��������ر����ӣ�����\n");
        close(sockfd);
    }

    printf("����ѭ����ETģʽ�������������\n");
}

/* ����epoll�ķ��ؽ�� */
void epoll_process(int epollfd, struct epoll_event *events, int number, int 
sockfd, int epoll_type, int block_type)
{
    struct sockaddr_in client_addr;
    socklen_t client_addrlen;
    int newfd, connfd;
    int i;

    for (i = 0; i < number; i++)
    {
        newfd = events[i].data.fd;
        if (newfd == sockfd)
        {
            printf("==================��һ��accept()=================\n");
            printf("accept()��ʼ...\n");

            /* ����3�룬ģ��һ����æ�ķ�������������������accept���� */
            printf("��ʼ����3��...\n");
            sleep(3);
            printf("����3�����������\n");

            client_addrlen = sizeof(client_addr);
            connfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addrlen);
            printf("connfd = %d\n", connfd);

            /* ע�������ӵ�socket��epoll����������LT����ET�����������Ƿ����� */
            addfd_to_epoll(epollfd, connfd, epoll_type, block_type);
            printf("accept()����������\n");
        }
        else if (events[i].events & EPOLLIN)
        {
            /* �ɶ��¼��������� */

            if (epoll_type == EPOLL_LT)    
            {
                printf("============================>ˮƽ������ʼ...\n");
                epoll_lt(newfd);
            }
            else if (epoll_type == EPOLL_ET)
            {
                printf("============================>��Ե������ʼ...\n");

                /* ��ѭ����ETģʽ */
                epoll_et_loop(newfd);

                /* ����ѭ����ETģʽ */
                //epoll_et_nonloop(newfd);
            }
        }
        else
            printf("�����¼�����...\n");
    }
}

/* ������ */
void err_exit(char *msg)
{
    perror(msg);
    exit(1);
}

/* ����socket */
int create_socket(const char *ip, const int port_number)
{
    struct sockaddr_in server_addr;
    int sockfd, reuse = 1;

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_number);

    if (inet_pton(PF_INET, ip, &server_addr.sin_addr) == -1)
        err_exit("inet_pton() error");

    if ((sockfd = socket(PF_INET, SOCK_STREAM, 0)) == -1)
        err_exit("socket() error");

    /* ���ø���socket��ַ */
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) == -1)
        err_exit("setsockopt() error");

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
        err_exit("bind() error");

    if (listen(sockfd, 5) == -1)
        err_exit("listen() error");

    return sockfd;
}

/* main���� */
int main(int argc, const char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "usage:%s ip_address port_number\n", argv[0]);
        exit(1);
    }

    int sockfd, epollfd, number;

    sockfd = create_socket(argv[1], atoi(argv[2]));
    struct epoll_event events[MAX_EPOLL_EVENTS];

    /* linux�ں�2.6.27����º�������epoll_create(int size)һ���Ĺ��ܣ���ȥ�������õ�size���� */
    if ((epollfd = epoll_create1(0)) == -1)
        err_exit("epoll_create1() error");

    /* ������������Լ�����sockfd����epoll_wait����ʱ���ض����¼�������
     * �����������Ǻ��Ժ������������������IOû���壬��������Ϊ������IO */

    /* sockfd����������LTģʽ */
    addfd_to_epoll(epollfd, sockfd, EPOLL_LT, FD_NONBLOCK);

    /* sockfd����������ETģʽ */
    //addfd_to_epoll(epollfd, sockfd, EPOLL_ET, FD_NONBLOCK);

   
    while (1)
    {
        number = epoll_wait(epollfd, events, MAX_EPOLL_EVENTS, -1);
        if (number == -1)
            err_exit("epoll_wait() error");
        else
        {
            /* ���µ�LT��ET���Լ��Ƿ��������������accept()�������ص��ļ��������������������connfd */

            /* connfd:������LTģʽ */
            epoll_process(epollfd, events, number, sockfd, EPOLL_LT, FD_BLOCK);

            /* connfd:��������LTģʽ */
            //epoll_process(epollfd, events, number, sockfd, EPOLL_LT, FD_NONBLOCK);

            /* connfd:������ETģʽ */
            //epoll_process(epollfd, events, number, sockfd, EPOLL_ET, FD_BLOCK);

            /* connfd:��������ETģʽ */
            //epoll_process(epollfd, events, number, sockfd, EPOLL_ET, FD_NONBLOCK);
        }
    }

    close(sockfd);
    return 0;
}