#include <fcntl.h>
#include <string.h>
#include <syslog.h>
#include <unistd.h>

/* Write a string to a file 
 * parameters:  filename to write to (create if it doesn't exist, assume directory already exists)
 * 		data to write
 *
 */
int writeFile(const char *filename, const char *buf) {
  int fd = creat (filename, 0644);
  if (fd == -1) {
    syslog(LOG_ERR, "could not open file");
    return -1;
  }
  /* write the string in 'buf' to 'fd' */
  size_t count = strlen (buf);
  ssize_t nr = write (fd, buf, count);
  if (nr == -1) {
    /* error, check errno */
    return -1;
  }
  else if (nr != count) {
    /* partial write */
    return -1;
  }

}

int main(int argc, char *argv[]) {
  openlog(NULL, LOG_CONS, LOG_USER);

  if (argc != 3) {
    syslog(LOG_ERR, "writer requires 2 arguments: file to write and data to write.");
    closelog();
    return 1;
  }

  syslog(LOG_DEBUG, "Writing %s to %s\n", argv[2], argv[1]);

  int wr = writeFile(argv[1], argv[2]);
  if (wr == -1) {
    syslog(LOG_ERR, "Failed to write file");
    closelog();
    return 1;
  }

  closelog();
  return 0;
}
