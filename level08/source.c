#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

void log_wrapper(FILE *log_fp, char *filename, char *msg)
{
    char    buf[254];   // [rbp-0x110]

    strcpy(buf, filename);
    snprintf(buf + strlen(buf), 254 - strlen(buf), msg);
    buf[strcspn(buf, "\n")] = '\0';
    fprintf(log_fp, "LOG: %s\n", buf);
}

int main(int argc, char **argv)
{
    char    dst_path[100];      // [rbp-0x70]
    char    c;                  // [rbp-0x71]
    int     fd;                 // [rbp-0x78]
    FILE    *log_fp;            // [rbp-0x88]
    FILE    *src_fp;            // [rbp-0x80]

    c = 0xff;
    fd = 0xffffffff;

    if (argc != 2)
        printf("Usage: %s filename\n", argv[0]);

    log_fp = fopen("./backups/.log", "w");
    if (!log_fp)
    {
        printf("ERROR: Failed to open %s\n", "./backups/.log");
        exit(1);
    }
    log_wrapper(log_fp, argv[1], "Starting back up: ");
    src_fp = fopen(argv[1], "r");
    if (!src_fp)
    {
        printf("ERROR: Failed to open %s\n", argv[1]);
        exit(1);
    }
    strcpy(dst_path, "./backups/");
    strncat(dst_path, argv[1], 99 - strlen(dst_path));
    fd = open(dst_path, 0xc1, 0x1b0);
    if (fd < 0)
    {
        printf("ERROR: Failed to open %s%s\n", "./backups/", argv[1]);
        exit(1);
    }
    while ((c = fgetc(src_fp)) != 0xff)
        write(fd, &c, 1);
    
    log_wrapper(log_fp, argv[1], "Finished back up ");
    fclose(src_fp);
    close(fd);
    return (0);
}