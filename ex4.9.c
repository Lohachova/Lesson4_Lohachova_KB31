#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/utsname.h>

void help_print()
{
    printf("-h                  Print help and exit\n");
}

int
main(int argc,char** argv)
{
    char* opts = "h";

    struct utsname myinfo;
    uname(&myinfo);
    char buff[255];
    gethostname(buff, 255);

    int opt;
    while( (opt = getopt(argc, argv, opts)) != -1 )
    {
        switch (opt)
        {
            case 'h':
            {
                help_print();
                return EXIT_SUCCESS;
            }
            
        }
    }

    printf("Ім'я машини: %s\n",myinfo.nodename);
    printf("Тип машини: %s\n",myinfo.machine);
    printf("Ім'я системи: %s\n",myinfo.sysname);
    printf("Номер випуску: %s\n",myinfo.release);
    printf("Версія: %s\n",myinfo.version);
    printf("Ім'я хоста: %s\n",buff);
    printf("ІD Хоста: %ld\n",gethostid());
    
    return EXIT_SUCCESS;
}
