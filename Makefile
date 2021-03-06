PROG = CMS
OBJS = login.o actions.o login.o client.o
CC = g++
CFLAGS = -ansi -pedantic -Wall
LFLAGS =			#default path should be ok
LIBS = 

$(PROG) : $(OBJS) 
	$(CC) $(LFLAGS) $^ -o $@ $(LIBS)

clean:
	rm -rf $(OBJS)

realclean:
	rm -rf $(PROG) $(OBJS) core

#default rule for cpp to .o
%.o : %.cpp
	$(CC) -c $(CFLAGS) $< -o $@
