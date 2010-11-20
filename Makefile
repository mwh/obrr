PREFIX = $(HOME)/.local
INSTALL_DIR = $(PREFIX)/bin

obrr: obrr.c
	$(CC) -lX11 -o obrr obrr.c

all: obrr

install: obrr
	cp obrr $(INSTALL_DIR)/obrr
