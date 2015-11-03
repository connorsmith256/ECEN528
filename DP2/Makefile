CC        =  gcc
CFLAGS1   =  -O3 -m32                   # for production code
CFLAGS1   =  -g -m32                    # for debugging

# The flags above assume the target OS is Linux.  The flag
# settings below should be used if the target is HP-UX.
# The flag settings are appropriate for cc, not gcc.
HPUXFLGS1 = -Aa +O3 +DAportable         # for production code
HPUXFLGS2 = -Aa -g  +DAportable         # for debugging
HPUXCC    = cc

# The target name below should be changed for each version
# of the gold standard or distribution code.

TARGET    = mydlx
OBJ       = bin/mem.o bin/clib.o bin/dlx.o bin/stall.o

$(TARGET): $(OBJ)
		@$(CC) $(CFLAGS1) $(OBJ) -o $(TARGET) -lm

bin/mem.o: src/mem.c src/mem.h
		@$(CC) $(CFLAGS1) -c src/mem.c -o bin/mem.o

bin/dlx.o: src/dlx.c src/dlx.h src/mem.h src/ops.h src/dlxdef.h src/stalldef.h
		@$(CC) $(CFLAGS1) -c src/dlx.c -o bin/dlx.o

bin/clib.o: src/clib.c src/mem.h src/dlx.h
		@$(CC) $(CFLAGS1) -c src/clib.c -o bin/clib.o

bin/stall.o: src/stall.c src/stalldef.h
		@$(CC) $(CFLAGS1) -c src/stall.c -o bin/stall.o

clean:
		@rm bin/*.o $(TARGET)
