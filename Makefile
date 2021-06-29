LIBS  = -lkernel32 -luser32 -lgdi32 -lopengl32
CFLAGS = -Wall

OBJ = Pile.o

SRCS = $(OBJ:%.o=%.c)

test: $(SRCS)
    gcc -o $@  $(CFLAGS) $(LIBS) $(SRCS)
