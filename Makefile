CC = gcc
CFLAGS = -g -Wall -Wextra -pedantic -ansi
LDLIBS = -lscreen -Llib
HFLAGS = -I ./include 

O = ./obj/
C = ./src/
H = ./include/
BIN = ./bin/

EXE = $(BIN)game
OBJ = $(O)game_loop.o $(O)command.o $(O)game.o $(O)graphic_engine.o $(O)space.o $(O)object.o $(O)game_management.o $(O)player.o $(O)set.o $(O)enemy.o $(O)link.o $(O)inventory.o $(O)dialogue.o $(O)game_rules.o
TESTS = space_test set_test enemy_test link_test object_test command_test game_management_test player_test inventory_test game_test
TEST_BINS = $(addprefix $(BIN),$(TESTS))

.PHONY: all clear clean game game_debug Doxygen run run_log run_v run_log_v test $(TESTS)

all: $(EXE) test

$(BIN):
	mkdir -p $(BIN)

$(EXE): $(OBJ) | $(BIN)
	$(CC) -o $@ $(OBJ) $(LDLIBS)

clear: 	
	rm -f $(O)*.o

clean: 
	rm -f $(O)*.o core game space_test set_test enemy_test link_test object_test command_test game_management_test player_test inventory_test game_test $(EXE) $(TEST_BINS)

test: $(TEST_BINS)


game: $(EXE)

##### DEBUG OPTION ##########
game_debug:
	$(MAKE) clean
	$(MAKE) CFLAGS="$(CFLAGS) -DDEBUG" $(EXE)

Doxygen:
	@echo Documenting project with doxygen...
	@doxygen Doxyfile

run: $(EXE)
	@echo Running game with custom .dat file...
	@$(EXE) data/nuevo.dat

run_log: $(EXE)
	@echo Running game with custom .dat file...
	@$(EXE) data/nuevo.dat -l fchlog.log

run_v: $(EXE)
	@echo Running valgrind through the game executable...
	@valgrind --leak-check=full $(EXE) data/nuevo.dat

run_log_v: $(EXE)
	@echo Running valgrind through the game executable...
	@valgrind --leak-check=full $(EXE) data/nuevo.dat -l fchlog.log

$(O)command.o: $(C)command.c $(H)command.h $(H)types.h
	@echo Compiling $<...
	$(CC) $(CFLAGS) -c $(HFLAGS) -o $@ $<

$(O)enemy.o: $(C)enemy.c $(H)enemy.h $(H)types.h
	@echo Compiling $<...
	$(CC) $(CFLAGS) -c $(HFLAGS) -o $@ $<

$(O)game.o: $(C)game.c $(H)game.h $(H)command.h $(H)types.h $(H)space.h $(H)player.h $(H)object.h $(H)enemy.h $(H)game_management.h $(H)dialogue.h
	@echo Compiling $<...
	$(CC) $(CFLAGS) -c $(HFLAGS)-o $@ $<

$(O)game_loop.o: $(C)game_loop.c $(H)game_rules.h $(H)graphic_engine.h $(H)game.h $(H)command.h $(H)types.h $(H)space.h $(H)player.h $(H)object.h $(H)enemy.h
	@echo Compiling $<...
	$(CC) $(CFLAGS) -c $(HFLAGS)-o $@ $<

$(O)game_management.o: $(C)game_management.c $(H)game_management.h $(H)game.h $(H)command.h $(H)types.h $(H)space.h $(H)player.h $(H)object.h $(H)enemy.h $(H)dialogue.h
	@echo Compiling $<...
	$(CC) $(CFLAGS) -c $(HFLAGS)-o $@ $<

$(O)object.o: $(C)object.c $(H)object.h $(H)types.h
	@echo Compiling $<...
	$(CC) $(CFLAGS) -c $(HFLAGS) -o $@ $<

$(O)graphic_engine.o: $(C)graphic_engine.c $(H)graphic_engine.h $(H)game.h $(H)command.h $(H)types.h $(H)space.h $(H)player.h $(H)object.h $(H)enemy.h $(H)libscreen.h
	@echo Compiling $<...
	$(CC) $(CFLAGS) -c $(HFLAGS) -o $@ $<

$(O)dialogue.o: $(C)dialogue.c $(H)dialogue.h $(H)types.h
	@echo Compiling $<...
	$(CC) $(CFLAGS) -c $(HFLAGS) -o $@ $<

$(O)player.o: $(C)player.c $(H)player.h $(H)types.h
	@echo Compiling $<...
	$(CC) $(CFLAGS) -c $(HFLAGS) -o $@ $<

$(O)set.o: $(C)set.c $(H)set.h $(H)types.h
	@echo Compiling $<...
	$(CC) $(CFLAGS) -c $(HFLAGS) -o $@ $<

$(O)space.o: $(C)space.c $(H)space.h $(H)types.h $(H)set.h
	@echo Compiling $<...
	$(CC) $(CFLAGS) -c $(HFLAGS) -o $@ $<

$(O)link.o: $(C)link.c $(H)link.h $(H)types.h
	@echo Compiling $<...
	$(CC) $(CFLAGS) -c $(HFLAGS) -o $@ $<

$(O)inventory.o: $(C)inventory.c $(H)set.h $(H)types.h $(H)inventory.h
	@echo Compiling $<...
	$(CC) $(CFLAGS) -c $(HFLAGS) -o $@ $<

