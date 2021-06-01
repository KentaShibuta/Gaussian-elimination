PROGRAM	=	matrix_solv_gauss
OBJS	=	gauss.o global_variable.o malloc.o main.o
CC	=	gcc
CFLAGS	= -g -Wall

$(PROGRAM):$(OBJS)
	$(CC) $(CFLAGS) -o $(PROGRAM) $(OBJS) -lm

clean:
	-rm $(OBJS) $(PROGRAM)

all: clean $(PROGRAM)