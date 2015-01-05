SRCMODULES = main.c list.c exec.c Xstring.c input.c
OBJMODULES = $(SRCMODULES:.c=.o)
CFLAGS = -std=c99 -O0
FILENAME = Xshell
TEMP_MAKE_FILE = deps.mk
OUTPUT_TYPE = -o

$(FILENAME):	$(OBJMODULES)
		echo $^
		$(CC) $^ $(OUTPUT_TYPE) $@ $(CFLAGS)

%.o: %.c %.h
		$(CC) -c $< $(CFLAGS) $(OUTPUT_TYPE) $@

ifneq (clean, $(MAKECMDGOALS))
-include $(TEMP_MAKE_FILE)
endif

$(TEMP_MAKE_FILE): $(SRCMODULES)
		$(CC) -MM $^ > $@

clean:
		$(RM) $(OBJMODULES) $(TEMP_MAKE_FILE)

run:
		./$(FILENAME)
