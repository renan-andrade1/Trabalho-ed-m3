# Variáveis para organizar os caminhos
CC = g++
CFLAGS = -Wall -std=c++11 -Iheader

# Fontes e Objetos
SRCS = main/main.cpp impls/gerenciador.cpp impls/ordenacao.cpp
OBJS = $(SRCS:.cpp=.o)

# Nome do executável final
TARGET = programa

# Regra principal (compila tudo)
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Como compilar os arquivos .cpp em .o
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para limpar os arquivos gerados
clean:
	rm -f $(OBJS) $(TARGET)