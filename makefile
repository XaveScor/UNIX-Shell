SRCMODULES = main.c list.c exec.c Xstring.c input.c flag.c
OBJMODULES = $(SRCMODULES:.c=.o)
CFLAGS = -std=c99 -O0
FILENAME = Xshell
TEMP_MAKE_FILE = deps.mk

$(FILENAME):	$(OBJMODULES)
		$(CC) $^ -o $@ $(CFLAGS)

%.o: %.c %.h
		$(CC) -c $< $(CFLAGS) -o $@
		
ifneq (clean, $(MAKECMDGOALS))
-include $(TEMP_MAKE_FILE)
endif

$(TEMP_MAKE_FILE): $(SRCMODULES)
		$(CC) -MM $^ > $@

clean:
		$(RM) $(OBJMODULES) $(TEMP_MAKE_FILE)

run:
		./$(FILENAME)
