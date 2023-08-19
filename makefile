CC=gcc
CFLAGS=-I
DEPS=comdef.h linkedList.h linkedListInt.h stackInt.h
TARGET_LL=test_ll
TARGET_STACK=test_stack
TARGET_BUILD_ALL=all
TARGET_CLEAN_BUILD_ALL=cleanbuildall

$(TARGET_BUILD_ALL):
	@echo ==========Building All targets============
	make -f makefile test_stack
	make -f makefile test_ll
	@echo ==========All targets built successful============

$(TARGET_CLEAN_BUILD_ALL):
	@echo ========Cleaning all targets=======
	make -f makefile clean
	make -f makefile $(TARGET_BUILD_ALL)

stackInt.o: stackInt.c $(DEPS)
	@echo Compiling $< 
	$(CC) -c -o $@ $< $(CFLAGS).

test_stackInt.o: test_stackInt.c $(DEPS)
	@echo Compiling $< 
	$(CC) -c -o $@ $< $(CFLAGS).

linkedListInt.o: linkedListInt.c $(DEPS)
	@echo Compiling $< 
	$(CC) -c -o $@ $< $(CFLAGS).

test_linkedListInt.o: test_linkedListInt.c $(DEPS)
	@echo Compiling $< 
	$(CC) -c -o $@ $< $(CFLAGS).

$(TARGET_LL): linkedListInt.o test_linkedListInt.o
	@echo Linking OBJ Files[$^]
	$(CC) -o $@ $^
	@echo Build Successful. Executable Created - $(TARGET_LL) 

$(TARGET_STACK): stackInt.o test_stackInt.o
	@echo Linking OBJ Files[$^]
	$(CC) -o $@ $^
	@echo Build Successful. Executable Created - $(TARGET_STACK) 

clean:
	@echo Cleaning targets
	rm ./*.o ./$(TARGET_LL) ./$(TARGET_STACK)
