CC = gcc
CFLAGS= -Wall -I ./include
OBJS=http-parser.o

trial-http: trial-http.h $(OBJS)
	$(CC) $(CFLAGS) -o bin/trial-http main.c $(OBJS)

$(OBJS): trial-http.h
