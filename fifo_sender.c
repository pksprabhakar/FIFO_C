#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define FIFO_PATH "/tmp/myfifo"
#define MESSAGE "Hello from sender!\n"

int main() {
    int fd;

    // Open FIFO for writing
    fd = open(FIFO_PATH, O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Write message to FIFO
    if (write(fd, MESSAGE, strlen(MESSAGE)) == -1) {
        perror("write");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("Message sent: %s", MESSAGE);

    // Close the FIFO
    close(fd);
    return 0;
}
