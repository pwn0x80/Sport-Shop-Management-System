
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"
#define RESET "\x1B[0m"

enum access { admin = 0, shopowner = 1 };

typedef struct data {
  char user[20]; // user name
  int mode_set;  // permission set
} DATA_ACCESS;

extern void Mode();
extern void print_image();
