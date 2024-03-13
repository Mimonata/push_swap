# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spitul <spitul@student.42berlin.de >       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 18:45:34 by spitul            #+#    #+#              #
#    Updated: 2024/03/13 17:44:16 by spitul           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

CC := cc
CFLAGS := -Wall -Wextra -Werror 

SRCDIR := src
OBJDIR := $(SRCDIR)

SOURCES := $(wildcard $(SRCDIR)/*.c) $(wildcard $(SRCDIR)/ops/*.c)
OBJECTS := $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SOURCES))

TARGET := $(SRCDIR)/$(NAME)

all: directories $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ 

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

directories:
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)/*.o $(TARGET)

.PHONY: all clean
