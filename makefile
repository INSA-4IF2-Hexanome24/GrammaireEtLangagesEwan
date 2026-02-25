# ===== Compilateur =====
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# ===== Dossiers =====
BUILD_DIR = Compiled
TARGET = prog.exe

# ===== Sources =====
SRC = main.cpp Lexer.cpp Symbole.cpp Automate.cpp

# ===== Objets dans Compiled/ =====
OBJ = $(SRC:%.cpp=$(BUILD_DIR)/%.o)

# ===== Règle principale =====
all: $(TARGET)

# ===== Edition de liens (exe dans dossier principal) =====
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# ===== Compilation vers Compiled/ =====
$(BUILD_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ===== Nettoyage =====
clean:
	del /Q $(BUILD_DIR)\*.o 2>nul || true
	del /Q *.exe 2>nul || true

rebuild: clean all
