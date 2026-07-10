CC=gcc

CFLAGS=	-Wall	-g	-Wextra

TARGET=rev_singleList

OBJS=rev_singleList.o

$(TARGET):	$(OBJS)
	$(CC)	$(CFLAGS)	-o	$(TARGET)	$(OBJS)

rev_singleList.o:rev_singleList.c

	$(CC)	$(CFLAGS)	-c	rev_singleList.c

clean:
	rm -f $(TARGET) $(OBJS)
