#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int fd1, fd2;
    char buffer[100];
    int bytesRead;

    // Open File1.txt for reading
    fd1 = open("File1.txt", O_RDONLY);

    if (fd1 < 0) {
        printf("Error opening File1.txt\n");
        return 1;
    }

    // Create/Open File2.txt for writing
    fd2 = open("File2.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (fd2 < 0) {
        printf("Error opening File2.txt\n");
        close(fd1);
        return 1;
    }

    // Read from File1 and write to File2
    while ((bytesRead = read(fd1, buffer, sizeof(buffer))) > 0) {
        write(fd2, buffer, bytesRead);
    }

    // Close both files
    close(fd1);
    close(fd2);

    printf("File copied successfully!\n");

    return 0;
}
