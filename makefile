SRCMODULES = main.c list.c exec.c Xstring.c input.c
OBJMODULES = $(SRCMODULES:.c=.o)
CFLAGS = -std=c99 -O0
FILENAME = Xshell
TEMP_MAKE_FILE = deps.mk

$(FILENAME):	$(OBJMODULES)
		$(CC) $^ -o $@ $(CFLAGS); make clean

%.o: %.c %.h
		$(CC) -c $< $(CFLAGS) -o $@
		
ifneq (clean, $(MAKECMDGOALS))
-include $(TEMP_MAKE_FILE)
endif

$(TEMP_MAKE_FILE): $(SRCMODULES)
		$(CC) -MM $^ > $@

clean:		
		rm -f $(OBJMODULES) $(TEMP_MAKE_FILE)