$(O)game_rules.o: $(C)game_rules.c $(H)game.h $(H)object.h $(H)space.h $(H)set.h $(H)types.h $(H)inventory.h
	@echo Compiling $<...
	$(CC) $(CFLAGS) -c $(HFLAGS) -o $@ $<

$(O)space_test.o: $(C)space_test.c $(H)space.h $(H)types.h $(H)set.h $(H)link.h $(H)space_test.h $(H)test.h
	@echo Compiling $<...
	$(CC) $(CFLAGS) -c $(HFLAGS) -o $@ $<

$(BIN)space_test: $(O)space_test.o $(O)space.o $(O)set.o $(O)link.o | $(BIN)
	$(CC) $(CFLAGS) -o $@ $^

space_test: $(BIN)space_test

$(O)set_test.o: $(C)set_test.c $(H)set.h $(H)types.h $(H)set_test.h $(H)test.h
	@echo Compiling $<...
	$(CC) $(CFLAGS) -c $(HFLAGS) -o $@ $<

$(BIN)set_test: $(O)set_test.o $(O)set.o | $(BIN)
	$(CC) $(CFLAGS) -o $@ $^

set_test: $(BIN)set_test

$(O)enemy_test.o: $(C)enemy_test.c $(H)enemy.h $(H)types.h $(H)enemy_test.h $(H)test.h
	@echo Compiling $<...
	$(CC) $(CFLAGS) -c $(HFLAGS) -o $@ $<

$(BIN)enemy_test: $(O)enemy_test.o $(O)enemy.o | $(BIN)
	$(CC) $(CFLAGS) -o $@ $^

enemy_test: $(BIN)enemy_test

$(O)link_test.o: $(C)link_test.c $(H)link.h $(H)types.h $(H)link_test.h $(H)test.h
	@echo Compiling $<...
	$(CC) $(CFLAGS) -c $(HFLAGS) -o $@ $<

$(BIN)link_test: $(O)link_test.o $(O)link.o | $(BIN)
	$(CC) $(CFLAGS) -o $@ $^

link_test: $(BIN)link_test

$(O)object_test.o: $(C)object_test.c $(H)object.h $(H)types.h $(H)object_test.h $(H)test.h
	@echo Compiling $<...
	$(CC) $(CFLAGS) -c $(HFLAGS) -o $@ $<

$(BIN)object_test: $(O)object_test.o $(O)object.o | $(BIN)
	$(CC) $(CFLAGS) -o $@ $^

object_test: $(BIN)object_test

$(O)command_test.o: $(C)command_test.c $(H)command.h $(H)types.h $(H)command_test.h $(H)test.h
	@echo Compiling $<...
	$(CC) $(CFLAGS) -c $(HFLAGS) -o $@ $<

$(BIN)command_test: $(O)command_test.o $(O)command.o | $(BIN)
	$(CC) $(CFLAGS) -o $@ $^

command_test: $(BIN)command_test

$(O)game_management_test.o: $(C)game_management_test.c $(H)game_management.h $(H)game.h $(H)command.h $(H)types.h $(H)space.h $(H)set.h $(H)link.h $(H)player.h $(H)inventory.h $(H)object.h $(H)enemy.h $(H)dialogue.h
	@echo Compiling $<...
	$(CC) $(CFLAGS) -c $(HFLAGS) -o $@ $<

$(BIN)game_management_test: $(O)game_management_test.o $(O)game_management.o $(O)game.o $(O)space.o $(O)object.o $(O)link.o $(O)player.o $(O)enemy.o $(O)inventory.o $(O)set.o $(O)command.o $(O)dialogue.o | $(BIN)
	$(CC) $(CFLAGS) -o $@ $^

game_management_test: $(BIN)game_management_test

$(O)game_test.o: $(C)game_test.c $(H)game.h $(H)command.h $(H)types.h $(H)space.h $(H)set.h $(H)link.h $(H)player.h $(H)inventory.h $(H)object.h $(H)enemy.h $(H)game_test.h $(H)test.h $(H)dialogue.h
	@echo Compiling $<...
	$(CC) $(CFLAGS) -c $(HFLAGS) -o $@ $<

$(BIN)game_test: $(O)game_test.o $(O)game_management.o $(O)game.o $(O)space.o $(O)object.o $(O)link.o $(O)player.o $(O)enemy.o $(O)inventory.o $(O)set.o $(O)command.o $(O)dialogue.o | $(BIN)
	$(CC) $(CFLAGS) -o $@ $^

game_test: $(BIN)game_test

$(O)player_test.o: $(C)player_test.c $(H)player.h $(H)types.h $(H)inventory.h $(H)set.h $(H)player_test.h $(H)test.h
	@echo Compiling $<...
	$(CC) $(CFLAGS) -c $(HFLAGS) -o $@ $<

$(BIN)player_test: $(O)player_test.o $(O)player.o $(O)inventory.o $(O)set.o | $(BIN)
	$(CC) $(CFLAGS) -o $@ $^

player_test: $(BIN)player_test

$(O)inventory_test.o: $(C)inventory_test.c $(H)inventory.h $(H)types.h $(H)set.h $(H)inventory_test.h $(H)test.h
	@echo Compiling $<...
	$(CC) $(CFLAGS) -c $(HFLAGS) -o $@ $<

$(BIN)inventory_test: $(O)inventory_test.o $(O)inventory.o $(O)set.o | $(BIN)
	$(CC) $(CFLAGS) -o $@ $^

inventory_test: $(BIN)inventory_test