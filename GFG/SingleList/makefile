CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = main

SRCS = main.c addStart.c addEnd.c addMid.c addPos.c delStart.c delEnd.c delPos.c delMid.c reverserListNode.c reverserListData.c printList.c printListR.c sortListData.c sortListNode.c creatNode.c deleteList.c findMid.c detectLoop.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)
